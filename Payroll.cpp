#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;
ofstream outfile;

class employee
{
	public:
		double salary, hourlyRate, taxRate, taxAmount, grossPay, netPay, otPay;
		int hours, otHours;

		int payStat;
		int employeeID;
		string firstName,lastName;

	void setVariables( int empID, string fName, string lName, int stat, int rate, int hrs )
	{
		employeeID = empID;
		firstName = fName;
		lastName = lName;
		payStat = stat;

		if(payStat == 1)
		{
			hourlyRate = rate;
		}
		else
		{
			salary = rate;
		}
		hours=hrs;
	}

	virtual double calculateGrossPay() = 0;

	double calculateTaxAmount()
	{
		taxRate = 0.30;
		taxAmount = grossPay*taxRate;
        	return taxAmount;
	}

	double calculateNetPay()
	{
		netPay = grossPay - taxAmount;
		return netPay;
	}

	void printData()
	{
		cout<<setprecision(2)<<setiosflags(ios::fixed | ios::showpoint);
		cout<<setw(12)<<firstName<<setw(12)<<lastName<<setw(12)<<employeeID<<setw(12)<<hours<<setw(12)<<otHours<<setw(12)<<grossPay<<setw(12)<<netPay<<setw(12)<<otPay<< endl;
		outfile<<setprecision(2)<<setiosflags(ios::fixed | ios::showpoint);
		outfile<<setw(12)<<firstName<<setw(12)<<lastName<<setw(12)<<employeeID<<setw(12)<<hours<<setw(12)<<otHours<<setw(12)<<grossPay<<setw(12)<<netPay<<setw(12)<<otPay<< endl;
	}
};

class employeeSalary : public employee
{
	public:
		double calculateGrossPay()
		{
			double hourlyRate = (salary/40);
			double regPay = hours*hourlyRate;
        		if (hours > 40)
        		{
				otHours = (hours - 40);
				otPay = (otHours * hourlyRate);
				grossPay = (regPay + otPay);
			}
			else
			{
				if(hours <= 40)
				{
            				otHours = 0; otPay = 0; grossPay = regPay;
        			}
			}
			return grossPay;
		}
};

class employeeHourly : public employee
{
	public:
			double calculateGrossPay()
			{
				const double regPay = (40 * hourlyRate);
				if ( hours > 40 )
				{
					otHours = (hours - 40);
					otPay = (otHours * hourlyRate * 1.5);
					grossPay = (regPay + otPay);
				}
				else
				{
					otHours = 0;
					otPay = 0;
					grossPay = regPay;
				}

				return grossPay;
			}
};

int main()
{
	int employeeCounter = 0;
	int totalEmployeeCount = 0;
	outfile.open("Output.dat", ios::out | ios::trunc );

	string fName, lName;
	int empID = 0, stat = 0, rate = 0, hrs = 0;

	cout << "Enter the number of employees you want to process:  ";
	cin >> totalEmployeeCount;

	employee* employee[100];

	while( employeeCounter < totalEmployeeCount )
	{
		cout<<"Is employee "<< employeeCounter+1 << " hourly or salary? (Enter 1 for hourly / 2 for salary):";
		cin>>stat;

		if(stat == 1)
		{
			cout << "\nHOURLY employee:-"<<endl;
			cout<<"Enter employee's ID: ";
			cin>>empID;
			cout<<"Enter employee's first name: ";
			cin>>fName;
			cout<<"Enter employee's last name: ";
			cin>>lName;
			cout<<"Enter employee's hourly wage: ";
			cin>>rate;
			cout<<"Enter employee's hours for this week: ";
			cin>>hrs;

			employee[employeeCounter] = new employeeHourly();
			employee[employeeCounter]->setVariables( empID, fName, lName, stat, rate, hrs );
			employee[employeeCounter]->calculateGrossPay();
			employee[employeeCounter]->calculateTaxAmount();
			employee[employeeCounter]->calculateNetPay();
			cout<<endl<<endl;
			employeeCounter++;
		}
		else
		{
			cout<<"\nSALARY employee:-\n";
			cout<<"Enter employee's ID: ";
			cin>>empID;
			cout<<"Enter employee's first name: ";
			cin>>fName;
			cout<<"Enter employee's last name: ";
			cin>>lName;
			cout<<"Enter employee's hourly wage: ";
			cin>>rate;
			cout<<"Enter employee's hours for this week: ";
			cin>>hrs;
			employee[employeeCounter] = new employeeSalary();
			employee[employeeCounter]->setVariables(empID, fName, lName, stat, rate, hrs );
			employee[employeeCounter]->calculateGrossPay();
			employee[employeeCounter]->calculateTaxAmount();
			employee[employeeCounter]->calculateNetPay();
			cout<<endl<<endl;
			employeeCounter++;
		}
	}

	cout<<"------------------------------------------------------------------------------------------------------\n";
	outfile<<"------------------------------------------------------------------------------------------------------\n";
	cout<<"  First Name   Last Name      Emp ID       Hours Overtime(hrs)   Gross Pay   Net Pay   Overtime Pay\n";
	outfile<<"  First Name   Last Name      Emp ID       Hours Overtime(hrs)   Gross Pay   Net Pay   Overtime Pay\n";
	cout<<"------------------------------------------------------------------------------------------------------\n";
	outfile<<"------------------------------------------------------------------------------------------------------\n";
	for(int i=0;i<employeeCounter;++i)
	{
		employee[i]->printData();
	}
	cout<<"------------------------------------------------------------------------------------------------------\n";
	outfile<<"------------------------------------------------------------------------------------------------------\n";
	outfile.close();
	return 0;
}
