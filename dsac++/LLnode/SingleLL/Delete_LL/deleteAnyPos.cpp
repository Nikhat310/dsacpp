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
		static int countNode(){
			if(head==NULL){
				cout<<"no nodes !"<<endl;
				return 0;
			}
			Node *ptr=head;
			int count=0;
			while(ptr!=NULL){
				
					ptr=ptr->next;
					count=count+1;
					}
			
				return count; 
		}
		static void deletePos(int pos){
			if(head==NULL){
				cout<<"no nodes !"<<endl;
				return;
			}
			int c=countNode();
			if(pos>c || pos<1){
				cout<<"invalid position";
				return;
			}
			Node *ptr=head;
			int i=1;
			while(i<(pos-1)){
				i=i+1;
				ptr=ptr->next;
			}
			cout<<"deleted element : "<<ptr->next->data<<endl;
			ptr->next=ptr->next->next;

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
	  SL::disp();
	  SL::deletePos(2);
	  SL::disp();
	  
	}

