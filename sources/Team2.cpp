#include "Team2.hpp"
#include "Team.hpp"

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader)
    {
        // no need to insert leader, it has already inserted from Team cunstrctor
    }

    void Team2::add(Character *newMember)
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
    }

    void Team2::attack(Team *enemy)
    {

        // pick a victim, the closest to the leader
        Character *victim = pickTeamMember(enemy->getLeader());

        // atack the victim, if the victim dies, pick another victim, if all enemy's members are dead, the attack finishes
        for (Character *attackTeamMember : this->squad)
        {
            if (enemy->getLeader()->isDead()) // if the leader is dead, pick a new leader
            {
                Character *newLeader = enemy->pickTeamMember(enemy->getLeader());
                enemy->setTeamLeader(newLeader);
            }
            if (enemy->stillAlive() == 0) // if all enemy's members are dead, the attack finishes
            {
                break;
            }
            else
            {
                if (victim->isAlive())
                {
                    if (attackTeamMember->isNinjaOrCowboy() == 1)
                    {
                        dynamic_cast<Cowboy *>(attackTeamMember)->shoot(victim);
                    }
                    else
                    {
                        dynamic_cast<Ninja *>(attackTeamMember)->slash(victim);
                    }
                }
                else
                {
                    victim = pickTeamMember(this->leader);
                }
            }
        }
    }

    int Team2::stillAlive()
    {
        int numberOfAllive = 0;
        for (Character *teamMember : this->squad)
        {
            if (teamMember->isAlive())
            {
                numberOfAllive++;
            }
        }
        return numberOfAllive;
    }

    Character *Team2::pickTeamMember(Character *teamMember)
    {
        double shortestDisToLeader = std::numeric_limits<double>::max();
        Character *closerToLeader;

        for (Character *teamMember : this->squad)
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

    void Team2::print()
    {
        string ss;
        for (Character *teamMember : this->squad)
        {
            ss = teamMember->print();
            cout << ss << endl;
        }
    }

}