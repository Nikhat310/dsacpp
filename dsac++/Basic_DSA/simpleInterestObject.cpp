#include<iostream>
using namespace std;
class SI{
	float p,r,t;
public:
	SI(float p,float r,float t){
		this->p=p;
		this->r=r;
		this->t=t;
	}
	void show(){
		cout<<"enter principle value : "<<p<<endl;
		cout<<"enter time : "<<t<<endl;
		cout<<"enter rate : "<<r<<endl;


	}
	float calculation(){
		float si;
		si=(p*r*t)/100;
		// cout<<"Simple Interest is "<<si<<endl;
		return si;
	}
};
int main(){
	float a,b,c;
	cout<<"enter a b c: ";
	cin>>a>>b>>c;
	SI *s1=new SI(a,b,c);
	s1->show();
	cout<<"simple interest :"<<s1->calculation()<<endl;
return 0;
}
