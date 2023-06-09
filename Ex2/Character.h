#ifndef CHARACTER_H
#define CHARACTER_H

#include "IBehavior.h"
class Character
{
public:
    IBehavior *behavior;

    void SetForce(int force) { force_ = force; }
    void SetIntellect(int intellect) { intellect_ = intellect; }
    void SetHealth(double health) { health_ = health; }

    int GetForce() { return force_; }
    int GetIntellect() { return intellect_; }
    double GetHealth() { return health_; }
    IBehavior *GetBehavior() { return behavior; }

    // SpecialMove가 Character에 dependent하여 SetBehavior 함수를 추상화함
    virtual void SetBehavior(int) = 0;
    double PerformBehavior(Character *enemy) { return (enemy->GetBehavior())->MyHurtCalculation(force_, enemy->GetForce(), enemy->GetIntellect(), enemy->GetHealth(), behavior); }

protected:
    int force_;
    int intellect_;
    int health_;
};

class DongChan : public Character
{
public:
    DongChan()
    {
        SetForce(force);
        SetIntellect(intellect);
        SetHealth(health);
    }

    static int force;
    static int intellect;
    static int health;

    void SetBehavior(int moveNumber)
    {
        switch (moveNumber)
        {
        case int(MoveOptions::Attack):
            behavior = new Attack;
            break;
        case int(MoveOptions::Defend):
            behavior = new Defend;
            break;
        case int(MoveOptions::Counterattack):
            behavior = new Counterattck;
            break;
        case int(MoveOptions::SpecialMove):
            behavior = new HealthShield;
            break;
        case int(MoveOptions::DoNothing):
            behavior = new DoNothing;
        default:
            break;
        }
    }
};

class HangWoo : public Character
{
public:
    HangWoo()
    {
        SetForce(force);
        SetIntellect(intellect);
        SetHealth(health);
    }

    static int force;
    static int intellect;
    static int health;

    void SetBehavior(int moveNumber)
    {
        switch (moveNumber)
        {
        case int(MoveOptions::Attack):
            behavior = new Attack;
            break;
        case int(MoveOptions::Defend):
            behavior = new Defend;
            break;
        case int(MoveOptions::Counterattack):
            behavior = new Counterattck;
            break;
        case int(MoveOptions::SpecialMove):
            behavior = new YukBalSanGiGaeSay;
            break;
        case int(MoveOptions::DoNothing):
            behavior = new DoNothing;
        default:
            break;
        }
    }
};

std::random_device randomDevice;
std::mt19937 randomGenerator(randomDevice());
std::uniform_int_distribution<int> dongchanForce(60, 80);
std::uniform_int_distribution<int> dongchanIntellect(70, 100);

// (무력, 지력, 체력)은 클래스의 정적 멤버변수로 선언 후 정의
int DongChan::force = dongchanForce(randomGenerator);
int DongChan::intellect = dongchanIntellect(randomGenerator);
int DongChan::health = 100;

int HangWoo::force = 100;
int HangWoo::intellect = 50;
int HangWoo::health = 100;

#endif
