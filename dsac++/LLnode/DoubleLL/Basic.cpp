#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *prev;
	Node *next;

	
};
int main(){
	Node *f=new Node();
	Node *s=new Node();
	Node *t=new Node();
	f->data=10;
	f->prev=NULL;
	f->next=s;
	s->data=20;
	s->prev=f;
	s->next=t;
	t->data=30;
	t->prev=s;
	t->next=NULL;

	
	Node *ptr=f;
	while(ptr != NULL){
		cout<<ptr->data<<endl;
		ptr=ptr->next;
	}
    cout<<ptr->data<<"\n"<<endl;//last pointer
    while(ptr!=NULL)
    {
    	cout<<ptr->data<<endl;
		ptr=ptr->prev;
    }

}