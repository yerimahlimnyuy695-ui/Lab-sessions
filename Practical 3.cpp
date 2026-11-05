#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	double a,b;
	
	cout<< "Enter two numbers:";
	cin>>a>>b;
	
	cout<<"Sum = "<< a+b << endl;
	cout<<"Difference =" << a-b << endl;
	cout<<"Product =" << a*b << endl;
	
	if (b!=0){
		cout << "Quotient =" << a/b << endl;
	}
	else{
		cout << "Division by zer0 is not allowed."<< endl;
	}
	
	int x,y;
	
	cout<<"\nEnter two integers:";
	cin>> x>>y;
	
	if (y!=0){
		cout<<"Remainder="<<x%y<<endl;
	}
	else{
		cout<<"Cannot calculate remainder by zero."<<endl;
	}
	
	cout<<"\nSquare root of first number="<<sqrt(a)<<endl;
	cout<<"Power="<<pow(a,b)<<endl;
	cout<<"Minimum="<<min(a,b)<<endl;
	cout<<"Maximum="<<max(a,b)<<endl;
	
	double radius;
	cout<<"\nEnter radius of circle";
	cin>>radius;
	
	double area=3.14159*radius*radius;
	cout<<"Area of circle="<<area<<endl;
	
	return 0;
}


