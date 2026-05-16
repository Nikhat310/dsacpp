#include<iostream>
using namespace std;
class ArrayDemo
{
public:
	 static int *arr;
	 static int size;

	ArrayDemo(int size)
	{
		this->size=size;
		arr=new int[size];
	}

	static void input()
	{
		cout<<"Enter array elements :";
		int i;
		for( i=0;i<size;i++)
		{
			cin>>arr[i];
		}
	}

	static void dispF()
	{
		int i;
		cout<<"elements in forward : ";
		for (i=0;i<size;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;

	}
	
static void dispB()
	{
		int i;
		cout<<"elements in backward : ";
		for (i=size-1;i>=0;i--)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;

	}

	static void sum()
	{
		int s=0;
		cout<<"Sum of the elements : ";
		for (int i=0;i<size;i++)
		{
			s=s+arr[i];
		}
cout<<"Sum of the elements = "<<s<<endl;
	}

};
int *ArrayDemo::arr=NULL;
int ArrayDemo::size=0;
int main()
{
	int size;
	cout<<"Size of the array : ";
	cin>>size;
	ArrayDemo obj(size);
	ArrayDemo::input();
	ArrayDemo::dispF();
	ArrayDemo::dispB();
	ArrayDemo::sum();
}