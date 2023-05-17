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
        if (enemy == nullptr)
        {
            throw std::invalid_argument("nullpter sent as enemy");
        }

        if (this->leader->isDead()) // if the leader is dead, pick a new leader
        {
            this->pickNewLeader(this->leader);
        }

        // pick a victim, the closest to the leader
        Character *victim = pickVictim(this->leader, enemy);
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
                    victim = pickVictim(this->leader, enemy);
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
                        victim = pickVictim(this->leader, enemy);
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

    vector<Cowboy *> Team::getCowboys()
    {
        return this->cowboys;
    }
    
    vector<Ninja *> Team::getNinjas()
    {
        return this->ninjas;
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

    void Team::pickNewLeader(Character *teamMember)
    {
        double shortestDisToLeader = std::numeric_limits<double>::max();
        Character *closerToLeader;

        for (Cowboy *teamMember : this->cowboys)
        {
            double currentDisToLeader = this->leader->getLocation().distance(teamMember->getLocation());
            if (teamMember != this->leader && currentDisToLeader < shortestDisToLeader)
            {
                shortestDisToLeader = currentDisToLeader;
                closerToLeader = teamMember;
            }
        }

        for (Ninja *teamMember : this->ninjas)
        {
            double currentDisToLeader = this->leader->getLocation().distance(teamMember->getLocation());
            if (teamMember->isAlive() && teamMember != this->leader && currentDisToLeader < shortestDisToLeader)
            {
                shortestDisToLeader = currentDisToLeader;
                closerToLeader = teamMember;
            }
        }

        this->setTeamLeader(closerToLeader);
    }

    Character *Team::pickVictim(Character *teamMember, Team *enemy)
    {
        double shortestDisToLeader = std::numeric_limits<double>::max();
        Character *closerToLeader;

        for (Cowboy *teamMember : enemy->getCowboys())
        {
            double currentDisToLeader = this->leader->getLocation().distance(teamMember->getLocation());
            if (teamMember != this->leader && currentDisToLeader < shortestDisToLeader)
            {
                shortestDisToLeader = currentDisToLeader;
                closerToLeader = teamMember;
            }
        }

        for (Ninja *teamMember : enemy->getNinjas())
        {
            double currentDisToLeader = this->leader->getLocation().distance(teamMember->getLocation());
            if (teamMember->isAlive() && teamMember != this->leader && currentDisToLeader < shortestDisToLeader)
            {
                shortestDisToLeader = currentDisToLeader;
                closerToLeader = teamMember;
            }
        }

        return closerToLeader;
    }

    
}