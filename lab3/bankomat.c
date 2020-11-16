#include <stdio.h>

int KASA[5] = {10, 20, 50, 100, 200};

void stanBankomatu(int bank[]){
    for(int i=0; i<5;i++){
        scanf("%d", &bank[i]);
    }
}

void wypisz(int bank[]){
    for(int i=0;i < 5; i++){
        printf("%d ", bank[i]);
    }
}

void wyplata(int bank[], int n){
    int sum=0, i = 4;

    while(sum < n && i>= 0){
        if(bank[i] > 0 && sum+KASA[i]<=n){
            bank[i]--;
            sum+=KASA[i];
        }else{
            i--;
        }
    }

    if(sum == n){
        printf("TAK\n");
    }else{
        printf("NIE\n");
    }
}

int main() {
    int bankomat[5];
    int n, check;

    scanf("%d", &n);

    for(int i=0; i < n; i++){
        stanBankomatu(bankomat);
        scanf("%d", &check);
        wyplata(bankomat, check);
    }

    return 0;
}

