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

    Team::~Team()
    {
        for (Character *member : this->squad)
        {
            delete member;
            member = nullptr;
        }

        this->squad.clear();
        this->squad.shrink_to_fit();
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
            this->pickNewLeader();
        }

        Character *victim;
        // atack the victim, if the victim dies, pick another victim, if all enemy's members are dead, the attack finishes
        for (auto attackTeamMember : this->squad)
        {
            // pick a victim, the closest to the leader
            victim = pickVictim(enemy);

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
                {
                    cout << "victim is dead! pick another victim" << endl;
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

    void Team::pickNewLeader()
    {
        double shortestDisToLeader = std::numeric_limits<double>::max();
        Character *closerToLeader;

        for (auto teamMember : this->squad)
        {
            double currentDisToLeader = teamMember->distance(this->leader);
            if (teamMember->isAlive() && currentDisToLeader < shortestDisToLeader)
            {
                shortestDisToLeader = currentDisToLeader;
                closerToLeader = teamMember;
            }
        }
        if (closerToLeader != nullptr)
        {
            this->setTeamLeader(closerToLeader);
        }
        else
        {
            throw std::runtime_error("There is no any team member alive");
        }
    }

    Character *Team::pickVictim(Team *enemy)
    {
        double shortestDisToLeader = std::numeric_limits<double>::max();
        Character *closerToLeader;

        for (auto teamMember : enemy->getSquad())
        {
            double currentDisToLeader = teamMember->distance(this->leader);
            if (teamMember->isAlive() && currentDisToLeader < shortestDisToLeader)
            {
                shortestDisToLeader = currentDisToLeader;
                closerToLeader = teamMember;
            }
        }

        if (closerToLeader != nullptr)
        {
            return closerToLeader;
        }
        else
        {
            throw std::runtime_error("There is no any team member alive");
        }
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
        return (dynamic_cast<Cowboy *>(first) && dynamic_cast<Ninja *>(second));
    }

}