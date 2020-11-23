#include<stdio.h>

void temerrraturra(int tab[], int xD){
    for(int i=0; i < 7; i++){
        printf("MIASTO %d, dzien %d = %d\n", xD, i+1, tab[i]);
    }
}

int main(){
    int miastoX[7], miastoD[7];

    for(int i = 0; i < 7; i++){
        scanf("%d", &miastoX[i]);
    }

     for(int i = 0; i < 7; i++){
        scanf("%d", &miastoD[i]);
    }

    temerrraturra(miastoX, 1);
    temerrraturra(miastoD, 2);

    return 0;
}