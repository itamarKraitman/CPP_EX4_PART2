#include "Team2.hpp"
#include "Team.hpp"

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader)
    {
        // no need to insert leader, it has already inserted from Team cunstrctor
        this->setType(2);
    }

    void Team2::add(Character *newMember)
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

    void Team2::attack(Team *enemy)
    {

        if (enemy == nullptr)
        {
            throw std::invalid_argument("nullpter sent as enemy");
        }

        else if (enemy->stillAlive() == 0)
        {
            throw std::runtime_error("Enemy team is already dead");
        }

        if (this->getLeader()->isDead()) // if the leader is dead, pick a new leader
        {
            this->pickNewLeader();
        }

        // pick a victim, the closest to the leader
        Character *victim;

        // atack the victim, if the victim dies, pick another victim, if all enemy's members are dead, the attack finishes
        for (Character *attackTeamMember : this->getSquad())
        {
            victim = pickVictim(enemy);
            
            if (attackTeamMember->isAlive())
            {
                if (victim->isAlive())
                {
                    if (attackTeamMember->isNinjaOrCowboy() == 1)
                    {
                        dynamic_cast<Cowboy *>(attackTeamMember)->shoot(victim);
                    }
                    else
                    {
                        Ninja *temp = dynamic_cast<Ninja *>(attackTeamMember);
                        bool isHit = temp->slash(victim);
                        if (!isHit)
                        {
                            temp->move(victim);
                        }
                    }
                }
                else if (enemy->stillAlive() > 0)
                {
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


}