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
	while (ch == 'y'){
		c=c+1;
		cur=new Node();
		cout<<"enter node"<<c<<" : ";
		cur->prev=cur;
		cin>>cur->data;
		cur->next=cur;
		if(head == NULL){
			head = cur;
		}else{
			ptr->next=cur;
			cur->prev=ptr;
			cur->next=head;
			head->prev=cur;
		}
		ptr=cur;
		cout<<"do you want to create next,then press y "<<endl;
		cin>>ch;
	}
}
static void InsertEnd(int ele)
		   {
			Node *cur=new Node();
			cur->prev=cur;
			cur->data=ele;
			cur->next=cur;
			if(head==NULL)
			{
				head=cur;
				return;
			}
           
            	Node *ptr=head->prev;
            	ptr->next=cur;
            	cur->next=head;
            	cur->prev=ptr;
            	head->prev=cur;
			   
			
			    cout<<"Inserted New Node in the ending: "<<ele<<endl;
            

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
	    
	    do
	{
		cout<<ptr->data<<"\n";
		ptr=ptr->next;
	}while(ptr!=head);
}

	static void dispBackward()
	{
				if(head==NULL)
			{
				cout<<"empty list!";
				return;
			}
		cout<<"elements from backward : "<<endl;

			Node *ptr=head->prev;
		    
	 do
	{
		cout<<ptr->data<<"\n";
	
		ptr=ptr->prev;
	}while(ptr!=head->prev);

	 
    }
};
Node * SL::head;//static method in class define outside the class in cpp
int main(){
	
	  SL::create();
	  SL::dispForward();
	  SL::dispBackward();
	  SL::InsertEnd(99);
	  SL::dispForward();
	  SL::dispBackward();
	
	}

