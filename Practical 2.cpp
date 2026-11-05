#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main(){
	string name, dept;
	int age, id;
	double fee;
	bool paid;
	
	cout<<"Enter ID, Age, Fee, Paid(1/0):";
	cin>>id>>age>>fee>>paid;
	
	cin.ignore();
	cout<<"Enter Full Name:";
	getline(cin, name);
	cout<<"Enter department:";
	getline(cin,dept);
	
	cout<<"\n ---RECEIPT ---\n"<<"ID:"<<id<<"\nName:"<<name
	<<"\nAge:"<<age<<"\nDept:"<<dept<<fixed<<setprecision(2)
	<<"\nFee: $" <<fee<<"\npaid:"<<(paid ? "Yes" : "No")<<"\n";
	return 0;
}
