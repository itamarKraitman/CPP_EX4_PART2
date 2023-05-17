#include <iostream>
#include <limits>
#include <sstream>
#include <algorithm>
#include "Team.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"

namespace ariel
{
    using namespace std;

    Team::Team(Character *leader) : leader(leader), whichTypeOfTeam(1)
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
        this->squad.push_back(newMember);
        newMember->assignToTeam();

        std::sort(this->squad.begin(), this->squad.end(), compareCharacters);
    }

    void Team::attack(Team *enemy)
    {
        if (enemy == nullptr)
        {
            throw std::invalid_argument("nullpter sent as enemy");
        }
        else if (enemy->stillAlive() == 0)
        {
            throw std::runtime_error("Enemy team is already dead");
        }

        if (this->leader->isDead()) // if the leader is dead, pick a new leader
        {
            this->pickNewLeader(this->leader);
        }
        // pick a victim, the closest to the leader
        Character *victim = pickVictim(enemy);

        // atack the victim, if the victim dies, pick another victim, if all enemy's members are dead, the attack finishes
        for (Character *attackTeamMember : this->squad)
        {
            if (attackTeamMember->isAlive())
            {
                if (victim->isAlive())
                {
                    if (attackTeamMember->isNinjaOrCowboy() == 1) // cowboy
                    {
                        dynamic_cast<Cowboy *>(attackTeamMember)->shoot(victim);
                    }
                    else // ninja
                    {
                        Ninja *memberAsNinja = dynamic_cast<Ninja *>(attackTeamMember);
                        bool isHit = memberAsNinja->slash(victim);
                        if (!isHit)
                        {
                            memberAsNinja->move(victim);
                        }
                    }
                }
                else if (enemy->stillAlive() > 0)
                {   cout << "victim is dead! pick another victim" << endl;
                    victim = pickVictim(enemy);
                }
                else
                {
                    cout << "Enemy team is dead!" << endl;
                    break;
                }
            }
        }
    }

    int Team::stillAlive()
    {
        int numberOfAllive = 0;
        for (Character *member : this->squad)
        {
            if (member->isAlive())
            {
                numberOfAllive++;
            }
        }

        return numberOfAllive;
    }

    void Team::print()
    {
        string ss;
        for (Character *member : this->squad)
        {
            ss = member->print();
            cout << ss << endl;
        }
    }

    vector<Character *> Team::getSquad()
    {
        return this->squad;
    }

    void Team::addToSquad(Character *newMember)
    {
        this->squad.push_back(newMember);
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

        for (Character *teamMember : this->squad)
        {
            double currentDisToLeader = this->leader->distance(teamMember);
            if (teamMember->isAlive() && currentDisToLeader < shortestDisToLeader)
            {
                shortestDisToLeader = currentDisToLeader;
                closerToLeader = teamMember;
            }
        }

        this->setTeamLeader(closerToLeader);
    }

    Character *Team::pickVictim(Team *enemy)
    {
        double shortestDisToLeader = std::numeric_limits<double>::max();
        Character *closerToLeader;

        for (Character *teamMember : enemy->getSquad())
        {
            double currentDisToLeader = this->leader->distance(teamMember);
            if (teamMember->isAlive() && currentDisToLeader < shortestDisToLeader)
            {
                shortestDisToLeader = currentDisToLeader;
                closerToLeader = teamMember;
            }
        }

        return closerToLeader;
    }

    void Team::setType(int type)
    {
        this->whichTypeOfTeam = type;
    }

    int Team::getType()
    {
        return this->whichTypeOfTeam;
    }

    bool Team::compareCharacters(Character *first, Character *second)
    {
        if (dynamic_cast<Cowboy *>(first) && dynamic_cast<Ninja *>(second))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}