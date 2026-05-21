#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
};
	class MyStack
	{
	public:
		Node *top;
	
	MyStack()
	{
		top=NULL;
	}

	void push(int ele)
	{

		Node *cur=new Node();
		if(cur==NULL)
		{
			cout<<"Satck overflow!"<<endl;
			return ;
		}

		cur->data=ele;
		cur->next=top;
		top=cur;
		cout<<"Pushed element is "<<ele<<endl;

		
	}

	void pop()
	{
		if(top==NULL)
		{
			cout<<"Stack is underflow!"<<endl;
			return;
		}
		cout<<"Popped element is "<<top->data<<endl;
		top=top->next;
	}

	void peek()
	{
		if(top==NULL)
		{
			cout<<"Stack is underflow"<<endl;
			return;
		}
		cout<<" element is "<<top->data<<endl;

	}

	void disp()
	{
		if(top==NULL)
		{
			cout<<"Satck is underflow! "<<endl;
			return;
		}

		Node *ptr=top;
		while(ptr!=NULL)
		{
			cout<<ptr->data<<endl;
			ptr=ptr->next;
		}
	}

};

int main()
{

	int ch,ele;
	
    MyStack *s=new MyStack();
	while(1)
	{
		cout<<"Enter your choice : \n1.push element\n2.pop element\n3.peek element\n4.display eleemnt\n5.exit\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
			int ele;
			cout<<"Enter element: ";
			cin>>ele;
			s->push(ele);
			break;
	  
		case 2:s->pop();
			break;
		case 3:s->peek();
			break;
        case 4:s->disp();
	        break;
	    case 5:exit(0);
        default:cout<<"no choice"<<endl;
		}
	}
}