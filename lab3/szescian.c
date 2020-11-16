#include <stdio.h>

int main() {
    int i=1;
    while (i<=36)
    {
        printf("%d ", i);
        if(i%6==0){
            printf("\n");
        }
        i++;
    }
    

    return 0;
}
