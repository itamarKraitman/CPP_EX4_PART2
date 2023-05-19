#include "Team.hpp"
#include "SmartTeam.hpp"
#include <limits>
#include <cmath>

namespace ariel
{
    // pick victim- closest to all atacking members, alive, min health.
    // attack- cowboys, then ninjas- according distance and damage

    SmartTeam::SmartTeam(Character *leader) : Team(leader)
    {
        add(leader);
    }

    void SmartTeam::add(Character *newMember)
    {
        if (this->getSquad().size() == 10)
        {
            throw std::runtime_error("Team can has up to 10 members");
        }

        if (newMember->isAssignedToTeam())
        {
            throw std::runtime_error("Character is already assigned to a team");
        }

        this->addToSquad(newMember);
        newMember->assignToTeam();
    }

    void SmartTeam::attack(Team *enemy)
    {
        // attack with ninjas that can slash (causing the highest damage, then with cowboys, then with the rest of the ninjas
        if (enemy == nullptr)
        {
            throw std::invalid_argument("nullpter sent as enemy");
        }
        else if (enemy->stillAlive() == 0)
        {
            throw std::runtime_error("Enemy team is already dead");
        }
        if (this->getLeader()->isDead())
        {
            this->pickNewLeader();
        }

        // pick a victim, the closest to the leader
        Character *victim;

        // atack the victim, if the victim dies, pick another victim, if all enemy's members are dead, the attack finishes
        for (auto attackTeamMember : this->getSquad())
        {
            // pick the victim, which is the closest to all attacking team members and has the lowest health
            // why? because it's likelly to die within low number of attacks, so the enemy will lose large number of team members rapidly.
            // moreover, it's better to attack and kill the closest ones first, because it prevents them to attack back in case of counter attack.
            victim = pickVictim(enemy);
            // sort the squad acording ninjas that can slash, then cowboys and then the rest of the ninjas
            vector<Character *> sortedSquad = sortSquad(this->getSquad(), victim);

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

    Character *SmartTeam::pickVictim(Team *enemy)
    {
        double minDistance = std::numeric_limits<double>::max();
        int minHitPoints = std::numeric_limits<int>::max();
        Character *closestEnemy;

        // for each enemy teamate, calculate its distance to all teamates of the attacking team
        for (auto enemyMember : enemy->getSquad())
        {
            double currDistance = 0;

            if (enemyMember->isAlive())
            {
                for (auto teamMember : this->getSquad())
                {
                    if (teamMember->isAlive())
                    {
                        currDistance += enemyMember->distance(teamMember);
                    }
                }
            }
            currDistance = sqrt(currDistance);

            if (currDistance < minDistance && enemyMember->getHitPoints() < minHitPoints)
            {
                minDistance = currDistance;
                minHitPoints = enemyMember->getHitPoints();
                closestEnemy = enemyMember;
            }
        }

        return closestEnemy;
    }

    vector<Character *> SmartTeam::sortSquad(vector<Character *> squad, auto victim)
    {
        vector<Character *> sortedSquad;

        // add all ninjas that can slash the victim
        for (auto member : squad)
        {
            if (member->isNinjaOrCowboy() == 2 && member->isAlive() && member->distance(victim) < 1)
            {
                sortedSquad.push_back(member);
            }
        }

        // add all cowboys
        for (auto member : squad)
        {
            if (member->isNinjaOrCowboy() == 1 && member->isAlive())
            {
                sortedSquad.push_back(member);
            }
        }

        // add all other ninjas
        for (auto member : squad)
        {
            if (member->isNinjaOrCowboy() == 2 && member->isAlive() && member->distance(victim) >= 1)
            {
                sortedSquad.push_back(member);
            }
        }

        return sortedSquad;
    }

}