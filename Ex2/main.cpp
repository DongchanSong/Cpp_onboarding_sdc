#include "GlobalFunctions.h"
#include "Character.h"

int main()
{
    // 객체 생성
    Character *me = new DongChan;
    Character *enemy = new HangWoo;

    // Move 덱 생성
    int dequeSize = 5;
    std::deque<int> enemyMoveDeque = MakeEnemyMoveDeque(dequeSize);
    EnemyMovePrediction(me->GetIntellect(), enemy->GetIntellect(), dequeSize, enemyMoveDeque);
    std::deque<int> myMoveDeque = MakeMyMoveDeque(dequeSize);

    // 일기토에 필요한 Flag 및 #라운드
    bool myDoNothingFlag = false;
    bool enemyDoNothingFlag = false;
    int roundNumber = 1;

    // 일기토
    do
    {
        int myMove = myMoveDeque.at(roundNumber - 1);
        int enemyMove = enemyMoveDeque.at(roundNumber - 1);

        DoNothingCheck(myDoNothingFlag, myMove, enemyMove);
        DoNothingCheck(enemyDoNothingFlag, enemyMove, myMove);

        me->SetBehavior(myMove);
        enemy->SetBehavior(enemyMove);

        double myhurt = me->PerformBehavior(enemy);
        double enemyhurt = enemy->PerformBehavior(me);

        me->SetHealth(me->GetHealth() - myhurt);
        enemy->SetHealth(enemy->GetHealth() - enemyhurt);

        std::cout << "\nRound " << roundNumber << ") You: " << ToString(myMove) << ", Enemy: " << ToString(enemyMoveDeque.at(roundNumber - 1)) << "\n";
        PrintHealth(me->GetHealth(), enemy->GetHealth());

        roundNumber++;
    } while (roundNumber <= dequeSize && me->GetHealth() > 0 && enemy->GetHealth() > 0);

    // 승자 출력
    PrintResult(me->GetHealth(), enemy->GetHealth());

    return 0;
}