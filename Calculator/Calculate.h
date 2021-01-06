#pragma once
#include <cmath>
#include <stack>
#include <string>
#include <stdexcept>

using std::stack;
using std::string;

extern double calculate(string express);

inline size_t priority(const char op)
{
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/' || op == '%')
		return 2;
	if (op == '^')
		return 3;
	throw std::runtime_error{ string{"Invalid Operator: "} +op };
}

double calculating(double a, char op, double b)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	case '%':
		return int(a) % int(b);
	case '^':
		return pow(a, b);
	default:
		throw std::runtime_error{ string{"Invalid Operator: "} +op };
	}
}

void execute(std::stack<char>& ops, std::stack<double>& operands)
{
	double rhs{ operands.top() };
	operands.pop();
	double lhs{ operands.top() };
	operands.pop();

	double result = calculating(lhs, ops.top(), rhs);

	ops.pop();
	operands.push(result);
}

void push_operands(stack<double>& operands, string sub_express, size_t& index, size_t& i) {
	if (sub_express[0] == 's') {
		size_t split = sub_express.find(')');
		operands.push(sqrt(calculate(sub_express.substr(4, split - 4))));
		index += (split + 1);
	}
	else if (sub_express[0] == '(') {
		size_t split = sub_express.rfind(')');
		operands.push(calculate(sub_express.substr(1, split - 1)));
		index += (split + 1);
	}
	else if (index == 0 && (sub_express[0] == '-' || sub_express[0] == '+')) {
		operands.push(calculate('0' + sub_express));
		index += sub_express.length();
	}
	else {
		operands.push(std::stod(sub_express, &i));
		index += i;
	}
}

void pre_operate(string& exp) {
	size_t split = exp.find('s');
	if (split > 0 && split < exp.length() && !(exp[split - 1] > '9' || exp[split - 1] < '0'))
		exp = exp.substr(0, split) + "*" + exp.substr(split);
	split = exp.find('(');
	if (split > 0 && split < exp.length() && !(exp[split - 1] > '9' || exp[split - 1] < '0'))
		exp = exp.substr(0, split) + "*" + exp.substr(split);
}

extern double calculate(string express) {
	stack<double>operands;
	stack<char>operators;

	pre_operate(express);
	
	size_t index = 0, i = 0;
	push_operands(operands, express.substr(index), index, i);
	while (index < express.length())
	{
		operators.push(express[index++]);
		push_operands(operands, express.substr(index), index, i);
		if (index == express.length())
		{
			while (!operators.empty())
				execute(operators, operands);
			break;
		}
		while (!operators.empty() && priority(express[index]) <= priority(operators.top()))
			execute(operators, operands);
	}

	return operands.top();
}