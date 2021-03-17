#include<iostream>
using namespace std;
char CPU[100];
int choice;

int front=0,rear=0;

void push(int n)
{

    if(rear==n)
        cout<<"Overflow"<<endl;
    else
    {
        char value;

        cout<<"Enter your value : ";
        cin>>value;
        if(rear==0){
            CPU[rear]=value;
            rear++;
        }
        else if(CPU[rear-1]=='W')
            cout<<"You can't insert anything"<<endl;
        else if(CPU[rear-1]=='R'&&value=='R'){
        CPU[rear]=value;
        rear++;
        }
        else if(CPU[rear-1]=='R'&&value=='W'){
                cout<<"Writer can not enter here\n";
        }
    }
}
void pop()
{
    if(front==rear-1){
        cout<<"All are removed"<<endl;
        front=0,rear=0;
    }
    else
    {
        front++;
        cout<<"The item is popped successfully"<<endl;
    }
}
void display()
{
    if(front==rear)
        cout<<"CPU is empty"<<endl;
    else{
    for(int i=front;i<rear; i++)
        cout<<CPU[i]<<' ';
    cout<<endl;
    }
}

int main()
{

    int n;

    cout<<"Enter the size of the CPU : ";
    cin>>n;

    while(1)
    {
        cout<<"******** MENU *******"<<endl;
        cout<<"\n 1: push \n 2: pop \n 3: display"<<endl;

        int choice;

        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            push( n);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        }
    }
    return 0;
}
