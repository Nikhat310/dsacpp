#include<iostream>
using namespace std;
class A{
public:
	void loop(){
		cout<<"Loop Method"<<endl;
	}
};
class B:public A{
public:
	void show(){
		cout<<"show method"<<endl;
	}
};
int main(){
	A *ob=new A();
	ob->loop();
	B *obj=new B();
	obj->show();
	obj->loop();

}