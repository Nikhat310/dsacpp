#include<iostream>
using namespace std;
class student{
	string name;
	float total;
	string grade;
public:
	student(string name,float total,string grade){
		this->name=anme;
		this->total=total;
		this->grade=grade;
	}
	void display(){
		cout<<" NAme of the student : "<<name<<endl;
		cout<<" Marks of the student : "<<total<<endl;
		cout<<" grade of the student : "<<grade<<endl;
	}
};
int main(){
	string name,float total,string grade;
	cout<<"Name : ";
	cin>>name;
	cout<<"Toatl Mark : ";
	cin>>total;
	cout<<"Grade : ";
	cin>>grade;
	student *s1=new student(name,total,grade);
	s1->display();
}