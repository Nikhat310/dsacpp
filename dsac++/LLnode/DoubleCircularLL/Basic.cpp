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
	f->prev=t;
	f->data=10;
	f->next=s;
	s->data=20;
	s->prev=f;
	s->next=t;
	t->prev=s;
	t->data=30;
	t->next=f;

	cout<<"forward: "<<endl;
	
	Node *ptr=f;
	do{
		cout<<ptr->data<<endl;
		ptr=ptr->next;
	}while(ptr != f);
	cout<<"Backward: "<<endl;
    ptr=f->prev;
    do
    {
    	cout<<ptr->data<<endl;
		ptr=ptr->prev;
    }while(ptr!=f->prev);

}