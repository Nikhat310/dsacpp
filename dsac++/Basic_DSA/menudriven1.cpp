using namespace std;
#include<iostream>
int main()
{
	int no1,no2,ch;
	cout<<"enter two nos\n";
	cin>>no1>>no2;
	cout<<"enter your choice\n1.add\n2.sub\n3.mult\n";
	cin>>ch;
	switch(ch)
	{
	case 1:cout<<"sum=no1+no2";break;
	case 2:cout<<"sub=no1-no2";break;
	case 3:cout<<"mul=no1*no2";break;
	default:cout<<"invalid choice";
}
	
	return 0;
}