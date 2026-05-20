using namespace std;
#include<iostream>
void add(){
	int no1,no2,s;
	cout<<"Enter two numbers: ";	
	cin>>no1>>no2;
	s=no1+no2;
	cout<<"Sum is: "<<s<<endl;
	return;
}
int main(){
	add();
	add();
	return 0;
}