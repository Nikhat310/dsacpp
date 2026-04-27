using namespace std;
#include<iostream>
#include<stdlib.h>

void add(){
	int no1,no2,s;
	cout<<"Enter two numbers: ";	
	cin>>no1>>no2;
	s=no1+no2;
	cout<<"Sum is: "<<s<<endl;
	return;
}
void sub(){
	int no1,no2,sub;
	cout<<"Enter two numbers: ";	
	cin>>no1>>no2;
	sub=no1-no2;
	cout<<"Sub is: "<<sub<<endl;
	return;
}
void mul(){
	int no1,no2,mul;
	cout<<"Enter two numbers: ";	
	cin>>no1>>no2;
	mul=no1*no2;
	cout<<"mul is: "<<mul<<endl;
	return;
}
int main()
{
	int no1,no2,ch;
	cout<<"enter two nos\n";
	cin>>no1>>no2;
	while(1)
	{
		cout<<"enter your choice\n1.add\n2.sub\n3.mult\n4.exit\n";
		cin>>ch;
		switch(ch)
		{
		case 1:add();
			break;
		case 2:sub();
			break;
		case 3:mul();
			break;
		case 4:exit(0);
		default:cout<<"invalid choice";
	}
}
	
	return 0;
}