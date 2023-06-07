#ifndef PLAYER_H
#define PLAYER_H

#include "MoveOptions.h"
#include "ISpecialMove.h"

class Player
{
public:
    ISpecialMove *specialmove;

    void SetForce(int);
    void SetIntellect(int);
    void SetHealth(double);
    void SetSpecialMoveDamage(double);

    int GetForce();
    int GetIntellect();
    double GetHealth();
    double GetSpecialMoveDamage();

    void Attack(int, Player &);
    void Defend(int, Player &);
    void Counterattack(int, Player &);
    void SpecialMove(int, Player &);
    void DoNothing(int, Player &);

    double MyHurtCalculation(int, int, Player &);

protected:
    int myForce_;
    int myIntellect_;
    double myHealth_;
    double myHurt_;
    double myspecialMoveDamage_;
};
class DongChan : public Player
{
public:
    DongChan(int, int, double);
};
class HangWoo : public Player
{
public:
    HangWoo(int, int, double);
};

void Player::SetForce(int force) { myForce_ = force; }
void Player::SetIntellect(int intellect) { myIntellect_ = intellect; }
void Player::SetHealth(double health) { myHealth_ = health; }
void Player::SetSpecialMoveDamage(double specialmovedamage) { myspecialMoveDamage_ = specialmovedamage; }

int Player::GetForce() { return myForce_; }
int Player::GetIntellect() { return myIntellect_; }
double Player::GetHealth() { return myHealth_; }
double Player::GetSpecialMoveDamage() { return myspecialMoveDamage_; }

void Player::Attack(int enemyMove, Player &enemy)
{
    switch (enemyMove)
    {
    case int(MoveOptions::Attack):
        myHurt_ = (50 - (myForce_ - enemy.GetForce())) * 0.5;
        break;
    case int(MoveOptions::Defend):
        myHurt_ = 0;
        break;
    case int(MoveOptions::Counterattack):
        myHurt_ = (50 - (enemy.GetForce() - myForce_)) * 0.5;
        break;
    case int(MoveOptions::SpecialMove):
        enemy.SpecialMove(int(MoveOptions::Attack), *this);
        myHurt_ = enemy.GetSpecialMoveDamage();
        break;
    }
}
void Player::Defend(int enemyMove, Player &enemy)
{
    switch (enemyMove)
    {
    case int(MoveOptions::Counterattack):
        myHurt_ = 20;
        break;
    case int(MoveOptions::SpecialMove):
        enemy.SpecialMove(int(MoveOptions::Defend), *this);
        myHurt_ = 0.5 * enemy.GetSpecialMoveDamage();
        break;
    default:
        myHurt_ = 0;
        break;
    }
}
void Player::Counterattack(int enemyMove, Player &enemy)
{
    switch (enemyMove)
    {
    case int(MoveOptions::Attack):
        myHurt_ = 10;
        break;
    case int(MoveOptions::Defend):
        myHurt_ = 0;
        break;
    case int(MoveOptions::Counterattack):
        myHurt_ = (50 - (myForce_ - enemy.GetForce())) * 0.5;
        break;
    case int(MoveOptions::SpecialMove):
        enemy.SpecialMove(int(MoveOptions::Counterattack), *this);
        myHurt_ = 0.5 * enemy.GetSpecialMoveDamage();
        break;
    }
}
void Player::SpecialMove(int enemyMove, Player &enemy)
{
    specialmove->SPECIALMOVE(enemyMove, myForce_, myIntellect_, myHealth_, enemy.GetForce(), enemy.GetIntellect(), enemy.GetHealth(), enemy.GetSpecialMoveDamage());
    if (enemyMove == int(MoveOptions::SpecialMove))
    {
        enemy.SpecialMove(int(MoveOptions::Counterattack), *this);
    }
    myHurt_ = specialmove->myhurt_;
    myspecialMoveDamage_ = specialmove->specialMoveDamage_;
}

void Player::DoNothing(int enemyMove, Player &enemy)
{
    switch (enemyMove)
    {
    case int(MoveOptions::Attack):
        myHurt_ = (50 - (myForce_ - enemy.GetForce())) * 0.5;
        break;
    case int(MoveOptions::Defend):
    case int(MoveOptions::Counterattack):
        myHurt_ = 0;
        break;
    case int(MoveOptions::SpecialMove):
        enemy.SpecialMove(int(MoveOptions::Attack), *this);
        myHurt_ = enemy.GetSpecialMoveDamage();
        break;
    }
}

double Player::MyHurtCalculation(int myMove, int enemyMove, Player &enemy)
{
    switch (myMove)
    {
    case int(MoveOptions::Attack):
        this->Attack(enemyMove, enemy);
        break;
    case int(MoveOptions::Defend):
        this->Defend(enemyMove, enemy);
        break;
    case int(MoveOptions::Counterattack):
        this->Counterattack(enemyMove, enemy);
        break;
    case int(MoveOptions::SpecialMove):
        this->SpecialMove(enemyMove, enemy);
        break;
    case int(MoveOptions::DoNothing):
        this->DoNothing(enemyMove, enemy);
        break;
    }
    return myHurt_;
}

DongChan::DongChan(int force, int intellect, double health)
{
    SetForce(force);
    SetIntellect(intellect);
    SetHealth(health);
    specialmove = new HealthShield();
}
HangWoo::HangWoo(int force, int intellect, double health)
{
    SetForce(force);
    SetIntellect(intellect);
    SetHealth(health);
    specialmove = new YukBalSanGiGaeSay();
}

#endif //
