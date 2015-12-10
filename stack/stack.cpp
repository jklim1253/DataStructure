#include "stack.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace jklim;

void* operator new (std::size_t size) {
	void* p = ::malloc(size);
	std::cout << "addr " << p << " is allocated." << std::endl;
	return p;
}
void operator delete (void* p) noexcept {
	std::cout << "addr " << p << " is freed." << std::endl;
	::free(p);
}

void stack_demo() {

	std::string command;
	std::string value;
	stack<std::string> depot;

	while (std::cin >> command) {
		if (command == "push") {
			std::cin >> value;
			depot.push(value);
			std::cout << value << " is pushed." << std::endl;
		}
		else if (command == "pop") {
			std::cout << depot.pop() << " is popped." << std::endl;
		}
		else if (command == "length") {
			std::cout << "size : " << depot.length() << std::endl;
		}
		else if (command == "empty") {
			std::cout << "depot is " << (depot.empty()? "" : "not ") << "empty." << std::endl;
		}
		else if (command == "quit") {
			break;
		}
		else if (command == "top") {
			std::cout << "top is " << depot.top() << std::endl;
		}
		else {
			std::cout << "Usage : [command] \n\n"
				<< "push [value] : push specific value to stack.\n"
				<< "pop          : remove top of stack.\n"
				<< "length       : confirm length of stack.\n"
				<< "empty        : confirm whether stack is empty or not.\n"
				<< "top          : confirm top of stack.\n"
				<< "quit         : quit program.\n";
		}
	}
}

int fact(int n) {
	stack<int> depot;
	while (n > 1) depot.push(n--);

	int result = 1;
	while (!depot.empty()) {
		result *= depot.pop();
	}
	return result;
}
void stack_recursion() {
	int input;
	std::cout << "====================\n";
	std::cout << "Enter Number :>";
	std::cin >> input;
	std::cout << "factorial of " << input << " is " << fact(input) << std::endl;
	std::cout << "====================\n";
}

#include <algorithm>
std::string plus(const std::string& lhs, const std::string& rhs) {
	stack<int> depot;
	std::string::const_reverse_iterator lit = lhs.crbegin(), rit = rhs.crbegin();

	int tmp = 0, upper = 0;
	while (lit != lhs.crend() || rit != rhs.crend() || upper != 0) {
		tmp = upper;
		if (lit != lhs.crend()) {
			tmp += *lit - '0';
			++lit;
		}
		if (rit != rhs.crend()) {
			tmp += *rit - '0';
			++rit;
		}
		depot.push(tmp%10);
		upper = tmp / 10;
	}

	std::string result;
	while (!depot.empty()) {
		result.push_back(depot.pop() + '0');
	}
	return result;
}
void stack_plus() {
	std::string lho, rho;
	std::cout << "====================\n";
	std::cout << "Enter 2 Number :>";
	std::cin >> lho >> rho;
	std::cout << lho << " + " << rho << " = " << plus(lho, rho) << std::endl;
	std::cout << "====================\n";
}