#include<iostream>
#include<iomanip>
using namespace std;

class employee
{
	public:
		double salary, hourlyRate, taxRate, taxAmount, grossPay, netPay, otPay;
		int hours, otHours;

		int payStat;
		int employeeID;
		string firstName,lastName;
}
void printData()
	{
		cout<<setprecision(2)<<setiosflags(ios::fixed | ios::showpoint);
		cout<<setw(10)<<firstName<<setw(10)<<lastName<<setw(10)<<employeeID<<setw(10)<<hours<<setw(10)<<otHours<<setw(10)<<grossPay<<setw(10)<<netPay<<setw(10)<<otPay<< endl;
	}
class employeeSalary : public employee
{
	public:
		double calculateGrossPay()
		{
			double hourlyRate = (salary/40);
  
