using namespace std;
#include<iostream>
#include<stdlib.h>
void add(int x,int y){
	int s;
	s=x+y;
	cout<<"Sum is: "<<s<<endl;
	return;
}
void sub(int x,int y){
	int sub;
	sub=x-y;
	cout<<"Sub is: "<<sub<<endl;
	return;
}
void mul(int x,int y){
	int mul;
	mul=x*y;
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
		case 1:add(no1,no2);
			break;
		case 2:sub(no1,no2);
			break;
		case 3:mul(no1,no2);
			break;
		case 4:exit(0);
		default:cout<<"invalid choice";
	}
}
	
	return 0;
}