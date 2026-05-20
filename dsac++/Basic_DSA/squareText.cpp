#include<iostream>
using namespace std;
class square{
	int n;
public:
	square(int n){
		this->n=n;
	}
	void show(){
		cout<<"num : "<<n<<endl;
	}
	int squ(){
		return n*n;
	}
};
int main(){
	int num;
	cout<<"enter a num: ";
	cin>>num;
	// square s1(num);
	// s1.show();
	// cout<<"Square of a num is "<<s1.squ()<<endl;

	square *s1=new square(num);
	s1->show();
	cout<<"square :"<<s1->squ()<<endl;
return 0;
}
