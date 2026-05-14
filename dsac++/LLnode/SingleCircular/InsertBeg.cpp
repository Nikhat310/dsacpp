#include<iostream>
using namespace std;


class Node{
public:
	int data;
	Node *next;
};

//HAS A type program as SL cls has cls node

class SL
{
	public:
		static Node *head;
		static void create()
		{
			Node *cur=NULL,*ptr=NULL;
            char ch='y';
			int c=0;
			while (ch == 'y'){
				c=c+1;
				cur=new Node();
				cout<<"enter node"<<c<<" : ";
				cin>>cur->data;
				cur->next=cur;
				if(head == NULL){
					head = cur;
				}else{
					ptr->next=cur;
					cur->next=head;
				}
				ptr=cur;
				cout<<"do you want to create next,then press y "<<endl;
				cin>>ch;
				}
		}
		static void InsertBeg(int ele)
		   {
			Node *cur=new Node();
			cur->data=ele;
			cur->next=cur;
			if(head==NULL)
			{
				head=cur;
				
			}
            else
            {
            	Node *ptr=head;
            	while(ptr->next!=head)
            	{
                   ptr=ptr->next;
            	}
            	           cur->next=head;
			    ptr->next=cur;
			    head=cur;
			}
			    cout<<"Inserted New Node in the beginning: "<<ele<<endl;
            

		}
		static void disp()
		{
			Node *ptr;
			cout<<"elements are: "<<endl;
			ptr=head;
			do{
				cout<<ptr->data<<"\n";
				ptr=ptr->next;

				}while(ptr!=head);
			}
};
Node * SL::head;//static method in class define outside the class in cpp
int main(){
	
	  SL::create();
	  SL::disp();
	  SL::InsertBeg(5);
	  SL::disp();
	  
	}

