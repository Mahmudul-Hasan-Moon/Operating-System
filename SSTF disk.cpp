#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int queue[100],t[100],head,sum=0,n,i,j,temp;
    float avg;

    printf("Enter the value of head: ");
    scanf("%d",&head);

    printf("Enter the size of Queue: ");
    scanf("%d",&n);

    printf("Enter the Queue\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&queue[i]);
    }

    for(i=0; i<n; i++)
        t[i]= abs(head-queue[i]);  // store the difference in the T array

    for(i=0; i<n; i++)
    {
        for(j=i; j<n; j++)
        {
            if(t[i]>t[j])
            {
                temp=t[i];
                t[i]=t[j];
                t[j]=temp;
                                            // short the queue according to the difference time
                temp=queue[i];
                queue[i]=queue[j];
                queue[j]=temp;
            }
        }
    }

    printf("%d -->",head);  // first print the head
    for(i=0; i<n; i++)
    {
        printf("%d -->",queue[i]);
        sum=sum+abs(head-queue[i]);
        head=queue[i];
    }
    printf("\nTotal sum Time is %d\n",sum);

    avg=sum/(float)n;
    printf("\nAverage sum Time is %f\n",avg);

    return 0;
}

