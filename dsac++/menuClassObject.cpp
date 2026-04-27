#include<iostream>
using namespace std;
class rectangle
{
private:
	int l,b;
public:
	rectangle(int l,int b){
		this->l=l;
		this ->b=b;
	}
	void show(){
		cout<<"Length = "<<l<<endl;
		cout<<"Breadth = "<<b<<endl;
	}
	void area(){
		int ar;
        ar=l*b;
        cout<<"Area = "<<ar<<endl;
	}
	int perimeter(){
		return 2*(l+b);
	}
	
};
int main(){
	int length,breadth;
	cout<<"Enter length and breadth ";
	cin>>length>>breadth;
	rectangle r1(length,breadth);
	r1.show();
	r1.area();
	cout<<"perimeter = "<<r1.perimeter()<<endl;
	return 0;
}