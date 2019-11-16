#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/array.hpp>
#include <iostream>
using namespace std;

void greet()
{
	int n,choice;
	cout<<"Hello!\n";
	cout<<"Enter the number of elements: ";
	cin>>n;
	cout<<"The number of elemets are: "<< n;
	while(1)
	{
	cout<<"\nChoose data structure:-\n1. Stack\n2. Queue\n3. Exit\nEnter your choice: ";
	cin>>choice;
	 switch(choice)
	 {
		case 1:{ 
			cout<<"Stack:-\n";
			int push(int,int,int [],int);
			int pop(int,int [],int);
			void display(int,int[]);
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
			break;

		case 2:{
			cout<<"Queue:-\n";
			void insert(int,int,int [],int,int);
			int delet(int,int [],int,int);
			void display(int,int,int []);
			int a[n],ch,front=-1,rear=-1;
			while(1)
			{
				cout<<"\nQueue Operation:-\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ";
				cin>>ch;
				switch(ch)
				{
					case 1: cout<<"Insert operation:-"<<endl;
						cout<<"Enter element: ";
						int ele;
						cin>>ele;
						insert(ele,n,a,front,rear);
						break;
					case 2: cout<<"Delete operation:-"<<endl;
						front=delet(n,a,front,rear);
						break;
					case 3: cout<<"\nQueue is:-\n";
						display(front,rear,a);
						cout<<endl;
						break;
					case 4: cout<<"Bye...";
						exit(1);
						break;
					default:cout<<"Invalid Input!";
				}
		        }
		       }
			break;

		case 3: cout<<"\nGood Bye...\n";
			exit(1);
			break;
		default:cout<<"Invalid Input!\n";
	 }
	}
}

void insert(int ele, int n, int a[], int& front,int& rear)
{
	if(rear==n-1)
	{
		cout<<"Overflow!!!\n";
		return;
	}
	if(front==-1)
		front=0;
	rear++;
	a[rear]=ele;
	return;
}
int delet(int n, int a[], int front, int rear)
{
	if(front==-1 || front>rear)
	{
		cout<<"Underflow!!!\n";
		return front;
	}
	cout<<a[front]<<" is deleted from queue\n";
	front++;
	return front;
}
void display(int front, int rear, int a[])
{
	if(front==-1)
	{
		cout<<"Empty!!!\n";
		return;
	}
	for(int i=front;i<=rear;i++)
		cout<<a[i]<<" ";
	cout<<endl;
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
