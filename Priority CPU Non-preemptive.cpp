#include<bits/stdc++.h>
using namespace std;

int main()
{
    int P[100],BT[100],AT[100],PR[100],sum=0,n,i,j,temp,TAT,WT,SWT=0;
    float avg;

    printf("Enter the number of process: ");
    scanf("%d",&n);

    printf("First Enter Process Number then arrival time then burst time and Last Priority.\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&P[i]);
        scanf("%d",&AT[i]);
        scanf("%d",&BT[i]);
        scanf("%d",&PR[i]);
    }

        for(i=0; i<n; i++)  // short both array according to Arrival time
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

                temp=PR[i];
                PR[i]=PR[j];
                PR[j]=temp;
            }
        }
    }


    for(i=1; i<n; i++)  // short both array according to priority
    {
        for(j=i; j<n; j++)
        {
            if(PR[i]<PR[j])
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

                temp=PR[i];
                PR[i]=PR[j];
                PR[j]=temp;
            }
        }
    }

    for(i=0; i<n; i++)
    {
        printf("P%d -->",P[i]);
        sum=sum+BT[i];
        TAT = abs(sum - AT[i]);
        printf(" %d |",TAT);
        WT = abs(TAT - BT[i]);
        printf(" %d \n",WT);
        SWT = SWT + WT;
    }
    printf("\nTotal Time in Gan Chart is %d\n",sum);

    avg=SWT/(float)n;
    printf("\nAverage Waiting Time is %f\n",avg);

    return 0;
}



