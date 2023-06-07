#ifndef ISPECILMOVE_H
#define ISPECILMOVE_H

#include <cmath>
#include "MoveOptions.h"

class ISpecialMove
{
public:
    virtual void SPECIALMOVE(int, int, int, double, int, int, double, double) = 0;
    double specialMoveDamage_;
    double myhurt_;
};
class HealthShield : public ISpecialMove
{
public:
    double HealthShieldDamage(int, int, int, int, double);
    void SPECIALMOVE(int, int, int, double, int, int, double, double);
};
class YukBalSanGiGaeSay : public ISpecialMove
{
public:
    void SPECIALMOVE(int, int, int, double, int, int, double, double);
};

double HealthShield::HealthShieldDamage(int myforce, int myintellect, int enemyforce, int enemyintellect, double weightingfactor)
{
    return (50 - (enemyforce - myforce)) * 0.5 + (myintellect + abs(myintellect - enemyintellect)) * weightingfactor;
}
void HealthShield::SPECIALMOVE(int enemyMove, int myforce, int myintellect, double myhealth, int enemyforce, int enemyintellect, double enemyhealth, double enemySpecialMoveDamage)
{
    myhurt_ = 0;
    switch (enemyMove)
    {
    case int(MoveOptions::Defend):
        specialMoveDamage_ = HealthShieldDamage(myforce, myintellect, enemyforce, enemyintellect, 0.2);
        break;
    default:
        specialMoveDamage_ = HealthShieldDamage(myforce, myintellect, enemyforce, enemyintellect, 0.1);
        break;
    }
}
void YukBalSanGiGaeSay::SPECIALMOVE(int enemyMove, int myforce, int myintellect, double myhealth, int enemyforce, int enemyintellect, double enemyhealth, double enemySpecialMoveDamage)
{
    switch (enemyMove)
    {
    case int(MoveOptions::Attack):
        specialMoveDamage_ = myhealth;
        myhurt_ = (50 - (myforce - enemyforce)) * 0.5;
        break;
    case int(MoveOptions::Defend):
    case int(MoveOptions::Counterattack):
        specialMoveDamage_ = myhealth;
        myhurt_ = 0;
        break;
    case int(MoveOptions::SpecialMove):
        specialMoveDamage_ = 0;
        myhurt_ = enemySpecialMoveDamage;
        break;
    }
}

#endif // !ISPECILMOVE_H
