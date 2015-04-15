#include <iostream> 
#include <cmath> 
#include <string>
const int MAX_SIZE = 100;
const double PI = 3.14159265358979;

using namespace std;

class Stack 
{    
private:        
	double array[MAX_SIZE];        
	int peak;    
public:        
	Stack();
	void push(double element);
	double pop();
	double top();
	double size();
	bool isEmpty();
};
Stack::Stack() 
{            
	peak = -1;        
}        

void Stack::push(double element)
{            
	if (peak >= MAX_SIZE ) 
	{            
		cout << "Stack is full" << endl;
		return;
	}                   
	array[++peak] = element;
}        

double Stack::pop()
{            
	if ( peak == -1 ) 
	{            
		cout << "Stack is empty" << endl;
		return 1;            
	}            
	return array[peak--];        
}        

double Stack::top() 
{            
	return array[peak];        
}

double Stack::size() 
{
	return peak + 1;
}

bool Stack::isEmpty() 
{
	if (peak == -1) 
	{
		return true;
	}
	return false;
}


class Calculator
{ 
public: 
	double* returnValue(Stack& stk);
	void add(Stack& stk); 
	void sub(Stack& stk);
	void multi(Stack& stk);
	void devide(Stack& stk);
	void sin2(Stack& stk);
	void cos2(Stack& stk);
	void exp2(Stack& stk);
	void log2(Stack& stk);
	void sqrt2(Stack& stk);
	void asin2(Stack& stk);
	void acos2(Stack& stk);
	void tan2(Stack& stk);
	void atan2(Stack& stk);
	void mod(Stack& stk);
}; 

double* Calculator::returnValue(Stack& stk)
{
	double* temp = new double[2];
	if (stk.size() == 1)
	{
		temp[0] = stk.pop();
		temp[1] = temp[0];
	}
	else
	{
		temp[0] = stk.pop();
		temp[1] = stk.pop();
	}
	return temp;
}
void Calculator::add(Stack& stk)
{
	double* temp = returnValue(stk);
	double rValue = temp[1];
	double lValue = temp[0];
	stk.push(lValue + rValue);
	cout << stk.top() << endl;
} 
void Calculator::sub(Stack& stk)
{
	if (stk.size() == 1)
	{
		cout<<"Please enter one more value !" <<endl;
	}
	else
	{
		double rValue = stk.pop();
		double lValue = stk.pop();
		stk.push(lValue - rValue);
		cout << stk.top() << endl;
	}
} 
void Calculator::multi(Stack& stk)
{
	if (stk.size() == 1)
	{
		double value = stk.pop();
		stk.push(value * value);
		cout << stk.top() << endl;
	}
	else
	{
		double rValue = stk.pop();
		double lValue = stk.pop();
		stk.push(lValue * rValue); 
		cout << stk.top() << endl;
	}

}
void Calculator::devide(Stack& stk)
{
	if (stk.size() == 1)
	{
		cout<<"Please enter one more value !" <<endl;
	}
	else
	{
		double rValue = stk.pop();
		double lValue = stk.pop();
		if (rValue == 0)
		{
			cout<<"Division by zero !"<<endl;
		}
		else
		{
			stk.push(lValue / rValue); 
			cout << stk.top() << endl;
		}
	}
}
void Calculator::sin2(Stack& stk)
{
	cout << "Radians or Degrees ?" << endl;
	string input;
	cin >> input;
	if (input == "radians" || input == "rad" || input == "r" || input == "Radians")
	{
		double value = stk.pop();
		double result = sin(value);
		stk.push(result);
		cout << stk.top() << endl;
	}
	else 
	{
		double value = stk.pop();
		double result = sin(value * (PI/180));
		stk.push(result);
		cout << stk.top() << endl;
	}
} 
void Calculator::cos2(Stack& stk)
{ 
	cout << "Radians or Degrees ?" << endl;
	string input;
	cin >> input;
	if (input == "radians" || input == "rad" || input == "r" || input == "Radians")
	{
		double value = stk.pop();
		double result = cos(value);
		stk.push(result);
		cout << stk.top() << endl;
	}
	else 
	{
		double value = stk.pop();
		double result = cos(value * (PI/180));
		stk.push(result);
		cout << stk.top() << endl;
	}
} 
void Calculator::exp2(Stack& stk)
{ 
	double rValue = stk.pop();
	double lValue = stk.pop();
	stk.push(pow(lValue, rValue)); 
	cout << stk.top() << endl;
} 
void Calculator::log2(Stack& stk)
{ 
	double value = stk.pop();
	stk.push(log(value));
	cout << stk.top() << endl;
} 
void Calculator::sqrt2(Stack& stk)
{ 
	double value = stk.pop();
	stk.push(sqrt(value));
	cout << stk.top() << endl;
} 
void Calculator::asin2(Stack& stk)
{ 
	double value = stk.pop();
	stk.push(asin(value));
	cout << stk.top() << endl;
} 
void Calculator::acos2(Stack& stk)
{ 
	double value = stk.pop();
	stk.push(acos(value));
	cout << stk.top() << endl;
} 
void Calculator::tan2(Stack& stk)
{ 
	cout << "Radians or Degrees ?" << endl;
	string input;
	cin >> input;
	if (input == "radians" || input == "rad" || input == "r" || input == "Radians")
	{
		double value = stk.pop();
		double result = tan(value);
		stk.push(result);
		cout << stk.top() << endl;
	}
	else 
	{
		double value = stk.pop();
		double result = tan(value * (PI/180));
		stk.push(result);
		cout << stk.top() << endl;
	}
} 
void Calculator::atan2(Stack& stk)
{ 
	double value = stk.pop();
	stk.push(atan(value));
	cout << stk.top() << endl;
} 
void Calculator::mod(Stack& stk)
{
	int rValue = stk.pop();
	int lValue = stk.pop();
	stk.push(lValue % rValue); 
	cout << stk.top() << endl;
}

