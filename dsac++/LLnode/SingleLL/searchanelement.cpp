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
				cout<<"enter node "<<c<<" : ";
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
		static void searchele(int ele){
			if(head==NULL){
				cout<<"no nodes !"<<endl;
				return;
			}
			Node *ptr=head;
			int c=0,p=0;
			while(ptr!=NULL){
				p=p+1;
				if(ptr->data==ele){
					c++;
					break;
				}
			  ptr=ptr->next;	
			}
			if(ptr==NULL){
				cout<<"no such elements present here! "<<endl;
			}	else{
				cout<<ele<<" found in "<<" position "<<p<<endl;
			}
		}
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
	  cout<<"enter key element : ";
	  cin>>ele;
	  SL::searchele(ele);

	}

