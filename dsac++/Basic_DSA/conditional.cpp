using namespace std;
#include<iostream>
int main(){
	// int a=20,b=10;
	// if(a>=20 && b<=10){
	// 	cout<<"Both the conditions are true!"<<endl;
	// }else{
	// 	cout<<"At least one of the condition is false!"<<endl;
	// }

	//check +ve no
	int no;
	cout<<"Enetr a no: ";
	cin>>no;
	if(no>=0){
		cout<<"The no is +ve!"<<endl;
	}
	if(no<0){
		cout<<"-ve no";
	}

	int sal,da,hra,total;
	cout<<"enter a salary: ";
	cin>>sal;
	da=sal*0.3;
	hra=sal*0.2;
	if(sal>=5000){
		total=sal+da+hra;
		cout<<"Basic salary = "<<sal<<endl;
		cout<<da<<endl;
		cout<<hra<<endl;
		cout<<"totalsal = "<<total<<endl;
	}
	return 0;
}