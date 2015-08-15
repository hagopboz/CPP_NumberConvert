#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

#define BINARY 2
#define OCTAL 8
#define HEX 16

using namespace std;

void convertToBinary(int);
void convertToOctal(int);
void convertToHex(int);

void push(int*, int*, int);
int pop(int*, int*);

int main()
{
	int usrInput;
	do
	{
		cout << "Enter the number to convert: ";
		cin >> usrInput;
	}	while(usrInput < 0 && !isdigit(usrInput));

	cout << endl;
	convertToBinary(usrInput);
	convertToOctal(usrInput);
	convertToHex(usrInput);

	return 0;
}

void push(int *stack, int *stack_top, int rem)
{
	*(stack_top) = rem;
	//stack_top++;									//Doesn't update outside after called

	return;
}

int pop(int *stack, int *stack_top)
{
	return *stack_top;
}

void convertToBinary(const int usrInput)
{
	int rem = 0;
	int quotient = usrInput;
	int *stack = new int[100];
	int *stack_top = stack;
	string output = "";
	
	do
	{
		rem = quotient % BINARY;
		quotient /= BINARY;

		push(stack, stack_top, rem);
		stack_top++;					//Move stack_top pointer
	}	while(quotient >= BINARY);

	push(stack, stack_top, quotient);	//Push remaining element to stack

	while(stack_top != stack - 1)
	{
		if(pop(stack, stack_top) == 0)
			output += "0";
		else
			output += "1";
		stack_top--;
	}

	delete [] stack;			//stack_top is released to OS in the process
	//delete stack_top;
	stack = NULL;
	stack_top = NULL;

	cout << usrInput << " converted to Binary: " << output << endl;
	return;
}


void convertToOctal(const int usrInput)
 {
	int rem = 0;
	int quotient = usrInput;
	int *stack = new int[100];
	int *stack_top = stack;
	string output = "";
	
	do
	{
		rem = quotient % OCTAL;
		quotient /= OCTAL;

		push(stack, stack_top, rem);
		stack_top++;					//Move stack_top pointer
	}	while(quotient >= OCTAL);

	push(stack, stack_top, quotient);	//Push remaining element to stack

	while(stack_top != stack - 1)
	{
		int num = pop(stack, stack_top);
		switch(num)
		{
		case 0:
			output += "0";
			break;
		case 1:
			output += "1";
			break;
		case 2:
			output += "2";
			break;
		case 3:
			output += "3";
			break;
		case 4:
			output += "4";
			break;
		case 5:
			output += "5";
			break;
		case 6:
			output += "6";
			break;
		case 7:
			output += "7";
			break;
		default:
			cout << "Error converting to Octal.";
			system("exit");
		}
		stack_top--;
	}

	delete [] stack;			//stack_top is released to OS in the process
	//delete stack_top;
	stack = NULL;
	stack_top = NULL;

	cout << usrInput << " converted to Octal: " << output << endl;
	return;
}



void convertToHex(const int usrInput)
 {
	int rem = 0;
	int quotient = usrInput;
	int *stack = new int[100];
	int *stack_top = stack;
	string output = "";
	
	do
	{
		rem = quotient % HEX;
		quotient /= HEX;

		push(stack, stack_top, rem);
		stack_top++;					//Move stack_top pointer
	}	while(quotient >= HEX);

	push(stack, stack_top, quotient);	//Push remaining element to stack

	while(stack_top != stack - 1)
	{
		int num = pop(stack, stack_top);
		switch(num)
		{
		case 0:
			output += "0";
			break;
		case 1:
			output += "1";
			break;
		case 2:
			output += "2";
			break;
		case 3:
			output += "3";
			break;
		case 4:
			output += "4";
			break;
		case 5:
			output += "5";
			break;
		case 6:
			output += "6";
			break;
		case 7:
			output += "7";
			break;
		case 8:
			output += "8";
			break;
		case 9:
			output += "9";
			break;
		case 10:
			output += "A";
			break;
		case 11:
			output += "B";
			break;
		case 12:
			output += "C";
			break;
		case 13:
			output += "D";
			break;
		case 14:
			output += "E";
			break;
		case 15:
			output += "F";
			break;
		default:
			cout << "Error converting to Hex.";
			system("exit");
		}
		stack_top--;
	}

	delete [] stack;			//stack_top is released to OS in the process
	//delete stack_top;
	stack = NULL;
	stack_top = NULL;

	cout << usrInput << " converted to Hexadecimal: 0x" << output << endl;
	return;
}