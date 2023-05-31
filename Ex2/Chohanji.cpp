// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include <cmath>
// #include <deque>
#include "extraFunctions.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ISpecialMove
{
public:
    virtual void SPECIALMOVE(int, int, int, double, int, int, double, double) = 0;
    double SpecialMoveDamage;
    double myhurt;
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

    void Attack(int, Player);
    void Defend(int, Player);
    void Counterattack(int, Player);
    void SpecialMove(int, Player);

    double MyHurtCalculation(int, int, Player);

protected:
    int myForce;
    int myIntellect;
    double myHealth;
    double myHurt;
    double mySpecialMoveDamage;
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double HealthShield::HealthShieldDamage(int myforce, int myintellect, int enemyforce, int enemyintellect, double weightingfactor)
{
    return (50 - (enemyforce - myforce)) * 0.5 + (myintellect + abs(myintellect - enemyintellect)) * weightingfactor;
}
void HealthShield::SPECIALMOVE(int enemyMove, int myforce, int myintellect, double myhealth, int enemyforce, int enemyintellect, double enemyhealth, double enemySpecialMoveDamage)
{
    myhurt = 0;
    switch (enemyMove)
    {
    case MoveOptions::Defend:
        SpecialMoveDamage = HealthShieldDamage(myforce, myintellect, enemyforce, enemyintellect, 0.2);
        break;
    default:
        SpecialMoveDamage = HealthShieldDamage(myforce, myintellect, enemyforce, enemyintellect, 0.1);
        break;
    }
}
void YukBalSanGiGaeSay::SPECIALMOVE(int enemyMove, int myforce, int myintellect, double myhealth, int enemyforce, int enemyintellect, double enemyhealth, double enemySpecialMoveDamage)
{
    switch (enemyMove)
    {
    case MoveOptions::Attack:
        SpecialMoveDamage = myhealth;
        myhurt = (50 - (myforce - enemyforce)) * 0.5;
        break;
    case MoveOptions::Defend:
    case MoveOptions::Counterattack:
        SpecialMoveDamage = myhealth;
        myhurt = 0;
        break;
    case MoveOptions::SpecialMove:
        SpecialMoveDamage = 0;
        myhurt = enemySpecialMoveDamage;
        break;
    }
}

void Player::SetForce(int force) { myForce = force; }
void Player::SetIntellect(int intellect) { myIntellect = intellect; }
void Player::SetHealth(double health) { myHealth = health; }
void Player::SetSpecialMoveDamage(double specialmovedamage) { mySpecialMoveDamage = specialmovedamage; }

int Player::GetForce() { return myForce; }
int Player::GetIntellect() { return myIntellect; }
double Player::GetHealth() { return myHealth; }
double Player::GetSpecialMoveDamage() { return mySpecialMoveDamage; }

void Player::Attack(int enemyMove, Player enemy)
{
    switch (enemyMove)
    {
    case MoveOptions::Attack:
        myHurt = (50 - (myForce - enemy.GetForce())) * 0.5;
        break;
    case MoveOptions::Defend:
        myHurt = 0;
        break;
    case MoveOptions::Counterattack:
        myHurt = (50 - (enemy.GetForce() - myForce)) * 0.5;
        break;
    case MoveOptions::SpecialMove:
        enemy.SpecialMove(MoveOptions::Attack, *this);
        myHurt = enemy.GetSpecialMoveDamage();
        break;
    }
}
void Player::Defend(int enemyMove, Player enemy)
{
    switch (enemyMove)
    {
    case MoveOptions::Counterattack:
        myHurt = 20;
        /*상대방의 다음 합은 무효가 됩니다!*/
        break;
    case MoveOptions::SpecialMove:
        enemy.SpecialMove(MoveOptions::Defend, *this);
        myHurt = 0.5 * enemy.GetSpecialMoveDamage();
        break;
    default:
        myHurt = 0;
        break;
    }
}
void Player::Counterattack(int enemyMove, Player enemy)
{
    switch (enemyMove)
    {
    case MoveOptions::Attack:
        myHurt = 10;
        break;
    case MoveOptions::Defend:
        myHurt = 0;
        /*당신의 다음 합은 무효가 됩니다*/
        break;
    case MoveOptions::Counterattack:
        myHurt = (50 - (myForce - enemy.GetForce())) * 0.5;
        break;
    case MoveOptions::SpecialMove:
        enemy.SpecialMove(MoveOptions::Counterattack, *this);
        myHurt = 0.5 * enemy.GetSpecialMoveDamage();
        break;
    }
}
void Player::SpecialMove(int enemyMove, Player enemy)
{
    specialmove->SPECIALMOVE(enemyMove, myForce, myIntellect, myHealth, enemy.GetForce(), enemy.GetIntellect(), enemy.GetHealth(), enemy.GetSpecialMoveDamage());
    if (enemyMove == MoveOptions::SpecialMove)
    {
        enemy.SpecialMove(MoveOptions::Counterattack, *this);
    }
    myHurt = specialmove->myhurt;
    mySpecialMoveDamage = specialmove->SpecialMoveDamage;
}
double Player::MyHurtCalculation(int myMove, int enemyMove, Player enemy)
{
    switch (myMove)
    {
    case MoveOptions::Attack:
        this->Attack(enemyMove, enemy);
        break;
    case MoveOptions::Defend:
        this->Defend(enemyMove, enemy);
        break;
    case MoveOptions::Counterattack:
        this->Counterattack(enemyMove, enemy);
        break;
    case MoveOptions::SpecialMove:
        this->SpecialMove(enemyMove, enemy);
        break;
    }
    return myHurt;
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

int main()
{
    srand(time(NULL));
    // srand(7);

    DongChan me(rand() % (80 - 60 + 1) + 60, rand() % (100 - 70 + 1) + 70, 100);
    HangWoo enemy(100, 50, 100);

    int dequeSize = 5;
    int predictionNumber = round((me.GetIntellect() - enemy.GetIntellect()) * 0.1);

    std::deque<int> moveDeque = MakeMoveDeque(dequeSize);
    MovePrediction(dequeSize, predictionNumber, moveDeque);

    int roundNumber = 1;
    do
    {
        std::cout << "[Round " << roundNumber << "] Choose your move in this round (select a number and press enter key)" << std::endl
                  << "0:Attack / 1:Defend / 2:Counterattack / 3:SpecialMove" << std::endl
                  << std::endl;
        int enemyMove = moveDeque.at(roundNumber - 1);
        int myMove;
        std::cin >> myMove;

        double myhurt = me.MyHurtCalculation(myMove, enemyMove, enemy);
        double enemyhurt = enemy.MyHurtCalculation(enemyMove, myMove, me);

        enemy.SetHealth(enemy.GetHealth() - enemyhurt);
        me.SetHealth(me.GetHealth() - myhurt);

        std::cout << std::endl
                  << "Round " << roundNumber << ") "
                  << "You: " << ToString(myMove)
                  << ", Enemy: " << ToString(moveDeque.at(roundNumber - 1)) << std::endl;

        printHealth(me.GetHealth(), enemy.GetHealth());
        roundNumber++;
    } while (roundNumber <= dequeSize && me.GetHealth() > 0 && enemy.GetHealth());

    if ((me.GetHealth() <= 0 && enemy.GetHealth() <= 0) || me.GetHealth() == enemy.GetHealth())
    {
        std::cout << "Draw!" << std::endl;
    }
    else if (me.GetHealth() > enemy.GetHealth())
    {
        std::cout << "You win!" << std::endl;
    }
    else if (me.GetHealth() < enemy.GetHealth())
    {
        std::cout << "Enemy win!" << std::endl;
    }
    return 0;
}
