#include<stdio.h>
#include<stdlib.h>

int mutex=1,full=0,empty=3,x=0;

int wait(int s)
{
	return (--s);
}

int signal(int s)
{
	return(++s);
}

void producer()
{
	empty=wait(empty);
	mutex=wait(mutex);

	mutex=signal(mutex);
	full=signal(full);
	x++;
	printf("\nProducer produces the item %d\n",x);
}

void consumer()
{
	full=wait(full);
	mutex=wait(mutex);

	mutex=signal(mutex);
	empty=signal(empty);
	printf("\nConsumer consumes item %d\n",x);
	x--;
}

int main()
{
	int n;

	printf("Follow the following instructions: \n");
	printf("\n1.Producer\n2.Consumer\n3.Exit\n");
	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:	if((mutex==1)&&(empty!=0))
						producer();
					else
						printf("Buffer is full!!\n");
					break;
			case 2:	if((mutex==1)&&(full!=0))
						consumer();
					else
						printf("Buffer is empty!!\n");
					break;
			case 3:
					exit(0);
					break;
		}
	}

	return 0;
}
