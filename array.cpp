#include<iostream>
using namespace std;

class array
{
    public:
        int n;
	    char *ptr;
    void take_input()
    {
	    cout<<"Enter the size of the array: ";
	    cin>>n;

	    ptr=new (nothrow) char[n];
	    if (ptr == nullptr)
        cout << "Error: memory could not be allocated";
	    else
	    {
		    cout<<"Enter the elements: ";
		    for(int i=0;i<n;i++)
		    {
			    cin>>ptr[i];
		    }
	    }
    }
    void display()
    {
        int j;
        for(j=0;j<n-1;j++)
        {
            cout<<ptr[j]<<",";
        }
        cout<<ptr[j]<<".";
    }
};
int main()
{
    array obj;
    
    obj.take_input();
    obj.display();
    return 0;
}
