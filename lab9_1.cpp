#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;
double interest(double a,double b)
{
	return (a/100)*b;
}
double total(double a,double interest)
{
	return a+interest;
}
double newb(double total,double pay)
{
	int i=0;
	if(pay>total)
	{
		return i;
	}
	return total-pay;
}
double payment(double total,double pay)
{
	if(pay>total)
	{
		return total;
	}
	return pay;
}
void show(int i,double a,double interest,double total,double c,double newb)
{
	cout << fixed << setprecision(2);
	cout << setw(13) << left << i; 
	cout << setw(13) << left << a;
	cout << setw(13) << left << interest;
	cout << setw(13) << left << total;
	cout << setw(13) << left << c;
	cout << setw(13) << left << newb;
	cout << "\n";	
}
int main(){	
	double a,b,pay;
	cout << "Enter initial loan: ";
	cin>>a;
	cout << "Enter interest rate per year (%): ";
	cin>>b;
	cout << "Enter amount you can pay per year: ";
	cin>>pay;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	int i=1;
	while(total(a,interest(a,b))>pay)
	{
		if(total(a,interest(a,b))>=pay)
		{
			show(i,a,interest(a,b),total(a,interest(a,b)),payment(pay,total(a,interest(a,b))),newb(total(a,interest(a,b)),pay));
			a=newb(total(a,interest(a,b)),pay);
			i++;
		}
	}
	show(i,a,interest(a,b),total(a,interest(a,b)),payment(pay,total(a,interest(a,b))),newb(total(a,interest(a,b)),pay));
	
	return 0;
}
