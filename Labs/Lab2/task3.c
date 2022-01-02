#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    char o;
    printf("Enter the number of series terms:\n");
    scanf("%d",&n);
    if (n==1)
    printf("%d",0);
    else if (n==2)
    printf("%d,%d",0,1);
    else{
        printf("%d,%d,",0,1);
        int cnt1 = 0;
        int cnt2 = 1;
        for (int i = 0;i<n-2;i++){
            int total = cnt1+cnt2;
            printf("%d",total);
            cnt1 = cnt2;
            cnt2 = total;
            if (i<n-3)
            printf(",");
        }
    }
    return 0;

}
