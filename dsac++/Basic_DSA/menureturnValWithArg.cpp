using namespace std;
#include<iostream>
int add(int no1,int no2){
	int s;
	s=no1+no2;
	cout<<"sum is:"<<s<<endl;
	return s;
}
int sub(int no1,int no2){
	int sub;
	sub=no1-no2;
	cout<<"Sub is : "<<sub<<endl;
	return sub;
}
int mul(int no1,int no2){
	int mul;
	mul=no1*no2;
	cout<<"mul is:"<<mul<<endl;
	return mul;
}
int main(){
	int x,y,ch;
	cout<<"enter ur numbers: ";
	cin>>x>>y;
	while(1){
		cout<<"Enter your choice: \n1.add\n2.sub\n3.mul\n4.exit\n";
		cin>>ch;
		switch(ch){
			case 1:add(x,y);
			break;
		case 2:sub(x,y);
			break;
		case 3:mul(x,y);
			break;
		case 4:exit(0);
		default:cout<<"invalid choice";

		}
	}
}