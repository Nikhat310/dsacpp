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
		static void count(){

		}
		static void countCheck(){
			int ec=0,oc=0;
			if(head==NULL){
				cout<<"no elements!"<<endl;
				return;
			}
			Node *ptr=head;
			while(ptr!=NULL){
				
					if(ptr->data%2==0){
						ec=ec+1;
					}else{
						oc=oc+1;
					}
					ptr=ptr->next;
			}
				cout<<"number of even data nodes : "<<ec<<endl; 
				cout<<"number of odd data nodes : "<<oc<<endl; 


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
	  SL::countCheck();
	  SL::disp();
	  
	}

