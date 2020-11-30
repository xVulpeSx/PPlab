#include<stdio.h>
#include<stdlib.h>

void setters(int *a, int *b, int *c){
    (*a) = 0;
    (*b) = 0;
    (*c) = 0;
}

void check(int *number, int *flowersUsed, int *leafsUsed, int *counter){
    (*counter)++;

    if((*number) % 2 == 0){
        (*flowersUsed)++;
        (*number)/=2;
    }else{
        (*leafsUsed)++;
        (*number) = ((*number) * 3) + 1;
    }
}

int main(){
    int number, counter, flowersUsed, leafsUsed;
    
    scanf("%d", &number);

   while(number != 0){
       setters(&counter, &leafsUsed, &flowersUsed);
       while(number != 1 && counter < 16){
           check(&number, &flowersUsed, &leafsUsed, &counter);
       }

       if(counter < 16 && number == 1){
           printf("TAK %d %d\n", flowersUsed, leafsUsed);
       }else{
           printf("NIE\n");
       }
       scanf("%d", &number);
   }

    return 0;
}