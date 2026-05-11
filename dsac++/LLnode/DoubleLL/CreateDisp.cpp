#include<iostream>
using namespace std;


class Node{
public:
	int data;
	Node *next;
	Node *prev;
};

//HAS A type program as SL cls has cls node

class SL
{
	public:
		static Node *head;
		static void create()
		{
			Node *cur=NULL,*ptr=NULL,*prev=NULL;
	char ch='y';
	int c=0;
	while (ch == 'y')
	{
		c=c+1;
		cur=new Node();
		cout<<"enter node"<<c<<" : "<<endl;
		cur->prev=ptr;
		cin>>cur->data;
		cur->next=NULL;
		if(head == NULL)
		{
			head = cur;
		}
		else
		{
			ptr->next=cur;
			cur->prev=ptr;
		}
		ptr=cur;
		cout<<"do you want to create next,then press y "<<endl;
		cin>>ch;
	}
}
		static void dispForward()
		{
			if(head==NULL)
			{
				cout<<"empty list!";
				return;
			}
			Node *ptr=head;
		    cout<<"elements from forward : "<<endl;
	    
	    while(ptr!=NULL)
	{
		cout<<ptr->data<<"\n";
		ptr=ptr->next;
	}
}

	static void dispBackward()
	{
				if(head==NULL)
			{
				cout<<"empty list!";
				return;
			}
			Node *ptr=head;
		    
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
		cout<<"elements from backward : "<<endl;
	 

	while(ptr!=NULL)
	{
		cout<<ptr->data<<"\n";
		ptr=ptr->prev;
	}
	
    }
};
Node * SL::head;//static method in class define outside the class in cpp
int main(){
	
	  SL::create();
	  SL::dispForward();
	  SL::dispBackward();
	
	}

