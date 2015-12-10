#include "../stack/stack.hpp"
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

int main() {

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
	
	return 0;
}