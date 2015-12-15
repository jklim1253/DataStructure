#pragma comment(lib, "../lib/stack.lib")
#include "../stack/stack.hpp"
#pragma comment(lib, "../lib/queue.lib")
#include "../queue/queue.hpp"
#include "MainApplication.hpp"

struct StackDemo : public Function {
	void operator ()() {
		stack_demo();

		stack_recursion();

		stack_plus();

		stack_multiply();
	}
};
struct QueueDemo : public Function {
	void operator ()() {

	}
};
struct Demo : public Function {
	void operator ()() {
		StackDemo()();
		QueueDemo()();
	}
};
int main() {

	Get(MainApplication).run(Demo());

	
	return 0;
}