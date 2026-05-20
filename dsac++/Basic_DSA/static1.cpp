#include<iostream>
using namespace std;
class A{
public:
	static void show(){
		cout<<"Show method!"<<endl;
	}
	void loop(){
		cout<<"Loop method!"<<endl;
	}

};
int main(){
	A::show();
	A *a=new A();
	a->loop();
}