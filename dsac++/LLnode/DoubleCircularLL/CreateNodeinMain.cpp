#include<iostream>
using namespace std;
class Node{
public:
	int data;
	Node *prev;
	Node *next;
};
int main(){
	Node *head=NULL,*cur=NULL,*ptr=NULL,*prev=NULL;
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
	

	cout<<"Forward: "<<endl;

	 ptr=head;
	do{
		cout<<ptr->data<<endl;
		ptr=ptr->next;
	}while(ptr != head);

    
    cout<<"\n"<<endl;
	cout<<"Backward: "<<endl;
    ptr=head->prev;
    do
    {
    	cout<<ptr->data<<endl;
		ptr=ptr->prev;
    }while(ptr!=head->prev);

}