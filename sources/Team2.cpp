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
            this->pickNewLeader(this->getLeader());
        }

        // pick a victim, the closest to the leader
        Character *victim = pickVictim(enemy);

        // atack the victim, if the victim dies, pick another victim, if all enemy's members are dead, the attack finishes
        for (Character *attackTeamMember : this->getSquad())
        {
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

    int Team2::stillAlive()
    {
        int numberOfAllive = 0;
        for (Character *teamMember : this->getSquad())
        {
            if (teamMember->isAlive())
            {
                numberOfAllive++;
            }
        }
        return numberOfAllive;
    }

    void Team2::pickNewLeader(Character *teamMember)
    {
        double shortestDisToLeader = std::numeric_limits<double>::max();
        Character *closerToLeader;

        for (Character *teamMember : this->getSquad())
        {
            double currentDisToLeader = this->getLeader()->getLocation().distance(teamMember->getLocation());
            if (teamMember->isAlive() && currentDisToLeader < shortestDisToLeader)
            {
                shortestDisToLeader = currentDisToLeader;
                closerToLeader = teamMember;
            }
        }
        this->setTeamLeader(closerToLeader);
    }

    Character *Team2::pickVictim(Team *enemy)
    {
        double shortestDisToLeader = std::numeric_limits<double>::max();
        Character *closerToLeader;

        for (Character *teamMember : enemy->getSquad())
        {
            double currentDisToLeader = this->getLeader()->getLocation().distance(teamMember->getLocation());
            if (teamMember->isAlive() && currentDisToLeader < shortestDisToLeader)
            {
                shortestDisToLeader = currentDisToLeader;
                closerToLeader = teamMember;
            }
        }
        return closerToLeader;
    }

    void Team2::print()
    {
        string ss;
        for (Character *teamMember : this->getSquad())
        {
            ss = teamMember->print();
            cout << ss << endl;
        }
    }
}