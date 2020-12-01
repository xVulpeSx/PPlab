#include<stdio.h>
#include<stdlib.h>

long long schodek(int n, int r){
    long long  *schodki = (long long *) malloc(sizeof(long long)*n);
    schodki[0] = 1;

    for(int i=1;i<n;i++){
        schodki[i]=0;
    }

    for(int i = 1; i < n; i++){
        for(int j=1;j<=r;j++){
            if(i-j>=0){
                schodki[i]+=schodki[i-j];
            }else if(i-j == -1){
                schodki[i]++;
            }
        }
    }

    long long result = schodki[n-1];
    free(schodki);

    return result;
}

int main(){
   int n, r;

   scanf("%d", &n);
   scanf("%d", &r);

   printf("%lld", schodek(n,r));

 //   printf("%d %d: %lld\n", 9, 9, schodek(9,9));

    // for(int i=1; i< 40; i++){
    //     for (int j=1; j< 20; j++){
    //         printf("%d %d: %lld\n", i, j, schodek(i,j));
    //     }
    // }

    return 0;
}