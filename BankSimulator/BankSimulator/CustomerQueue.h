//
//  CustomerQueue.h
//  BankSimulator
//
//  Created by Giovanni Junseo Kim on 2022/10/23.
//

#ifndef CustomerQueue_h
#define CustomerQueue_h

#include "Customer.h"

using namespace std;

#define MAX_QUEUE_SIZE 100

class CustomerQueue {
protected:
    int front;     // 첫 번째 요소 앞의 위치
    int rear;     // 마지막 요소 위치
    int data[MAX_QUEUE_SIZE]; // 요소의 배열
public:
    CustomerQueue(){ front = rear = 0; }
    bool isEmpty() { return front == rear; }
    bool isFull() { return (rear+1)%MAX_QUEUE_SIZE == front; }
    void enqueue( Customer customer ) { // 큐에 삽입
        if( isFull() )
            cout << " error: 큐가 포화상태입니다\n";
        else {
            rear = (rear+1) % MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }
    int dequeue( ) {     // 첫 항목을 큐에서 빼서 반환
        if( isEmpty() )
            cout << " error: 큐가 포화상태입니다\n";
        else {
            front = (front+1) % MAX_QUEUE_SIZE;
            return data[front];
        }
        return 0;
    }
    int peek( ) {         // 첫 항목을 큐에서 빼지 않고 반환
         if( isEmpty() )
             cout << " error: 큐가 포화상태입니다\n";
         else
            return data[(front+1) % MAX_QUEUE_SIZE];
        return 0;
    }
    void display( ) {     // 큐의 모든 내용을 순서대로 출력
       printf( "큐 내용 : ");
       int maxi = (front < rear) ? rear : rear+MAX_QUEUE_SIZE;
       for( int i = front+1 ; i<=maxi ; i++ )
            printf( "[%2d] ", data[i%MAX_QUEUE_SIZE]);
        cout << endl;
    }
};



#endif /* CustomerQueue_h */
