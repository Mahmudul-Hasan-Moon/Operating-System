// SCAN Disk Scheduling Algorithm
#include<bits/stdc++.h>
using namespace std;

#define LOW 0
#define HIGH 199

int main()
{
    int queue[20];
    int head, max, n, temp, sum, dloc; //location of head in queue

    printf("Enter head value: ");
    scanf("%d",&head);

    printf("Input size of queue: ");
    scanf("%d",&n);

    printf("Enter the element of the Queue: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &queue[i]);
    }

    queue[n] = head; //add head into queue
    n++;

    sort(queue,queue+n); //sort the array

    max = queue[n-1];

    //locate head in the queue
    for(int i=0; i<n; i++)
    {
        if(head == queue[i])
        {
            dloc = i;
            break;
        }
    }

    if(abs(head-LOW) <= abs(head-HIGH))
    {

        for(int j=dloc; j>=0; j--)
        {
            printf("%d --> ",queue[j]);
        }
        printf("%d -->",LOW);
        for(int j=dloc+1; j<n; j++)
        {
            printf("%d --> ",queue[j]);
        }
        sum  = head + max;
        printf("\nmovement of total cylinders %d", sum);
    }
    else
    {

        for(int j=dloc; j<n; j++)
        {
            printf("%d --> ",queue[j]);
        }
        printf("%d -->",HIGH);
        for(int j=dloc-1; j>=0; j--)
        {
            printf("%d --> ",queue[j]);
        }
        sum  = (HIGH - head)+ (HIGH- queue[0]);
        printf("\nmovement of total cylinders %d", sum);
    }

    return 0;
}
