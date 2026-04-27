using namespace std;
#include<iostream>
int main()
{
	int no1,no2,ch;
	cout<<"enter two nos\n";
	cin>>no1>>no2;
	cout<<"enter your choice\n1.add\n2.sub\n3.mult\n";
	cin>>ch;
	if(ch==1)
	{
		cout<<"sum="<<no1+no2<<endl;
	}
	else if(ch==2)
	{
			cout<<"sub="<<no1-no2<<endl;
	}
	else if(ch==3)
	{
		cout<<"mult="<<no1*no2<<endl;
	}
	else
	{
		cout<<"invalid choice\n";
	}
	return 0;
}