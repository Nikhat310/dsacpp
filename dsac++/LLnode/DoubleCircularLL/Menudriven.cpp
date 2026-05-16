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

static void InsertBeg(int ele)
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
            	
            	           cur->next=head;
            	           cur->prev=ptr;
            	           head->prev=cur;
			    ptr->next=cur;
			    head=cur;
			
			    cout<<"Inserted New Node in the beginning: "<<ele<<endl;
            

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


static void deleteBeg()
		   {
			if(head==NULL)
			{
				cout<<"empty List !"<<endl;
				return;
			}
            if(head->next==head)
            {
               head=NULL;
               cout<<"successfully deleted first node "<<endl;
               return;
            }
            
            	Node *ptr=head->prev;
            	  cout<<"deleted Node in the beginning: "<<head->data<<endl;
            	head=head->next;
            	ptr->next=head;
            	head->prev=ptr;

		}

static void deleteEnd()
		   {
			if(head==NULL)
			{
				cout<<"empty List !"<<endl;
				return;
			}
            if(head->next==head)
            {
               head=NULL;
               cout<<"successfully deleted node "<<endl;
               return;
            }
            
            	Node *ptr=head->prev->prev;
            	cout<<"deleted Node in the ending: "<<head->prev->data<<endl;
            	ptr->next->prev=NULL;
            	ptr->next->next=NULL;
            	ptr->next=head;
            	head->prev=ptr;


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
	int ch;
	while(1)
	{
		cout<<"enter your choice : \n1.create\n2.dispForward\n3.dispBackward\n4.InsertBeg\n5.InsertEnd\n6.deleteBeg\n7.deleteEnd\n8.exit\n";
		cin>>ch;
		switch(ch)
		{
	  
		case 1:SL::create();
			break;
	  
		case 2:SL::dispForward();
			break;
		case 3:SL::dispBackward();
			break;
        case 4:SL::InsertBeg(33);
	        break;
        case 5:SL::InsertEnd(44);
	        break;
        case 6:SL::deleteBeg();
	        break;
        case 7:SL::deleteEnd();
	        break;
	    case 8:exit(0);
        default:cout<<"no choice"<<endl;
		}
	}
	  
	
	}

