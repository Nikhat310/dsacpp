#include<iostream>
using namespace std;
class MyStack
{
public:
	int *arr;
	int top;
    int max;
	MyStack(int size)
	{
		arr=new int[size];
		max=size;
		top=-1;
	}

	void push(int ele)
	{
		if(top==max-1)
		{
			cout<<"Stack is full"<<endl;
			return;
		}
		top++;
		arr[top]=ele;
		cout<<"Pushed element is "<<arr[top]<<endl;
	}

	void pop()
	{
		if(top==-1)
		{
			cout<<"Stack is underflow!"<<endl;
			return;
		}
		cout<<"Popped element is "<<arr[top]<<endl;
		top=top-1;
	}

	void peek()
	{
		if(top==-1)
		{
			cout<<"Stack is underflow"<<endl;
			return;
		}
		cout<<" element is "<<arr[top]<<endl;

	}

	void disp()
	{
		if(top==-1)
		{
			cout<<"Satck is underflow! "<<endl;
			return;
		}
		int i=top;
		while(i>=0)
		{
			cout<<arr[i]<<" "<<endl;
			i--;
		}
	}

};

int main()
{
	// int size;
	// cout<<"Size of the array : ";
	// cin>>size;

	// MyStack obj(5);
	// obj.push(10);
	// obj.push(20);
	// obj.push(30);
	// obj.push(40);
	// obj.pop();
	// obj.peek();
	// obj.disp();
	// return 0;

	int size,ch;
	cout<<"Size of the array : ";
	cin>>size;
 MyStack obj(size);
	while(1)
	{
		cout<<"Enter your choice : \n1.push element\n2.pop element\n3.peek element\n4.display eleemnt\n5.exit\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
			int ele;
			cout<<"Enter element: ";
			cin>>ele;
			obj.push(ele);
			break;
	  
		case 2:obj.pop();
			break;
		case 3:obj.peek();
			break;
        case 4:obj.disp();
	        break;
	    case 5:exit(0);
        default:cout<<"no choice"<<endl;
		}
	}
}