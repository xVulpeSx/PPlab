#include<stdio.h>

struct Pole
{
    int x, y;
};


int main(){
    int n;
    struct Pole a;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d %d", &a.x, &a.y);
        printf("%d\n", a.x * a.y);
    }
}