#include<iostream>
#include<string>

#define ENQ "ENQUEUE"
#define DEQ "DEQUEUE"

#define SIZE 11
#define true 1
#define false 0

int errorFlag = false;

int * queue = (int*) calloc(SIZE, sizeof(int));

int head = -1, tail = -1;

void enQueue(int);

int deQueue();

int size();

int queueEmpty();

void clear();
///////////////////////////////////

void display(){
    int i = 0, iHead=head;;

    while(i < size()){
        std::cout << queue[iHead] << "\n";
        iHead = (iHead+1)%SIZE;
        i++;
    }
}

int main(){
    std::string input;
    int a;

    std::cin >> input;

    while (input != "END"){
        if(input == ENQ){
            std::cin >> a;
            enQueue(a);
        }else if(input == DEQ){
            deQueue();
        }
        std::cin >> input;
    }

    if(errorFlag == false){
        display();
    }else{
        printf("error");
    }

    return 0;
}

void enQueue(int a){
    if(head == (tail+1)%SIZE){
        errorFlag = true;
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
        errorFlag = true;
        return -2137;
    }else if(size() == 0){
        errorFlag = true;
        head = -1;
        tail = -1;
        return -2137;
    }else{
        a = queue[head];
        head = (head+1) % SIZE;
        return a;
    }
}

int size(){
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
