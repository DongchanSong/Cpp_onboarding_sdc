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
        // Move 덱으로부터 move number 가져오기
        int myMove = myMoveDeque.at(roundNumber - 1);
        int enemyMove = enemyMoveDeque.at(roundNumber - 1);

        DoNothingCheck(myDoNothingFlag, myMove, enemyMove);
        DoNothingCheck(enemyDoNothingFlag, enemyMove, myMove);

        // 각자 행동 정의
        me->SetBehavior(myMove);
        enemy->SetBehavior(enemyMove);

        // 위에서 정의된 행동으로 각자 피해 계산
        double myhurt = me->PerformBehavior(enemy);
        double enemyhurt = enemy->PerformBehavior(me);

        // 피해 반영
        me->SetHealth(me->GetHealth() - myhurt);
        enemy->SetHealth(enemy->GetHealth() - enemyhurt);

        // 라운드 결과 출력
        std::cout << "\nRound " << roundNumber << ") You: " << ToString(myMove) << ", Enemy: " << ToString(enemyMoveDeque.at(roundNumber - 1)) << "\n";
        PrintHealth(me->GetHealth(), enemy->GetHealth());

        roundNumber++;
    } while (roundNumber <= dequeSize && me->GetHealth() > 0 && enemy->GetHealth() > 0);

    // 승자 출력
    PrintResult(me->GetHealth(), enemy->GetHealth());

    return 0;
}