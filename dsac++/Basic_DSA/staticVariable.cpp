#include<iostream>
using namespace std;
class A{
public:
	int x=0;
	int y=0;
	static int z;

};
int A::z=0;
int main(){
	cout<<A::z<<endl;
	//cout<<A::x<<endl  //error
	A *a=new A();
	A *b=new A();
	a->x=10;
	b->y=10;
	cout<<a->x<<" "<<b->y<<endl;
	a->z=30;
	b->z=50;
	cout<<a->z<<" "<<b->z<<" "<<A::z<<endl;
	return 0;

}