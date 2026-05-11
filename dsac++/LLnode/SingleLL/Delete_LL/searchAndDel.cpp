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
		static void searchdelele(int ele){
			Node *temp=NULL;
			if(head==NULL){
				cout<<"no nodes !"<<endl;
				return;
			}
			Node *ptr=head;
			if(head->data==ele){
				cout<<"deleted element "<<head->data<<endl;
				head=head->next;
				return;
			}
			
			

		  while(ptr!=NULL){
				
				if(ptr->data==ele && ptr->next!=NULL){
					temp->next=ptr->next;
					break;
				}else if(ptr->next==NULL){
           temp->next=NULL;
					
				}
				temp=ptr;
			  ptr=ptr->next;	
			}
			
		// 	if(ptr->next!=NULL){
		// 		temp->next=ptr->next;
		// 	}else{
        //    temp->next=NULL;
		// 	}
		// }
		
	

		static void disp()
		{
			Node *cur=new Node();
			Node *ptr;
			cout<<"elements are: "<<endl;
			ptr=head;
			while(ptr!=NULL){
				cout<<ptr->data<<"\n";
				ptr=ptr->next;

				}
			}
};
Node * SL::head;
int main(){
	
	  SL::create();
	  // SL::searchNode();
	  SL::disp();
	  int ele;
	  cout<<"enter delete element : ";
	  cin>>ele;
	  SL::searchdelele(ele);
	  SL::disp();

	}

