#include <stdio.h>
#include <stdlib.h>

int main(){
  int queue[100], n, head, seek =0, dif,sum = 0;
  float avg;

  printf("Enter head value:");
  scanf("%d", &head);

  printf("Enter the size of the queue: ");
  scanf("%d", &n);

  printf("Enter queue elements: ");
  for(int i=1; i<=n; i++){
    scanf("%d",&queue[i]);
  }

  queue[0]=head;

  for(int j=0; j<n; j++){
        printf("%d -->",queue[j]);
        if(queue[j+1]>queue[j])
        sum = sum + abs(queue[j+1]-queue[j]);
        else
        sum = sum + abs(queue[j]-queue[j+1]);
  }
  printf("Total cost: %d\n",sum);

  return 0;
}
