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
	

	//biggest element
// static void biggestEle()
// {
// 	int big=arr[0];
// 	for(int i=1;i<size;i++)
// 	{
//   if(big<arr[i])
//   {
//   	big=arr[i];
//   }
// 	}
//   cout<<"biggest element in the array is "<<big<<endl;

// }


//big and second big element
	static void bigAndSbigEle()

{
	int big=INT_MIN;
	int sbig=INT_MIN;
	for(int i=0;i<size;i++)
	{
  if(big<arr[i])
  {
  	sbig=big;
  	big=arr[i];
  }
  if(arr[i]<big && arr[i]>sbig)
  {
  	sbig=arr[i];
  }
	}
  cout<<"biggest element in the array is "<<big<<endl;
  cout<<"Second biggest element in the array is "<<sbig<<endl;


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
	ArrayDemo::bigAndSbigEle();
	
}