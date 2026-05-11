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
		
		static Node * create()
		{
		    
		     Node *head=NULL;

			Node *cur=NULL,*ptr=NULL;
            char ch='y';
			int c=0;
			while (ch == 'y')
			{
				c=c+1;
				cur=new Node();
				cout<<"enter node : ";
				cin>>cur->data;
				cur->next=NULL;
				if(head == NULL)
				{
					head = cur;
				}else
				{
					ptr->next=cur;
				}
				ptr=cur;
				cout<<"do you want to create next,then press y "<<endl;
				cin>>ch;
				}
				return head;
		}

		static void merge(Node * L1,Node *L2)
		{
           if(L1==NULL && L2==NULL)
           {
           	cout<<"list is empty!";
           	return;
           }
           Node *ptr=L1;
           Node *head3=NULL;
           while(ptr!=NULL)
           {
           	head3=appendLL(head3,ptr->data);
           	ptr=ptr->next;
           }
           ptr=L2;
           while(ptr!=NULL)
           {
           	head3=appendLL(head3,ptr->data);
           	ptr=ptr->next;
           }
           disp(head3);
		}

		static Node* appendLL(Node *head,int ele)
		{
			Node *cur=new Node();
			cur->data=ele;
			cur->next=NULL;
			if(head==NULL)
			{
            head=cur;
            return head;
			}
			Node *ptr=head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=cur;
			return head;
			

		}


		static void disp(Node *head)
		{
			Node *ptr;
			cout<<"elements are: "<<endl;
			ptr=head;
			while(ptr!=NULL){
				cout<<ptr->data<<"\n";
				ptr=ptr->next;

				}
			}
};
// Node * SL::head;//static method in class define outside the class in cpp
int main(){
	Node *L1=SL::create();
	Node *L2=SL::create();
	SL::disp(L1);
	SL::disp(L2);
	cout<<"after merge : "<<endl;
	SL::merge(L1,L2);
	  // SL::disp(L1);
	  // SL::disp(L2);

	  
	  
	}

