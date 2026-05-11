#include<iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	
};
int main(){
	Node *f=new Node();
	Node *s=new Node();
	Node *t=new Node();
	f->data=10;
	f->next=s;
	s->data=20;
	s->next=t;
	t->data=30;
	t->next=NULL;
	Node *ptr=f;
	while(ptr != NULL){
		cout<<ptr->data<<endl;
		ptr=ptr->next;
	}

}