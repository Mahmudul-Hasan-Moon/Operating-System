#include<bits/stdc++.h>
using namespace std;

int main()
{
    int P[100],BT[100],AT[100],pr[100],sum=0,n,i,j,temp,T,k=0,asum=0,x=0;
    float avg;

    printf("Enter the size of Queue: ");
    scanf("%d",&n);

    printf("First Enter Process Number then arrival time and then enter burst time.\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&P[i]);
        scanf("%d",&AT[i]);
        scanf("%d",&BT[i]);
    }

    printf("Enter the Time to process a schedule per time: ");
    scanf("%d",&T);

     for(i=0; i<n; i++)
    {
        sum=sum+BT[i];
    }

    for(i=0; i<n; i++)  // short both array according to arrival time
    {
        for(j=i; j<n; j++)
        {
            if(AT[i]>AT[j])
            {
                temp=AT[i];
                AT[i]=AT[j];
                AT[j]=temp;

                temp=P[i];
                P[i]=P[j];
                P[j]=temp;
                // short the BT according to the difference time
                temp=BT[i];
                BT[i]=BT[j];
                BT[j]=temp;
            }
        }
    }

    int maxx = 0;
    for(i=0; i<n; i++)
    {
        if(BT[i]>maxx)
            maxx = BT[i];
    }

    x = ceil((maxx*1.0)/T);  // x is count for how many time the loop works

    k = 0;

    for(j=0; j<x; j++)
    {
        for(i=0; i<n; i++)
        {
            if(BT[i]>=T)
            {
                BT[i] = BT[i] - T;
                pr[k] = P[i];
                k++;
            }
            else if(BT[i]<T && BT[i]>0)
            {
                BT[i] = 0;
                pr[k] = P[i];
                k++;
            }
        }
    }

    for(i=0; i<k; i++)
        printf("P%d -->",pr[i]);


    printf("\nTotal Time in Gan Chart is %d\n",sum);

    avg=sum/(float)n;
    printf("\nAverage Time is %f\n",avg);

    return 0;
}


