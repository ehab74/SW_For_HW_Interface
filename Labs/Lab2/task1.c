#include <stdio.h>
#include <stdlib.h>

int main(){
    int x,n;
    char o;
    printf("Enter an 8 bit number:\n");
    scanf("%d",&x);
    printf("Enter number of rotate cycles:\n");
    scanf("%d",&n);
    printf("Enter rotate option (l for left or r for right):\n");
    scanf(" %c",&o);
    n%=8;
    int pow = 1;
    for (int i=0;i<n;i++)
     pow*=2;
    pow--; 
    if (o=='r'){
        int mask = x & pow;
        x = x>>n;
        x|= mask<<8-n;
    }
    else {
        pow = pow<<8-n;
        int mask = x & pow;
        x = x<<n;
        if (x>=256)
        x-=256;
        x|= mask>>8-n;
    }
    printf("%d\n",x);
    return 0;
}