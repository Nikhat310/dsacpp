#include<iostream>
#include<climits>
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
	

	//smallest element
// static void smallestEle()
// {
// 	int small=arr[0];
// 	for(int i=1;i<size;i++)
// 	{
//   if(small>arr[i])
//   {
//   	small=arr[i];
//   }
// 	}
//   cout<<"biggest element in the array is "<<small<<endl;

// }


//big and second big element
	static void smallAndSsmall()

{
	int small=INT_MAX;
	int s2=INT_MAX;
	for(int i=0;i<size;i++)
	{
  if(small>arr[i])
  {
  	s2=small;
  	small=arr[i];
  }
  if(arr[i]>small && arr[i]<s2)
  {
  	s2=arr[i];
  }
	}
  cout<<"smallest element in the array is "<<small<<endl;
  cout<<"Second smallest element in the array is "<<s2<<endl;


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
	ArrayDemo::smallAndSsmall();
	
}