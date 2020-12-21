#include<stdio.h>

#define SIZE 10
#define true 1
#define false 0

int queue[SIZE];

int head = -1, tail = -1;

void enQueue(int);

int deQueue();

void size();

int queueEmpty();

void clear();
///////////////////////////////////


int main(){
    

    return 0;
}

void enQueue(int a){
    if(head == (tail+1)%SIZE){
        printf("error");
        return;
    }else if(head == -1){
        head = 0;
        tail = 1;
        queue[head] = a;
    }else{
            queue[tail] = a;
            tail = (tail+1) % SIZE;
    }
}

int deQueue(){
    int a = -2137;
    if(tail == -1){
        printf("error");
        return -2137;
    }else{
        a = queue[head];
        head += (head+1) % SIZE;
        return a;
    }
}

void size(){
    if( tail > head){
        return tail - head;
    }else if(tail == head){
        return 0;
    }else{
        return tail + SIZE-head;
    }
}

int queueEmpty(){
    if(head == tail){
        return true;
    }
    return false;
}

void clear(){
    head = -1;
    tail = -1;
}
