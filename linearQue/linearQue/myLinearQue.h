//
//  myLinearQue.h
//  linearQue
//
//  Created by Giovanni Junseo Kim on 2022/10/04.
//

#ifndef myLinearQue_h
#define myLinearQue_h
#define MAX_QUEUE_SIZE 5

#include <iostream>

class CircularQueue {
protected:
    int front;     // 첫 번째 요소 앞의 위치
    int rear;     // 마지막 요소 위치
    int data[MAX_QUEUE_SIZE]; // 요소의 배열
public:
    CircularQueue(){ front = rear = -1; }
    bool isEmpty() { return front == rear; }
    bool isFull() { return rear == MAX_QUEUE_SIZE-1; }
    void enqueue( int val ) { // 큐에 삽입
        if( isFull()){
            printf(" error: 큐가 포화상태입니다\n");
            if(front == -1){
                printf("큐의 요소들을 앞으로 땡길 수 없습니다.\n");
            }
            else{
                printf("큐의 요소들을 최대한 앞으로 땡겨보겠습니다.\n");
                for(int i = 0; i<rear-front ;i++)
                    data[i] = data[front+1+i];
                rear = rear - (front+1);
                front = -1;
                enqueue(val);
                printf("큐의 요소들을 최대한 앞으로 땡기고, 추가하였습니다.\n");
            }
        }
        else {
            rear = (rear+1);
            data[rear] = val;
        }
    }
    int dequeue( ) {     // 첫 항목을 큐에서 빼서 반환
        if( isEmpty()){
            printf(" Error: 큐가 공백상태입니다\n");
            return 0;
        }
        else {
            front = (front+1);
            return data[front];
        }
    }
    int peek( ) {         // 첫 항목을 큐에서 빼지 않고 반환
        if( isEmpty()){
            printf(" Error: 큐가 공백상태입니다\n");
            return 0;
        }
         else
               return data[front+1];
    }
    void display( ) {     // 큐의 모든 내용을 순서대로 출력
           printf( "큐 내용 : ");
        int maxi = rear;
           for( int i = front+1 ; i<=maxi ; i++ )
                printf( "[%2d] ", data[i]);
           printf( "\n");
    }
};

#endif /* myLinearQue_h */
