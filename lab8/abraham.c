#include<stdio.h>

int synowie[17];

void uzupelnij(){
    synowie[1] = 7;
    int synowiepom[17];
    synowiepom[1] = 7;

    for(int i = 2; i < 17; i++){
        if(i%2 == 0)
            synowiepom[i] = synowiepom[i-1] * 5;
        else{
            synowiepom[i] = synowiepom[i-1] * 3;    
        }
        
        synowie[i]=synowie[i-1] + synowiepom[i];
    }

}

int main(){
    int n, pom;
    scanf("%d", &n);
    uzupelnij();
    for(int i = 0; i < n; i++){
        scanf("%d", &pom);
        printf("%d", synowie[pom]);
    }
    return 0;
}