#include <stdio.h>
#include <stdlib.h>

int main(){
    for(int i = 1; i < 10; i++){
        int j = i;
        if (i >= 6){
            j = 10 - i;
        }
        j += j - 1;
        for(int k = 1; k < 10; k++){
            if (k > (9 - j)/2 && k < 10 - ((9 - j)/2))
            printf("*");
            else
            printf(" ");
        }
        printf("\n");
    }
    return 0;   
}