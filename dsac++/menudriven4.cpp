using namespace std;
#include<iostream>
int main(){
	int i;
	i=1;
	cout<<"A";
	while(i<5){
		cout<<"B";
		i++;
		if(i>=3){
			break;
		}
		cout<<"C";
	}
	cout<<i;
	cout<<"D";
	
}