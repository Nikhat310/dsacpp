#include<iostream>
using namespace std;
class Node{
public:
	int data;
	Node *next;
};
int main(){
	Node *head=NULL,*cur=NULL,*ptr=NULL;
	char ch='y';
	int c=0;
	while (ch == 'y'){
		c=c+1;
		cur=new Node();
		cout<<"enter node1 : ";
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
	cout<<"elements are: "<<endl;
	ptr=head;
	while(ptr!=NULL){
		cout<<ptr->data<<"\n";
		ptr=ptr->next;
	}

}