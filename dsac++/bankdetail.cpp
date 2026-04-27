#include<iostream>
using namespace std;
class bank{
	string name;
	int accNo,bal;
public:
	bank(string name,int accNo,int bal){
		this->name=name;
		this->accNo=accNo;
		this->bal=bal;
	}
	void bankDetails(){
		cout<<"Name : "<<name<<endl;
		cout<<"Account Num: "<<accNo<<endl;
		cout<<"Balance : "<<bal<<endl;
	}
	void deposit(int bal){
		this->bal=this->bal+bal;
		cout<<"Amount "<<bal<<" deposit success!\n"<<endl;
	}
	void withdraw(int bal){
		if(this->bal >= bal)
		{
			this->bal=this->bal-bal;
			cout<<bal<<" amount withdrawn!\n"<<endl;
		}else{
			cout<<"Insufficient balance!\n"<<endl;
		}
	}
	int show(){
		return this->bal;
	}

};
int main(){
	string name;
	int accNo,bal,ch;
	cout<<"name: ";
	cin>>name;
	cout<<"Account num: ";
	cin>>accNo;
	cout<<"Balance : ";
	cin>>bal;
	bank *b1=new bank(name,accNo,bal);
	// b1->bankDetails();

	while(1){
		cout<<"\nenter your choice : \n1.bankDetails\n2.deposit\n3.withdraw\n4.show\n5.exit\n";
		cin>>ch;
		switch(ch){
		case 1:
			b1->bankDetails();
			break;
		case 2:
cout<<"deposit amount : \n";
			cin>>bal;
			b1->deposit(bal);
			break;
		case 3:
			cout<<"withdraw amount: \n";
			cin>>bal;
			b1->withdraw(bal);
			break;
		case 4:
		    cout<<"Available balance : \n" <<b1->show();
			break;
		case 5:exit(0);
		default: cout<<"\nInvalid statement!";
		}
	}
   return 0;
}