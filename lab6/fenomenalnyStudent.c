#include<stdio.h>
#include<stdlib.h>

unsigned long long int schodek(int n, int r){
    unsigned long long int *schodki = malloc(sizeof(unsigned long long int)*n);
    schodki[0] = 1;

    for(int i = 1; i < n; i++){
        for(int j=1;j<=r;j++){
            if(i-j>=0){
                schodki[i]+=schodki[i-j];
            }else if(i-j == -1){
                schodki[i]++;
            }
        }
    }

    unsigned long long int result = schodki[n-1];
    free(schodki);

    return result;
}

int main(){
   int n, r;

   scanf("%d", &n);
   scanf("%d", &r);

   printf("%llu", schodek(n,r));

 //   printf("%d %d: %lld\n", 9, 9, schodek(9,9));

    // for(int i=1; i< 40; i++){
    //     for (int j=1; j< 20; j++){
    //         printf("%d %d: %lld\n", i, j, schodek(i,j));
    //     }
    // }

    return 0;
}