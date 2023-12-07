//neha maam
//written by vinayak

//Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given conditions: 
//1. Operands and operator, both must be single character. 
//2. Input Postfix expression must be in a desired format. 
//3. Only '+', '-', '*' and '/ ' operators are expected.

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int prec(char c)
{
	if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

string in_post(string infix)
{
	stack<char> obj;
	string post;

	for (int i = 0; i < infix.length(); i++) {
		char c = infix[i];

		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'))
			post += c;

		else if (c == '(')
			obj.push('(');

		else if (c == ')') {
			while (obj.top() != '(') {
				post += obj.top();
				obj.pop();
			}
			obj.pop();
		}

		else {
			while (!obj.empty() && (prec(infix[i]) <= prec(obj.top()))) {
				post += obj.top();
				obj.pop();
			}
			obj.push(c);
		}
	}
	while (!obj.empty()) {
		post += obj.top();
		obj.pop();
	}
	return post;
}

int evaluate(string postfix){
    stack<int> s;

    for (int i = 0; i < postfix.length(); i++) {
        if (isdigit(postfix[i])){
            s.push(postfix[i] - '0');
        }
 
        else {
            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();
            switch (postfix[i]) {
            case '+':
                s.push(val2 + val1);
                break;
            case '-':
                s.push(val2 - val1);
                break;
            case '*':
                s.push(val2 * val1);
                break;
            case '/':
                s.push(val2 / val1);
                break;
            }
        }
    }
    return s.top();
}

int main(){
	string exp;

	cout<<"Enter the infix expression: ";
	cin>>exp;
	string postfix = in_post(exp);
	cout<<"Postfix expression is: "<<postfix<<endl;
	int result = evaluate(postfix);
	cout<<"Value of the postfix expression after evaluation is: "<<result<<endl;+

	return 0;
}

