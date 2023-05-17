#include <iostream>
#include <limits>
#include <sstream>
#include "Team.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"

namespace ariel
{
    using namespace std;

    Team::Team(Character *leader) : leader(leader)
    {
        add(leader);
    }

    void Team::add(Character *newMember)
    {
        if (this->squad.size() == 10)
        {
            throw std::runtime_error("Team can has up to 10 members");
        }

        if (newMember->isAssignedToTeam())
        {
            throw std::runtime_error("Character is already assigned to a team");
        }
        

        if (newMember->isNinjaOrCowboy() == 1) // cowboy
        {
            this->cowboys.push_back(dynamic_cast<Cowboy *>(newMember));
        }
        else // ninja
        {
            this->ninjas.push_back(dynamic_cast<Ninja *>(newMember));
        }
        this->squad.push_back(newMember);
        newMember->assignToTeam();
    }

    void Team::attack(Team *enemy)
    {
        if (enemy->getLeader()->isDead()) // if the leader is dead, pick a new leader
        {
            Character *newLeader = enemy->pickTeamMember(enemy->getLeader());
            enemy->setTeamLeader(newLeader);
        }

        // pick a victim, the closest to the leader
        Character *victim = pickTeamMember(enemy->getLeader());
        bool enemyIsDead = false;

        // atack the victim, if the victim dies, pick another victim, if all enemy's members are dead, the attack finishes
        for (Cowboy *attackTeamMember : this->cowboys)
        {
            if (enemy->stillAlive() == 0) // if all enemy's members are dead, the attack finishes
            {
                enemyIsDead = true;
                break;
            }
            else
            {
                if (victim->isAlive())
                {
                    attackTeamMember->shoot(victim);
                }
                else
                {
                    victim = pickTeamMember(this->leader);
                }
            }
        }
        if (!enemyIsDead)
        {
            for (Ninja *attackTEamMember : this->ninjas)
            {
                if (enemy->stillAlive() == 0) // if all enemy's members are dead, the attack finishes
                {
                    break;
                }
                else
                {
                    if (victim->isAlive())
                    {
                        attackTEamMember->slash(victim);
                    }
                    else
                    {
                        victim = pickTeamMember(this->leader);
                    }
                }
            }
        }
    }

    int Team::stillAlive()
    {
        int numberOfAllive = 0;
        for (Cowboy *cowboy : this->cowboys)
        {
            if (cowboy->isAlive())
            {
                numberOfAllive++;
            }
        }
        for (Ninja *ninja : this->ninjas)
        {
            if (ninja->isAlive())
            {
                numberOfAllive++;
            }
        }
        return numberOfAllive;
    }

    void Team::print()
    {
        string ss;
        for (Cowboy *cowboy : this->cowboys)
        {
            ss = cowboy->print();
            cout << ss << endl;
        }
        for (Ninja *ninja : this->ninjas)
        {
            ss = ninja->print();
            cout << ss << endl;
        }
    }

    vector<Character *> Team::getSquad()
    {
        return this->squad;
    }

    int Team::getSize()
    {
        return this->squad.size();
    }

    Character *Team::getLeader()
    {
        return this->leader;
    }
    void Team::setTeamLeader(Character *newLeader)
    {
        this->leader = newLeader;
    }

    Character *Team::pickTeamMember(Character *teamMember)
    {
        double shortestDisToLeader = std::numeric_limits<double>::max();
        Character *closerToLeader;

        for (Cowboy *teamMember : this->cowboys)
        {
            double currentDisToLeader = leader->getLocation().distance(teamMember->getLocation());
            if (teamMember != leader && currentDisToLeader < shortestDisToLeader)
            {
                shortestDisToLeader = currentDisToLeader;
                closerToLeader = teamMember;
            }
        }

        for (Ninja *teamMember : this->ninjas)
        {
            double currentDisToLeader = leader->getLocation().distance(teamMember->getLocation());
            if (teamMember != leader && currentDisToLeader < shortestDisToLeader)
            {
                shortestDisToLeader = currentDisToLeader;
                closerToLeader = teamMember;
            }
        }

        return closerToLeader;
    }
}