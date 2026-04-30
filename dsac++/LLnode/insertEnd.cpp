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
				cout<<"enter node1 : ";
				cin>>cur->data;
				cur->next=NULL;
				if(head == NULL){
					head = cur;
				}else{
					ptr->next=cur;
				}
				ptr=cur;
				cout<<"do you want to create next,then press y "<<endl;
				cin>>ch;
				}
		}
		static void insertEnd(int ele){
			Node *cur=new Node();
			cur->data=ele;
			cur->next=NULL;
			if(head==NULL)
			{
            head=cur;
            return;
			}
			Node *ptr=head;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			ptr->next=cur;
			cout<<"Inserted New Node at the end!"<<ele<<endl;

		}
		static void disp()
		{
			Node *cur=new Node();
			Node *ptr;
			cout<<"elements are: "<<endl;
			ptr=head;
			while(ptr!=NULL){
				cout<<ptr->data<<"\n";
				ptr->next=cur;

				}
			}
};
Node * SL::head;
int main(){
	
	  SL::create();
	  SL::disp();
	  SL::insertEnd(5);
	  SL::disp();
	  
	}

