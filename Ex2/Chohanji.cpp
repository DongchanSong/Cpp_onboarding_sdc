#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <deque>

enum MoveOptions
{
    Attack,
    Defend,
    Counterattack,
    SpecialMove
};
const char *ToString(MoveOptions);
std::deque<int> MakeMoveDeque(int);
void MovePrediction(int, int, std::deque<int>);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const char *ToString(MoveOptions moveName)
{
    switch (moveName)
    {
    case Attack:
        return "Attack";
    case Defend:
        return "Defend";
    case Counterattack:
        return "Counterattack";
    case SpecialMove:
        return "SpecialMove";
    default:
        return 0; // temp
    }
}
std::deque<int> MakeMoveDeque(int dequeSize)
{
    std::deque<int> moveDeque;
    int specialMoveCount = 0;
    for (int i = 0; i < dequeSize; i++)
    {
        if (specialMoveCount >= 1)
        {
            moveDeque.push_back(rand() % (MoveOptions::Counterattack - MoveOptions::Attack + 1) + MoveOptions::Attack);
        }
        else
        {
            moveDeque.push_back(rand() % (MoveOptions::SpecialMove - MoveOptions::Attack + 1) + MoveOptions::Attack);
            if (moveDeque.at(i) == MoveOptions::SpecialMove)
            {
                specialMoveCount++;
            }
        }
    }
    return moveDeque;
}
void MovePrediction(int dequeSize, int predictionNumber, std::deque<int> moveDeque)
{
    std::deque<int> numberDeque;
    int movePrediction[dequeSize];
    for (int i = 0; i < dequeSize; i++)
    {
        numberDeque.push_back(i);
        movePrediction[i] = 0;
    }
    for (int i = 0; i < predictionNumber; i++)
    {
        int moveIndex = rand() % (dequeSize - i);
        movePrediction[numberDeque.at(moveIndex)] = 1;
        numberDeque.erase(numberDeque.begin() + moveIndex);
    }
    std::cout << "HangWoo’s Move Prediction: " << std::endl;
    for (int i = 0; i < dequeSize; i++)
    {
        if (movePrediction[i] == 0)
        {
            std::cout << "???";
        }
        else
        {
            std::cout << ToString((MoveOptions)moveDeque.at(i));
        }
        if (i < dequeSize - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl
              << std::endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ISpecialMove
{
public:
    virtual void SPECIALMOVE(int, int, int, double, int, int, double) = 0;
    double SpecialMoveDamage;
    double myHurt;
};
class HealthShield : public ISpecialMove
{
public:
    double HealthShieldDamage(int, int, int, int, double);
    void SPECIALMOVE(int, int, int, double, int, int, double);
};
class YukBalSanGiGaeSay : public ISpecialMove
{
public:
    void SPECIALMOVE(int, int, int, double, int, int, double);
};

class Player
{
public:
    ISpecialMove *specialmove;

    void SetForce(int);
    void SetIntellect(int);
    void SetHealth(double);

    int GetForce();
    int GetIntellect();
    double GetHealth();
    double GetSpecialMoveDamage();

    void Attack(int, Player);
    void Defend(int, Player);
    void Counterattack(int, Player);
    void SpecialMove(int, Player);

    void Hap(int, int, Player);

private:
    int myForce;
    int myIntellect;
    double myHealth;
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
void HealthShield::SPECIALMOVE(int enemyMove, int myforce, int myintellect, double myhealth, int enemyforce, int enemyintellect, double enemyhealth)
{
    myHurt = 0;
    switch (enemyMove)
    {
    case MoveOptions::Defend:
        SpecialMoveDamage = HealthShieldDamage(myforce, myintellect, enemyforce, enemyintellect, 0.2);
        break;
    default:
        SpecialMoveDamage = HealthShieldDamage(myforce, myintellect, enemyforce, enemyintellect, 0.1);
        break;
    }

    std::cout << "HealthShieldDamage: " << SpecialMoveDamage << std::endl;
}
void YukBalSanGiGaeSay::SPECIALMOVE(int enemyMove, int myforce, int myintellect, double myhealth, int enemyforce, int enemyintellect, double enemyhealth)
{
    switch (enemyMove)
    {
    case MoveOptions::Attack:
        SpecialMoveDamage = myhealth;
        myHurt = (50 - (myforce - enemyforce)) * 0.5;
        break;
    case MoveOptions::Defend:
        SpecialMoveDamage = myhealth;
        myHurt = 0;
        break;
    case MoveOptions::Counterattack:
        SpecialMoveDamage = myhealth;
        myHurt = 0;
        break;
    case MoveOptions::SpecialMove:
        SpecialMoveDamage = 0;
        myHurt = 0;
        break;
    }
    std::cout << "YukBalSanGiGaeSayDamage: " << SpecialMoveDamage << std::endl;
}

void Player::SetForce(int force) { myForce = force; }
void Player::SetIntellect(int intellect) { myIntellect = intellect; }
void Player::SetHealth(double health) { myHealth = health; }

int Player::GetForce() { return myForce; }
int Player::GetIntellect() { return myIntellect; }
double Player::GetHealth() { return myHealth; }
double Player::GetSpecialMoveDamage() { return mySpecialMoveDamage; }

void Player::Attack(int enemyMove, Player enemy)
{
    switch (enemyMove)
    {
    case MoveOptions::Attack:
        myHealth -= (50 - (myForce - enemy.GetForce())) * 0.5;
        break;
    case MoveOptions::Defend:
        break;
    case MoveOptions::Counterattack:
        myHealth -= (50 - (enemy.GetForce() - myForce)) * 0.5;
        break;
    case MoveOptions::SpecialMove:
        myHealth -= enemy.GetSpecialMoveDamage();
        break;
    }
}
void Player::Defend(int enemyMove, Player enemy)
{
    switch (enemyMove)
    {
    case MoveOptions::Counterattack:
        myHealth -= 20;
        /*상대방의 다음 합은 무효가 됩니다!*/
        break;
    case MoveOptions::SpecialMove:
        myHealth -= 0.5 * enemy.GetSpecialMoveDamage();
        break;
    default:
        break;
    }
}
void Player::Counterattack(int enemyMove, Player enemy)
{
    switch (enemyMove)
    {
    case MoveOptions::Attack:
        myHealth -= 10;
        break;
    case MoveOptions::Defend:
        /*당신의 다음 합은 무효가 됩니다*/
        break;
    case MoveOptions::Counterattack:
        myHealth -= (50 - (myForce - enemy.GetForce())) * 0.5;
        break;
    case MoveOptions::SpecialMove:
        myHealth -= 0.5 * enemy.GetSpecialMoveDamage();
        break;
    }
}
void Player::SpecialMove(int enemyMove, Player enemy)
{
    specialmove->SPECIALMOVE(enemyMove, myForce, myIntellect, myHealth, enemy.GetForce(), enemy.GetIntellect(), enemy.GetHealth());
    myHealth -= specialmove->myHurt;
    mySpecialMoveDamage = specialmove->SpecialMoveDamage;
}

void Player::Hap(int myMove, int enemyMove, Player enemy)
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
    default:
        std::cout << "Invalid move number" << std::endl;
        break;
    }
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
    // srand(time(NULL));
    srand(7);

    DongChan me(rand() % (80 - 60 + 1) + 60, rand() % (100 - 70 + 1) + 70, 100);
    HangWoo enemy(100, 50, 100);

    int dequeSize = 5;
    int predictionNumber = round((me.GetIntellect() - enemy.GetIntellect()) * 0.1);

    std::deque<int> moveDeque = MakeMoveDeque(dequeSize);
    MovePrediction(dequeSize, predictionNumber, moveDeque);

    std::cout << "Choose your move in this round (select a number and press enter key)" << std::endl
              << "0:Attack / 1:Defend / 2:Counterattack / 3:SpecialMove" << std::endl
              << std::endl;

    int roundNumber = 1;
    // int enemyMove = moveDeque.at(roundNumber - 1);
    // int myMove;
    // std::cin >> myMove;
    int myMove = 0;    // temp
    int enemyMove = 3; // temp

    std::cout << "my Move: " << ToString((MoveOptions)myMove) << std::endl;
    std::cout << "enemy Move: " << ToString((MoveOptions)moveDeque.at(0)) << std::endl;
    std::cout << "my damage: " << (50 - (enemy.GetForce() - me.GetForce())) * 0.5 << std::endl;
    std::cout << "enemy damage: " << (50 - (me.GetForce() - enemy.GetForce())) * 0.5 << std::endl;
    std::cout << "my SM damage: " << me.GetSpecialMoveDamage() << std::endl;
    std::cout << "enemy SM damage: " << enemy.GetSpecialMoveDamage() << std::endl;
    std::cout << std::endl;

    me.Hap(myMove, enemyMove, enemy);
    enemy.Hap(enemyMove, myMove, me);
    std::cout << "my health in main: " << me.GetHealth() << std::endl;
    std::cout << "enemy health in main: " << enemy.GetHealth() << std::endl;
    std::cout << std::endl;

    return 0;
}
