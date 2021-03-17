#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,i,j,s[100];

    printf("Enter number of Philoshoper : ");

    while(scanf("%d",&n)!=EOF){
    if(n%2!=0){
        for(i=1;i<n;i=i+2)
            printf("P%d -- ",i);
        for(i=2;i<n;i=i+2)
            printf("P%d -- ",i);
        printf("P%d \n",n);

        printf("Enter number of Philoshoper : ");
    }
    else{
        for(i=1;i<=n;i=i+2)
            printf("P%d -- ",i);
        for(i=2;i<=n;i=i+2)
            printf("P%d -- ",i);

        printf("\n");

        printf("Enter number of Philoshoper : ");
    }
    }

    return 0;
}
