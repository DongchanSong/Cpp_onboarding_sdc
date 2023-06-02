#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <deque>

enum MoveOptions
{
    Attack = 1,
    Defend,
    Counterattack,
    SpecialMove,
    DoNothing
};
const char *ToString(int);
std::deque<int> MakeMoveDeque(int);
void MovePrediction(int, int, std::deque<int>);
void printHealth(double, double);
void printNonNegativeNumber(double);
void printResult(double, double);
int CheckMoveNumber(bool &);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const char *ToString(int moveNumber)
{
    switch (moveNumber)
    {
    case MoveOptions::Attack:
        return "Attack";
    case MoveOptions::Defend:
        return "Defend";
    case MoveOptions::Counterattack:
        return "Counterattack";
    case MoveOptions::SpecialMove:
        return "SpecialMove";
    case MoveOptions::DoNothing:
        return "SpecialMove";
    default:
        return 0; // temp
    }
}
std::deque<int> MakeMoveDeque(int dequeSize)
{
    std::deque<int> moveDeque;
    bool specialMoveLimited = false;
    for (int i = 0; i < dequeSize; i++)
    {
        if (specialMoveLimited == true)
        {
            moveDeque.push_back(rand() % (MoveOptions::Counterattack - MoveOptions::Attack + 1) + MoveOptions::Attack);
        }
        else
        {
            moveDeque.push_back(rand() % (MoveOptions::SpecialMove - MoveOptions::Attack + 1) + MoveOptions::Attack);
            if (moveDeque.at(i) == MoveOptions::SpecialMove)
            {
                specialMoveLimited = true;
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
        std::cout << "Round " << i + 1 << ": ";
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
void printNonNegativeNumber(double health)
{
    if (health <= 0)
    {
        std::cout << 0;
    }
    else
    {
        std::cout << health;
    }
}
void printHealth(double myhealth, double enemyhealth)
{
    std::cout << "Health -> You: ";
    printNonNegativeNumber(myhealth);
    std::cout << ", Enemy: ";
    printNonNegativeNumber(enemyhealth);

    if (myhealth <= 0 && enemyhealth <= 0)
    {
        std::cout << ", Both died...";
    }
    else if (myhealth <= 0)
    {
        std::cout << ", You died...";
    }
    else if (enemyhealth <= 0)
    {
        std::cout << ", Enemy died...";
    }
    std::cout << "\n\n";
}

void printResult(double myHealth, double enemyHealth)
{

    if ((myHealth <= 0 && enemyHealth <= 0) || myHealth == enemyHealth)
    {
        std::cout << "Draw!" << std::endl;
    }
    else if (myHealth > enemyHealth)
    {
        std::cout << "You win!" << std::endl;
    }
    else if (myHealth < enemyHealth)
    {
        std::cout << "Enemy win!" << std::endl;
    }
}

int CheckMoveNumber(bool &specialMoveLimit)
{
    int myMove;
    while (true)
    {
        std::cin >> myMove;

        try
        {
            switch (myMove)
            {
            case MoveOptions::Attack:
            case MoveOptions::Defend:
            case MoveOptions::Counterattack:
                break;
            case MoveOptions::SpecialMove:
                if (specialMoveLimit == false)
                {
                    specialMoveLimit = true;
                    break;
                }
                else
                {
                    throw "You can use SpecialMove only once.\nPlease put the number again: ";
                }
            default:
                throw myMove;
            }
        }
        catch (const char *errorMessage)
        {
            std::cout << errorMessage;
            continue;
        }
        catch (int myMove)
        {
            std::cout << std::to_string(myMove) + " is an invalid move number.\nPlease put the number again: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
    return myMove;
}
