#include "GlobalFunctions.h"
#include "Player.h"

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
    } while (roundNumber <= dequeSize && me.GetHealth() > 0 && enemy.GetHealth() > 0);
    PrintResult(me.GetHealth(), enemy.GetHealth());

    return 0;
}
