using namespace std;
#include<iostream>
int add(){
	int no1,no2,s;
	cout<<"Enter two nums: ";
	cin>>no1>>no2;
	s=no1+no2;
	cout<<"sum is: "<<s<<endl;
	return s;
}
int sub(){
	int no1,no2,sub;
	cout<<"Enter two nums: ";
	cin>>no1>>no2;
	sub=no1-no2;
	cout<<"sub is: "<<sub<<endl;
	return sub;
}
int mul(){
	int no1,no2,mul;
	cout<<"Enter two nums: ";
	cin>>no1>>no2;
	mul=no1*no2;
	cout<<"mul is: "<<mul<<endl;
	return mul;
}
int main(){
	int ch;
	//cout<<"Enter two nums: ";
	// cin>>a>>b;
	while(1){
		cout<<"enter your choice: \n1.add\n2.sub\n3.mul\n4.exit";
		cin>>ch;
		switch(ch){
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