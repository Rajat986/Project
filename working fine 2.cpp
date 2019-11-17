#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <iostream>
using namespace std;
#define SIZE 5

class queue
{
	private:
		int *arr ;
		int front, rear ;
		int MAX ;
	public:
		queue(int maxsize=10);
		void addq(int item);
		void delq();
		void disp();
};

queue::queue(int maxsize)
{
	MAX=maxsize ;
	arr=new int[MAX];
	front=-1;
	rear=-1;
}
void queue::addq(int item)
{
	if(rear==MAX-1)
	{
		cout<<"\nQueue is Full!!!";
		return;
	}
	rear++;
	arr[rear]=item;
	if(front==-1)
		front=0;
}
void queue::delq()
{
	if(front==-1)
	{
		cout << "\nQueue is Empty!!!\n" ;
		return;
	}
	cout<<"Deleted item is: "<<arr[front]<<endl;
	arr[front]=0;
	if(front==rear)
		front=rear=-1;
	else
		front++;
}
void queue::disp()
{
	if(front==-1)
	{
		cout<<"\nQueue is empty!!!\n";
		return;
	}
	for(int i=front;i<=rear;i++)
		cout<<arr[i]<<endl;
}

class stack
{
	private:
		int top;
		int num[SIZE];
	public:
		stack();
		int push(int);
		int pop();
		int isEmpty();
		int isFull();
		void displayItems();
};
stack::stack()
{
    top=-1;
}
int stack ::isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int stack::isFull()
{
	if(top==(SIZE-1))
		return 1;
	else
		return 0;
}
int stack::push(int n)
{
	if(isFull())
		return 0;
	++top;
	num[top]=n;
	return n;
}
int stack::pop()
{
	int temp;
	if(isEmpty())
		return 0;
	temp=num[top];
	--top;
	return temp;
}
void stack::displayItems()
{
	int i;
	if(top==-1)
	{
		cout<<"Stack is Empty!!!\n";
		return;
	}
	cout<<"STACK is:\n";
	for(i=top; i>=0; i--)
		cout<<num[i]<<endl;
	cout<<endl;
}

void greet()
{
 int ch;
 do
 {
	cout<<"1. Stack\n2. Queue\n3. Exit\nEnter your choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:{
			stack stk;
			int choice, n,temp;
			do
			{
				cout<<endl;
				cout<<"1. Push Item\n2. Pop Item\n3. Display Stack\n4. Exit\n"<<endl;
				cout<<"Enter your choice: ";
				cin>>choice;
				switch(choice)
				{
					case 1: cout<<"Enter item to insert: ";
						cin>>n;
						temp=stk.push(n);
						if(temp==0)
							cout<<"STACK is FULL."<<endl;
						else
							cout<<temp<<"is inserted into Stack."<<endl;
						break;
					case 2: temp=stk.pop();
						if(temp==0)
							cout<<"STACK IS EMPTY."<<endl;
						else
							cout<<temp<<" is removed from Stack."<<endl;
						break;
					case 3: stk.displayItems();
						break;
					case 4: cout<<"Bye...\n";
						break;
					default:cout<<"An Invalid choice."<<endl;
				}
			}while(choice!=4);
		       }
		       break;
		case 2:{
			cout<<"Hello|\n";
			queue a(10);
				a.addq ( 22 ) ;
	a.addq ( 19 ) ;
	a.addq ( 30 ) ;
	a.addq ( 32 ) ;
	a.delq( ) ;
	a.delq( ) ;
	a.delq( ) ;
	cout<<"\n";
		       }
			 break;
		case 3: cout<<"Good Bye...\n";
			break;
		default:cout<<"Invalid Input!!!\n";
	}
 }while(ch!=3);
}


BOOST_PYTHON_MODULE(hello_ext)
{
    using namespace boost::python;
    def("greet", greet);
}
