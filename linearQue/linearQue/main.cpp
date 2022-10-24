//
//  main.cpp
//  linearQue
//
//  Created by Giovanni Junseo Kim on 2022/10/04.
//

#include <iostream>
#include "myLinearQue.h"
int main() {
    CircularQueue que;
    for( int i=1 ; i<5; i++ )
        que.enqueue( i );
    que.display();
    que.enqueue(5);
    printf("5 추가 완료\n");
    que.display();
    que.enqueue(6);
    que.dequeue();
    que.dequeue();
    que.dequeue();
    que.display();
    que.enqueue(8);
    que.display();
}
