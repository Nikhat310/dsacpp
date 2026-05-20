#include<iostream>
using namespace std;
class A{
public:
	void loop(){
		cout<<"Loop Method"<<endl;
	}
};
class B{
public:
	A *ob;
	void show(){
		cout<<"show method";
	}
};
int main(){
	B *obj=new B();
	obj->ob->loop();
	obj->show();


}