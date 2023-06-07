#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "MoveOptions.h"

const char *ToString(int);
std::deque<int> MakeEnemyMoveDeque(int);
void EnemyMovePrediction(int, int, std::deque<int> &);
void PrintHealth(double, double);
void PrintNonNegativeNumber(double);
void PrintResult(double, double);
std::deque<int> MakeMyMoveDeque(int);
void DoNothingCheck(bool &, int &, int);

const char *ToString(int moveNumber)
{
    switch (moveNumber)
    {
    case int(MoveOptions::Attack):
        return "Attack";
    case int(MoveOptions::Defend):
        return "Defend";
    case int(MoveOptions::Counterattack):
        return "Counterattack";
    case int(MoveOptions::SpecialMove):
        return "SpecialMove";
    case int(MoveOptions::DoNothing):
        return "DoNothing";
    default:
        return 0; // temp
    }
}
std::deque<int> MakeEnemyMoveDeque(int dequeSize)
{
    std::deque<int> moveDeque;
    bool specialMoveLimited = false;
    for (int i = 0; i < dequeSize; i++)
    {
        if (specialMoveLimited == true)
        {
            moveDeque.push_back(rand() % (int(MoveOptions::Counterattack) - int(MoveOptions::Attack) + 1) + int(MoveOptions::Attack));
        }
        else
        {
            moveDeque.push_back(rand() % (int(MoveOptions::SpecialMove) - int(MoveOptions::Attack) + 1) + int(MoveOptions::Attack));
            if (moveDeque.at(i) == int(MoveOptions::SpecialMove))
            {
                specialMoveLimited = true;
            }
        }
    }
    return moveDeque;
}
void EnemyMovePrediction(int dequeSize, int predictionNumber, std::deque<int> &moveDeque)
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
        std::cout << "Round #" << i + 1 << ": ";
        if (movePrediction[i] == 0)
        {
            std::cout << "???";
        }
        else
        {
            std::cout << ToString(moveDeque.at(i));
        }
        if (i < dequeSize - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl
              << std::endl;
}
void PrintNonNegativeNumber(double health)
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
void PrintHealth(double myhealth, double enemyhealth)
{
    std::cout << "Health -> You: ";
    PrintNonNegativeNumber(myhealth);
    std::cout << ", Enemy: ";
    PrintNonNegativeNumber(enemyhealth);

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
    std::cout << "\n";
}

void PrintResult(double myHealth, double enemyHealth)
{
    if ((myHealth <= 0 && enemyHealth <= 0) || myHealth == enemyHealth)
    {
        std::cout << "\n***** Result: Draw! *****\n\n";
    }
    else if (myHealth > enemyHealth)
    {
        std::cout << "\n***** Result: You win! *****\n\n";
    }
    else if (myHealth < enemyHealth)
    {
        std::cout << "\n***** Result: Enemy win! *****\n\n";
    }
}

std::deque<int> MakeMyMoveDeque(int dequeSize)
{
    std::cout << "Choose your moves (select a number and press enter key)\n"
              << "1:Attack / 2:Defend / 3:Counterattack / 4:SpecialMove\n\n";
    std::deque<int> myMoveDeque;
    int myMove;
    bool specialMoveLimit = false;
    for (int i = 0; i < dequeSize; i++)
    {
        while (true)
        {
            std::cout << "Round #" << i + 1 << ": ";
            std::cin >> myMove;
            try
            {
                switch (myMove)
                {
                case int(MoveOptions::Attack):
                case int(MoveOptions::Defend):
                case int(MoveOptions::Counterattack):
                    myMoveDeque.push_back(myMove);
                    break;
                case int(MoveOptions::SpecialMove):
                    if (specialMoveLimit == false)
                    {
                        myMoveDeque.push_back(myMove);
                        specialMoveLimit = true;
                        break;
                    }
                    else
                    {
                        const char *errorMessage = "You can use SpecialMove only once. Please put the number again.\n";
                        throw errorMessage;
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
                std::cout << std::to_string(myMove) + " is an invalid move number. Please put the number again.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
            break;
        }
    }
    return myMoveDeque;
}

void DoNothingCheck(bool &myDoNothingFlag, int &myMove, int enemyMove)
{
    if (myDoNothingFlag == true)
    {
        myMove = int(MoveOptions::DoNothing);
        myDoNothingFlag = false;
    }
    if (myMove == int(MoveOptions::Counterattack) && enemyMove == int(MoveOptions::Defend))
    {
        myDoNothingFlag = true;
    }
}

#endif
