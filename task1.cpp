#include<iostream>
using namespace std;

void add();
void sub();
void mul();
void div();
int main()
{
	char op;
	cout<<"WELCOME TO THE CALCULATOR\n";
	cout<<"available operations\n ";
	cout<<"+ ADDITION\n";
	cout<<"- SUBRACTION\n";
	cout<<"* MULTIPLICATION\n";
	cout<<"/ DIVISION\n";
	cout<<"enter operation";
	cin>>op;
	
	switch(op)
	{
		case '+':
			add();
			break;
		case '-':
			sub();
			break;
		case '*':
			mul();
			break;
		case '/':
			div();
			break;
			default:
				cout<<"invalid operation please choose again";
				break;
	}
	return 0;
}
void add()
{
	double n1,n2;
	cout<<"enter two numbers";
	cin>>n1>>n2;
	cout<<"addition="<<n1+n2<<endl;
}
void sub()
{
	double n1,n2;
	cout<<"enter two numbers";
	cin>>n1>>n2;
	cout<<"subraction="<<n1-n2<<endl;
}
void mul()
{
	double n1,n2;
	cout<<"enter two numbers";
	cin>>n1>>n2;
	cout<<"multiplication="<<n1*n2<<endl;
}
void div()
{
	double n1,n2;
	cout<<"enter two numbers";
	cin>>n1>>n2;
	if (n2!=0)
	{
	cout<<"division="<<n1/n2<<endl;
    }
    else
    {
    	cout<<"division by zero not allowed";
	}
}
