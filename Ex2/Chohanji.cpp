#include "extraFunctions.h"

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
    void DoNothing(int, Player);

    double MyHurtCalculation(int, int, Player);

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

double HealthShield::HealthShieldDamage(int myforce, int myintellect, int enemyforce, int enemyintellect, double weightingfactor)
{
    return (50 - (enemyforce - myforce)) * 0.5 + (myintellect + abs(myintellect - enemyintellect)) * weightingfactor;
}
void HealthShield::SPECIALMOVE(int enemyMove, int myforce, int myintellect, double myhealth, int enemyforce, int enemyintellect, double enemyhealth, double enemySpecialMoveDamage)
{
    myhurt_ = 0;
    switch (enemyMove)
    {
    case MoveOptions::Defend:
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
    case MoveOptions::Attack:
        specialMoveDamage_ = myhealth;
        myhurt_ = (50 - (myforce - enemyforce)) * 0.5;
        break;
    case MoveOptions::Defend:
    case MoveOptions::Counterattack:
        specialMoveDamage_ = myhealth;
        myhurt_ = 0;
        break;
    case MoveOptions::SpecialMove:
        specialMoveDamage_ = 0;
        myhurt_ = enemySpecialMoveDamage;
        break;
    }
}

void Player::SetForce(int force) { myForce_ = force; }
void Player::SetIntellect(int intellect) { myIntellect_ = intellect; }
void Player::SetHealth(double health) { myHealth_ = health; }
void Player::SetSpecialMoveDamage(double specialmovedamage) { myspecialMoveDamage_ = specialmovedamage; }

int Player::GetForce() { return myForce_; }
int Player::GetIntellect() { return myIntellect_; }
double Player::GetHealth() { return myHealth_; }
double Player::GetSpecialMoveDamage() { return myspecialMoveDamage_; }

void Player::Attack(int enemyMove, Player enemy)
{
    switch (enemyMove)
    {
    case MoveOptions::Attack:
        myHurt_ = (50 - (myForce_ - enemy.GetForce())) * 0.5;
        break;
    case MoveOptions::Defend:
        myHurt_ = 0;
        break;
    case MoveOptions::Counterattack:
        myHurt_ = (50 - (enemy.GetForce() - myForce_)) * 0.5;
        break;
    case MoveOptions::SpecialMove:
        enemy.SpecialMove(MoveOptions::Attack, *this);
        myHurt_ = enemy.GetSpecialMoveDamage();
        break;
    }
}
void Player::Defend(int enemyMove, Player enemy)
{
    switch (enemyMove)
    {
    case MoveOptions::Counterattack:
        myHurt_ = 20;
        break;
    case MoveOptions::SpecialMove:
        enemy.SpecialMove(MoveOptions::Defend, *this);
        myHurt_ = 0.5 * enemy.GetSpecialMoveDamage();
        break;
    default:
        myHurt_ = 0;
        break;
    }
}
void Player::Counterattack(int enemyMove, Player enemy)
{
    switch (enemyMove)
    {
    case MoveOptions::Attack:
        myHurt_ = 10;
        break;
    case MoveOptions::Defend:
        myHurt_ = 0;
        break;
    case MoveOptions::Counterattack:
        myHurt_ = (50 - (myForce_ - enemy.GetForce())) * 0.5;
        break;
    case MoveOptions::SpecialMove:
        enemy.SpecialMove(MoveOptions::Counterattack, *this);
        myHurt_ = 0.5 * enemy.GetSpecialMoveDamage();
        break;
    }
}
void Player::SpecialMove(int enemyMove, Player enemy)
{
    specialmove->SPECIALMOVE(enemyMove, myForce_, myIntellect_, myHealth_, enemy.GetForce(), enemy.GetIntellect(), enemy.GetHealth(), enemy.GetSpecialMoveDamage());
    if (enemyMove == MoveOptions::SpecialMove)
    {
        enemy.SpecialMove(MoveOptions::Counterattack, *this);
    }
    myHurt_ = specialmove->myhurt_;
    myspecialMoveDamage_ = specialmove->specialMoveDamage_;
}

void Player::DoNothing(int enemyMove, Player enemy)
{
    switch (enemyMove)
    {
    case MoveOptions::Attack:
        myHurt_ = (50 - (myForce_ - enemy.GetForce())) * 0.5;
        break;
    case MoveOptions::Defend:
    case MoveOptions::Counterattack:
        myHurt_ = 0;
        break;
    case MoveOptions::SpecialMove:
        enemy.SpecialMove(MoveOptions::Attack, *this);
        myHurt_ = enemy.GetSpecialMoveDamage();
        break;
    }
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
    case MoveOptions::DoNothing:
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

int main()
{
    srand(time(NULL));

    DongChan me(rand() % (80 - 60 + 1) + 60, rand() % (100 - 70 + 1) + 70, 100);
    HangWoo enemy(100, 50, 100);

    int dequeSize = 5;
    int predictionNumber = round((me.GetIntellect() - enemy.GetIntellect()) * 0.1);

    std::deque<int> enemyMoveDeque = MakeEnemyMoveDeque(dequeSize);
    EnemyMovePrediction(dequeSize, predictionNumber, enemyMoveDeque);

    std::deque<int> myMoveDeque = MakeMyMoveDeque(dequeSize);

    bool myDoNothingFlag = false;
    bool enemyDoNothingFlag = false;
    int roundNumber = 1;
    do
    {
        int myMove = myMoveDeque.at(roundNumber - 1);
        int enemyMove = enemyMoveDeque.at(roundNumber - 1);

        DoNothingCheck(myDoNothingFlag, myMove, enemyMove);
        DoNothingCheck(enemyDoNothingFlag, enemyMove, myMove);

        double myhurt = me.MyHurtCalculation(myMove, enemyMove, enemy);
        double enemyhurt = enemy.MyHurtCalculation(enemyMove, myMove, me);

        enemy.SetHealth(enemy.GetHealth() - enemyhurt);
        me.SetHealth(me.GetHealth() - myhurt);

        std::cout << "\nRound " << roundNumber << ") You: " << ToString(myMove) << ", Enemy: " << ToString(enemyMoveDeque.at(roundNumber - 1)) << "\n";
        PrintHealth(me.GetHealth(), enemy.GetHealth());

        roundNumber++;
    } while (roundNumber <= dequeSize && me.GetHealth() > 0 && enemy.GetHealth());
    PrintResult(me.GetHealth(), enemy.GetHealth());

    return 0;
}
