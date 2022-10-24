//
//  main.cpp
//  BankSimulator
//
//  Created by Giovanni Junseo Kim on 2022/10/18.
//

#include <ctime>
#include "BankSimulator.h"
#include "CustomerQueue.h"
using namespace std;

int main()
{
    srand( (unsigned int)time(NULL) );
    BankSimulator sim;        // 시뮬레이터 객체 생성
    sim.readSimulationParameters( );    // 시뮬레이션 파라미터 설정
    sim.run();            // 시뮬레이션 시작
    sim.printStat();            // 시뮬레이션 결과 출력
}
