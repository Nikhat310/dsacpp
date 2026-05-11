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
				cout<<"enter node : ";
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

		static void reverse(){
			if(head==NULL)
			{
				cout<<"no elements! "<<endl;
				return;
			}
			Node *temp=NULL;
			Node *ptr=head;
			Node *cur=ptr->next;
			head->next=NULL;

		  while (cur!=NULL)
		  {
				temp=cur->next;
				cur->next=ptr;
				ptr=cur;
				cur=temp;
		  }
		  head=ptr;
		}

		static void disp()
		{
			Node *ptr;
			cout<<"elements are: "<<endl;
			ptr=head;
			while(ptr!=NULL){
				cout<<ptr->data<<"\n";
				ptr=ptr->next;

				}
			}
};
Node * SL::head;//static method in class define outside the class in cpp
int main(){
	
	  SL::create();
	  SL::disp();
	  SL::reverse();
	  SL::disp();
	  
	}

