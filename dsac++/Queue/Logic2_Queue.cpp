#include<iostream>
using namespace std;
class MyQueue
{
public:
	int *arr;
	int front,rear;
    int max;
	MyQueue(int size)
	{
		arr=new int[size];
		max=size;
		front=-1;
		rear=-1;
	}

	void enQueue(int ele)
	{
		if((rear+1)%max==front)
		{
           cout<<"Queue overflow !";
           return;
		}

		if(front==-1)
		{
			front=0;
		}
		

        rear=(rear+1)%max;

		arr[rear]=ele;
		cout<<"enQueued element is "<<arr[rear]<<endl;
	}

	void deQueue()
	{
		if(front==-1)
		{
			cout<<"Queue underflow"<<endl;
			return;
		}
		cout<<"removed element is "<<arr[front]<<endl;
		if(front==rear)
			{
				front=-1;
				rear=-1;
				return;
			}
			front=(front+1)%max;
	}

	void peek()
	{
		if(front==-1)
		{
			cout<<"Queue underflow"<<endl;
			return;
		}
		cout<<" element at the front is  "<<arr[front]<<endl;

	}

	void disp()
	{
		if(front==-1)
		{
			cout<<"\nQueue underflow"<<endl;
			return;
		}
		int i=front;
		do
		{
			cout<<arr[i]<<" "<<endl;
			i=(i+1)%max;
		}while(i!=(rear+1)%max);
		
	}

};

int main()
{
	int size,ch;
	cout<<"Size of the array : ";
	cin>>size;
    MyQueue obj(size);
	while(1)
	{
		cout<<"\nEnter your choice : \n1.enQueue element\n2.deQueue element\n3.peek element\n4.display eleemnt\n5.exit\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
			int ele;
			cout<<"Enter element: ";
			cin>>ele;
			obj.enQueue(ele);
			break;
	  
		case 2:obj.deQueue();
			break;
		case 3:obj.peek();
			break;
        case 4:obj.disp();
	        break;
	    case 5:exit(0);
        default:cout<<"Invalid choice"<<endl;
		}
	}
}