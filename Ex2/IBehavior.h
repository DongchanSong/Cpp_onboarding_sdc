#ifndef IBEHAVIOR_H
#define IBEHAVIOR_H

#include <cmath>

class IBehavior
{
public:
    // 내 피해 계산 후 반환하는 메소드
    virtual double MyHurtCalculation(int, int, int, double, IBehavior *) = 0;
    virtual double VersusAttack(int, int) = 0;
    virtual double VersusDefend() = 0;
    virtual double VersusCounterattack(int, int) = 0;
    virtual double VersusHealthShield(int, int, int) = 0;
    virtual double VersusYukBalSanGiGaeSay(double) = 0;
    virtual double VersusDoNothing() = 0;
};

class Attack : public IBehavior
{
public:
    double MyHurtCalculation(int myForce, int enemyForce, int enemyIntellect, double enemyHealth, IBehavior *me) { return me->VersusAttack(myForce, enemyForce); }
    double VersusAttack(int myForce, int enemyForce) { return 0.5 * (50 - (myForce - enemyForce)); }
    double VersusDefend() { return 0; }
    double VersusCounterattack(int myForce, int enemyForce) { return 0.5 * (50 - (enemyForce - myForce)); }
    double VersusHealthShield(int myForce, int enemyForce, int enemyIntellect) { return 0.5 * (50 - (myForce - enemyForce)) + 0.1 * (enemyIntellect + abs(enemyForce - myForce)); }
    double VersusYukBalSanGiGaeSay(double enemyHealth) { return enemyHealth; }
    double VersusDoNothing() { return 0; }
};

class Defend : public IBehavior
{
public:
    double MyHurtCalculation(int myForce, int enemyForce, int enemyIntellect, double enemyHealth, IBehavior *me) { return me->VersusDefend(); }
    double VersusAttack(int myForce, int enemyForce) { return 0; }
    double VersusDefend() { return 0; }
    double VersusCounterattack(int myForce, int enemyForce) { return 20; }
    double VersusHealthShield(int myForce, int enemyForce, int enemyIntellect) { return 0.5 * (0.5 * (50 - (myForce - enemyForce)) + 0.2 * (enemyIntellect + abs(enemyForce - myForce))); }
    double VersusYukBalSanGiGaeSay(double enemyHealth) { return 0.5 * enemyHealth; }
    double VersusDoNothing() { return 0; }
};

class Counterattck : public IBehavior
{
public:
    double MyHurtCalculation(int myForce, int enemyForce, int enemyIntellect, double enemyHealth, IBehavior *me) { return me->VersusCounterattack(myForce, enemyForce); }
    double VersusAttack(int myForce, int enemyForce) { return 10; }
    double VersusDefend() { return 0; }
    double VersusCounterattack(int myForce, int enemyForce) { return 0.5 * (50 - (myForce - enemyForce)); }
    double VersusHealthShield(int myForce, int enemyForce, int enemyIntellect) { return 0.5 * (0.5 * (50 - (myForce - enemyForce)) + 0.1 * (enemyIntellect + abs(enemyForce - myForce))); }
    double VersusYukBalSanGiGaeSay(double enemyHealth) { return 0.5 * enemyHealth; }
    double VersusDoNothing() { return 0; }
};

class HealthShield : public IBehavior
{
public:
    double MyHurtCalculation(int myForce, int enemyForce, int enemyIntellect, double enemyHealth, IBehavior *me) { return me->VersusHealthShield(myForce, enemyForce, enemyIntellect); }
    double VersusAttack(int myForce, int enemyForce) { return 0; }
    double VersusDefend() { return 0; }
    double VersusCounterattack(int myForce, int enemyForce) { return 0; }
    double VersusHealthShield(int myForce, int enemyForce, int enemyIntellect) { return 0; }
    double VersusYukBalSanGiGaeSay(double enemyHealth) { return 0; }
    double VersusDoNothing() { return 0; }
};

class YukBalSanGiGaeSay : public IBehavior
{
public:
    double MyHurtCalculation(int myForce, int enemyForce, int enemyIntellect, double enemyHealth, IBehavior *me) { return me->VersusYukBalSanGiGaeSay(enemyHealth); }
    double VersusAttack(int myForce, int enemyForce) { return 0.5 * (50 - (myForce - enemyForce)); }
    double VersusDefend() { return 0; }
    double VersusCounterattack(int myForce, int enemyForce) { return 0; }
    double VersusHealthShield(int myForce, int enemyForce, int enemyIntellect) { return 0.5 * (50 - (myForce - enemyForce)) + 0.1 * (enemyIntellect + abs(enemyForce - myForce)); }
    double VersusYukBalSanGiGaeSay(double enemyHealth) { return 0; }
    double VersusDoNothing() { return 0; }
};

class DoNothing : public IBehavior
{
public:
    double MyHurtCalculation(int myForce, int enemyForce, int enemyIntellect, double enemyHealth, IBehavior *me) { return me->VersusDoNothing(); }
    double VersusAttack(int myForce, int enemyForce) { return 0.5 * (50 - (myForce - enemyForce)); }
    double VersusDefend() { return 0; }
    double VersusCounterattack(int myForce, int enemyForce) { return 0; }
    double VersusHealthShield(int myForce, int enemyForce, int enemyIntellect) { return 0.5 * (50 - (myForce - enemyForce)) + 0.1 * (enemyIntellect + abs(enemyForce - myForce)); }
    double VersusYukBalSanGiGaeSay(double enemyHealth) { return enemyHealth; }
    double VersusDoNothing() { return 0; }
};

#endif