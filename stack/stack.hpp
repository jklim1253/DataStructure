#pragma once

#pragma comment(lib, "../lib/common.lib")
#include "../common/Link.hpp"

namespace jklim {

template<typename E>
class stackADT {
private:
	void operator = (const stackADT&) {}
	stackADT(const stackADT&) {}
public:
	stackADT() {}
	virtual ~stackADT() {}

	virtual void clear() = 0;
	virtual void push(const E& it) = 0;
	virtual E pop() = 0;
	virtual const E& top() const = 0;
	virtual int length() const = 0;
	virtual bool empty() const = 0;
};

template<typename E>
class stack : public stackADT<E> {
private :
	typedef SingleLink<E> LinkType;
	LinkType* head;
	int size;
public :
	stack() {
		head = nullptr;
		size = 0;
	}
	~stack() {
		clear();
	}

	void clear() {
		while (head != nullptr) {
			LinkType* tmp = head;
			head = head->next();
			delete tmp;
		}
		size = 0;
	}
	void push(const E& it) {
		head = new LinkType(it, head);
		++size;
	}
	E pop() {
		E it = head->value();
		LinkType* tmp = head->next();
		delete head;
		head = tmp;
		--size;
		return it;
	}
	const E& top() const {
		return head->value();
	}
	int length() const {
		return size;
	}
	bool empty() const {
		return (size == 0);
	}
};

} // namespace jklim

#ifdef STACK_EXPORTS
#define DEMOAPI __declspec(dllexport)
#else
#define DEMOAPI __declspec(dllimport)
#endif // STACK_EXPORTS

Version DEMOAPI GetVersionStack();

void DEMOAPI stack_demo();
void DEMOAPI stack_recursion();
void DEMOAPI stack_plus();
void DEMOAPI stack_multiply();