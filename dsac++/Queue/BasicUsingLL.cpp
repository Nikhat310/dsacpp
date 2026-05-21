#include<iostream>
using namespace std;
class Node{
public:
	int data;
	Node *next;

};

class MyQueue
{
public:
	
	Node *front,*rear;
    
	MyQueue()
	{
		front=NULL;
		rear=NULL;
	}

	void enQueue(int ele)
	{
		Node *cur=new Node();
		if(cur==NULL)
		{
			cout<<"Queue overflow"<<endl;
			return;
		}
		cur->data=ele;
		cur->next=NULL;
		if(front==NULL)
		{
			front=cur;
		}
		if(rear==NULL)
		{
		rear=cur;
		return;
	   }
		rear->next=cur;
		rear=cur;

		cout<<"enQueued element is "<<ele<<endl;
	}

	void deQueue()
	{
		if(front==NULL)
		{
			cout<<"Queue underflow"<<endl;
			return;
		}
		cout<<"deQueued element is "<<front->data<<endl;
		if(front==rear)
			{
				front=NULL;
				rear=NULL;
				return;
			}
			front=front->next;
	}

	void peek()
	{
		if(front==NULL)
		{
			cout<<"Queue underflow"<<endl;
			return;
		}
		cout<<" element at the front is  "<<front->data<<endl;

	}

	void disp()
	{
		if(front==NULL)
		{
			cout<<"Queue underflow"<<endl;
			return;
		}
		Node *ptr=front;
		while(ptr!=NULL)
		{
			cout<<ptr->data<<endl;
			ptr=ptr->next;
		}
	}

};

int main()
{
	int ch;
	
    MyQueue *obj=new MyQueue();
	while(1)
	{
		cout<<"Enter your choice : \n1.enQueue element\n2.deQueue element\n3.peek element\n4.display eleemnt\n5.exit\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
			int ele;
			cout<<"Enter element: ";
			cin>>ele;
			obj->enQueue(ele);
			break;
	  
		case 2:obj->deQueue();
			break;
		case 3:obj->peek();
			break;
        case 4:obj->disp();
	        break;
	    case 5:exit(0);
        default:cout<<"no choice"<<endl;
		}
	}
}