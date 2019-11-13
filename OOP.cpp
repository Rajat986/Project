#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/array.hpp>
#include <iostream>
using namespace std;

void greet()
{
	int n,i,test=1;
	cout<<"Enter the number of elements: ";
	cin>>n;
	cout<<"The number of elemets are: "<< n;
	int a[n];
	cout<<"Enter the elements:-"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"Enter element["<<i+1<<"]: ";
		cin>>a[i];
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";

	int ch;
	
	
		test++;
		cout<<"Stack operation:-\n1. Push\n2. Pop\n3. Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Push Operation:-"<<endl;
				break;
			case 2: cout<<"Pop Operation:-"<<endl;
				break;
			case 3: cout<<"\nBye...\n";
				exit(1);
				break;
			default:cout<<"Invalid Input!!!"<<endl;
		}
	
}

BOOST_PYTHON_MODULE(hello_ext)
{
	using namespace boost::python;
	def("array_o", greet);
}
