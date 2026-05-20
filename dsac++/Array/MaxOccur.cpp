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

	static void maxCount()
	{
		int i;
	  int maxCount=0;
		int ele=arr[0];
		for(int i=0;i<size;i++)
		{
			int count=1;
          if(arr[i]==-1)
          {
          	continue;
          }
          for(int j=i+1;j<=size;j++)
          {
          	if(arr[j]==-1)
          	{
          		continue;
          	}
          	if(arr[i]==arr[j])
          	{
          		arr[j]=-1;
          		count++;
          	}
          
          }
          	if(count>maxCount)
          {
          	maxCount=count;
          	ele=arr[i];
          }
		}
       cout<<ele<<" occuring maximum time in the array "<<maxCount<<" times"<<endl;   
		
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
	ArrayDemo::maxCount();
}