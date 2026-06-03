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

	void insertRear(int ele)
	{
		if((front==0 && rear==max-1) || (front==rear+1))
		{
           cout<<"Queue overflow !";
           return;
		}

		if(front==-1)
		{
			front=0;
		}
		if(rear==max-1)
		{
			rear=0;
		}
		else
		{
        rear++;
		}

		arr[rear]=ele;
		cout<<"enQueued element is "<<arr[rear]<<endl;
	}


    void insertFront(int ele)
    {
      if((front==0 && rear==max-1) || (front==rear+1))
		{
           cout<<"Queue overflow !";
           return;
		}

		if(front==-1)
		{
			front=0;
			rear=0;
			arr[rear]=ele;
			return;
		}
		if(front==0)
		{
			front=max-1;
		}else
		{
		
        front--;

		}

		arr[front]=ele;
		cout<<"enQueued element is "<<arr[front]<<endl;

    }


	void deleteFront()
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
			if(front==max-1)
			{
				front=0;
			}else
			{
			front=front+1;

			}
	}

    void deleteRear()
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
			if(rear==0)
			{
				rear=max-1;
			}else
			{
			rear--;
		}
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
			cout<<"Queue underflow"<<endl;
			return;
		}
		int i=front;
		if (front<=rear)
		{
            while(i<=rear)
		{
			cout<<arr[i]<<" "<<endl;
			i++;
		}
		}
		else
		{
			while(i<=max-1)
			{
				cout<<arr[i]<<endl;
				i++;
			}
			i=0;
			while(i<=rear)
			{
				cout<<arr[i]<<endl;
				i++;
			}
		}
		
		
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
		cout<<"\nEnter your choice : \n1.insertRear element\n2.insertFront element\n3.deleteRear element\n4.deleteFront eleemnt\n5.peek element\n6.display eleemnt\n7.exit\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
			int ele;
			cout<<"Enter element: ";
			cin>>ele;
			obj.insertRear(ele);
			break;
	  
		case 2:int ele1;
			cout<<"Enter element: ";
			cin>>ele1;
			obj.insertFront(ele1);
			break;
		case 3: obj.deleteFront();
			break;
		case 4: obj.deleteRear();
			break;
		case 5:obj.peek();
			break;
        case 6:obj.disp();
	        break;
	    case 7:exit(0);
        default:cout<<"no choice"<<endl;
		}
	}
}