double toDegrees(const double rad) 
{ 
	return rad * 180.0 / PI; 
}

bool isNumber(string input) 
{
	if (input == "0")
	{
		return true;
	}
	return (atof(input.c_str())); 
}

bool isOperator (const string& input)
{
	string operators[] = {"+", "-", "*", "/", "sin", "cos", "exp", "log", "sqrt", "asin", "acos", "tan", "atan", "mod"};
	for (int i = 0; i < 14; i++)
	{
		if (input == operators[i])
		{
			return true;
		}
	}
	return false;
}

bool isSpecial (const string& input)
{
	string special[] = {"pop", "clear", "=", "show", "help", "quit", "cls"};
	for (int i = 0; i < 7; i++)
	{
		if (input == special[i])
		{
			return true;
		}
	}
	return false;
}

void performOp (const string& input, Stack& stk)
{
	if (stk.isEmpty())
	{
		cout<<"Stack is empty !" << endl;
	}
	else
	{
		Calculator calc;
		if (input == "+")
		{
			calc.add(stk);
		}
		else if (input == "-")
		{
			calc.sub(stk);
		}
		else if (input == "*")
		{
			calc.multi(stk);
		}
		else if (input == "/")
		{
			calc.devide(stk);
		}
		else if (input == "sin")
		{
			calc.sin2(stk);
		}
		else if (input == "cos")
		{
			calc.cos2(stk);
		}
		else if (input == "exp")
		{
			calc.exp2(stk);
		}
		else if (input == "log")
		{
			calc.log2(stk);
		}
		else if (input == "sqrt")
		{
			calc.sqrt2(stk);
		}
		else if (input == "asin")
		{
			calc.asin2(stk);
		}
		else if (input == "acos")
		{
			calc.acos2(stk);
		}
		else if (input == "tan")
		{
			calc.tan2(stk);
		}
		else if (input == "atan")
		{
			calc.atan2(stk);
		}
		else if (input == "mod")
		{
			calc.mod(stk);
		}
	}
}

void performSpecial (const string& input, Stack& stk)
{
	if(input == "=")
	{
		cout << stk.top() << endl;
	}
	else if(input == "help")
	{
		system("CLS");
		cout << "Stack Calculator help documentation" << endl << endl;

		cout << "Integrated funtions:" << endl << endl;
		cout << "1) The \"+\" function returns the sum of two objects." << endl;
		cout << "2) The \"-\" function returns the difference of two objects." << endl;
		cout << "3) The \"*\" function returns the product of two objects." << endl;
		cout << "4) The \"/\" function returns the quotient of two objects." << endl;
		cout << "5) The \"sin\" function returns the sine of an object" << endl;
		cout << "6) The \"cos\" function returns the cosine of an object" << endl;
		cout << "7) The \"exp\" function  returns the object in the second position raised to the power of the object in the first position." << endl;
		cout << "8) The \"log\" function returns the base 10 logarithm of a number." << endl;
		cout << "9) The \"sqrt\" returns the square root of an object." << endl;
		cout << "10) The \"asin\" returns the arc sine of a number." << endl;
		cout << "11) The \"acos\" returns the arc cosine of a number." << endl;
		cout << "12) The \"tan\" function returns the tangent of an object." << endl;
		cout << "13) The \"atan\" function returns the arc tangent of a number." << endl;
		cout << "14) The \"mod\" function returns the modulo of two real numbers." << endl << endl;

		cout << "Special words:" << endl << endl;
		cout << "\"pop\" deletes the element on the top." << endl;
		cout << "\"clear\" deletes the whole stack." << endl;
		cout << "\"=\" prints the top of the stack." << endl;
		cout << "\"show\" prints the stack and destroys it." << endl << endl;

		cout << "Type \"cls\" to clear the screen." << endl;
		cout << "Type \"(q)uit\" to exit the program." << endl << endl;
	}
	else if(input == "clear")
	{
		while (!stk.isEmpty())
		{
			stk.pop();
		}
	}
	else if(input == "show")
	{
		if(stk.isEmpty())
		{
			cout << "Stack is empty" << endl;
		}
		while(!stk.isEmpty())
		{
			double temp = stk.top();
			cout << temp << endl;
			stk.pop();
		}
	}
	else if(input == "pop")
	{
		stk.pop();
	}
	else if(input == "cls")
	{
		system("CLS");
	}
}

int main()
{
	cout <<"--------------------------------Stack Calculator--------------------------------\n";

	Stack stk;
	string input;
	bool exit = false;

	while (!exit)
	{
		cout << ">>";
		cin >> input;
		if(input == "quit" || input == "q")
		{
			exit = true;
		}
		else if (isNumber (input))
		{
			if (input == "0")
			{
				stk.push(0);
			}
			else
			{
				double num = atof(input.c_str());
				stk.push(num);
			}
		}
		else if(isOperator (input))
		{
			performOp(input, stk);
		}
		else if(isSpecial (input))
		{
			performSpecial(input, stk);
		}
		else
		{
			cout << "Invalid input !" << endl;
		}
	}
}


