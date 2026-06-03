#include<iostream>
#include<string>
using namespace std;

class MyStack
{

	int arr[20];
	int top;

public:
	MyStack()
	{
		top=-1;
	}

	void push(int ele)
	{
		
		top++;
		arr[top]=ele;
	}

	int pop()
	{
		int item = arr[top];
		arr[top]=0;
		top=top-1;
		return item;
	}


};
class Post_Evaluate{
	MyStack st;

public:
	bool isOperand(char ch)
	{
		return((ch>='a' && ch<='z') || 
			(ch>='A' && ch<='Z') || 
			(ch>='0' && ch <='9'));
	}

	bool isOperator(char ch)
	{
		return (ch=='+' || ch=='-' || ch=='*' || ch == '/');
	}

	int postEval(string postfix)
	{
		int i;
		int item1,item2,r=0;

		for (int i = 0; i < postfix.length() ; i++)
		{
			char ch=postfix[i];

			if(ch==' ')

			{
				continue;
			}

			if(isOperand(ch))
			{
				if(ch>='0' && ch<='9')
				{
					int su=0;

					while(i<postfix.length() && isOperand(ch))
					{
						if(ch>='0' && ch<='9')
						{
							su=su*10+ (ch- '0');
						}

						i++;

						if(i< postfix.length())
						ch=postfix[i];
					else
						break;
					}
					i--;
					st.push(su);
				}
				else
				{
					cout<<"enter the value : "<<ch<<" : ";
					cin>>r;
					st.push(r);
				}

			}
			if(isOperator(ch))
			{
				item2=st.pop();
				item1=st.pop();
				if(ch=='+')
				{
					st.push(item1+item2);
				}
				else if(ch=='-')
				{
					st.push(item1-item2);
				}
				else if(ch=='*')
				{
					st.push(item1*item2);
				}
				else if(ch=='/')
				{
					st.push(item1/item2);
				}
				else
				{
					cout<<"Invalid Operand";
					exit(0);

				}
			}
		}
		return st.pop();
	}

};

int main()
{

	Post_Evaluate ob;
	string postfix;

	cout<<"Enter the postfix expression : ";
	getline(cin,postfix);

	cout<<"Postfix evaluated result = "<<ob.postEval(postfix);

	return 0;
}