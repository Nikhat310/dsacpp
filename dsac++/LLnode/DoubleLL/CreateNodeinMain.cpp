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
		cout<<"enter node1 : ";
		cur->prev=ptr;
		cin>>cur->data;
		cur->next=NULL;
		if(head == NULL){
			head = cur;
		}else{
			ptr->next=cur;
			cur->prev=ptr;
		}
		ptr=cur;
		cout<<"do you want to create next,then press y "<<endl;
		cin>>ch;
	}
	cout<<"elements are: "<<endl;
	ptr=head;
	while(ptr->next!=NULL)
	{
		cout<<ptr->data<<"\n";
		ptr=ptr->next;
	}
	cout<<ptr->data<<"\n"<<endl;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"\n";
		ptr=ptr->prev;
	}

}