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
		cout<<"Enter array elements :"<<endl;
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
	

	static void search(int ele,int rep)
	{
		int c=0;
		for(int i=0;i<=size;i++)
		{
			if(arr[i]==ele)
			{
				arr[i]=rep;
			    c++;

				// break;
			}
		}
		cout<<ele<<"replaced by "<<rep<<" "<<c<<"times"<<endl;
		
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
	// ArrayDemo::dispB();
	ArrayDemo::search(5,9);
	ArrayDemo::dispF();
	// ArrayDemo::dispB();
}