using namespace std;
#include<iostream>
int main(){

	//even Odd
	// int no;
	// cout<<"Enter a num: ";
	//cin>>no;
	// if(no%2==0){
	// 	cout<<"Even num!"<<endl;
	// }
	// if(no%2!=0){
	// 	cout<<"Odd num!"<<endl;
	// }

	//2digt no
//     int no;
// 	cout<<"Enter a num: ";
// 	cin>>no;
// if(no>9){
// 	if(no<100){
// 		cout<<"2 digit number!"<<endl; 
// 	}

	//nested if
	int no;
	cout<<"Enter a num: ";
	cin>>no;
	if(no==0){
		cout<<"Num is "<<no<<endl;
	}else{
		if(no>=0){
			cout<<"+ve num!"<<endl;
		}else{
			cout<<"num is -ve!"<<endl;
		}
	}
	return 0;
}
