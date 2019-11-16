Compile:
bjam --toolset=gcc --verbose-test test

Run:
python OOP.py

#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/array.hpp>
#include <iostream>
using namespace std;

void greet()
{
	int n,i;
	int push(int,int, int [],int);
	int pop(int, int [], int);
	void display(int, int[]);
	cout<<"Hello!\n";
	cout<<"Enter the number of elements: ";
	cin>>n;
	cout<<"The number of elemets are: "<< n;
	int a[n],ch,top=-1;
	while(1)
	{
		cout<<"\nStack operation:-\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Push Operation:-"<<endl;
				cout<<"\nEnter element: ";
				int ele;
				cin>>ele;
				top=push(ele,n,a,top);
				break;
			case 2: cout<<"Pop Operation:-"<<endl;
				top=pop(n,a,top);
				break;
			case 3: cout<<"\nStack is:-\n";
				display(top,a);
				cout<<endl;
				break;
			case 4: cout<<"\nBye...\n";
				exit(1);
				break;
			default:cout<<"Invalid Input!!!"<<endl;
		}
	}
}

int push(int ele, int n, int a[], int top)
{
	if(top>=n-1)
	{
		cout<<"Overflow!!!\n";
		cout<<top<<endl;
		return top;
	}
	++top;
	a[top]=ele;
	cout<<ele<<" pushed into stack!\n";
	return top;
}
int pop(int n, int a[], int top)
{
	if(top==-1)
	{
		cout<<"Underflow!!!\n";
		return top;
	}
	cout<<"Popped element is: "<<a[top]<<endl;
	--top;
	return top;
}
void display(int top, int a[])
{
	if(top==-1)
	{
		cout<<"Empty!!!\n";
		return;
	}
	for(int i=0;i<=top;i++)
		cout<<a[i]<<" ";
}

BOOST_PYTHON_MODULE(hello_ext)
{
	using namespace boost::python;
	def("array_o", greet);
}
