#include <iostream>
//#include <stdio.h>
#include<stdlib.h>

#define MAX 10
#define MAXNUM 11
#define RASCAL


class Cqueue {
    int q[MAXNUM];
    int front, rear;

    public:
    Cqueue() {front=0; rear=0;}
    int push(int);
    int pop();
};
int Cqueue::push(int in) {
    std::cout<<" ";
    if (front == (rear+1) % MAXNUM ) {
        std::cout << "Circular Queue overflow";
        return -1;
    }
    rear = (rear+1)% MAXNUM;
    this->q[rear-1] = in;
    if (front == -1 )
        front = 0;
    return 0;
}
int Cqueue::pop() {
    if (front == rear && rear ==-1) {
        std::cout << "Circular Queue underflow";
        return -1;
    }
    int element;
    element = this->q[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAXNUM;
    return element;
}
int main() {
    int i, temp;
    Cqueue cir;

    std::cout << "Enter the circular queue variables" << std::endl;
    for (i=0; i<MAX; i++) {
         std::cin  >> temp;
         cir.push(temp);
    }
    //printf("who is there?\n");
    for (i=0; i<MAX; i++) {
        std::cout << "variables are " << cir.pop() << std::endl;
    }
    std::cout << "stop\n";
    std::cin  >> temp;
}
