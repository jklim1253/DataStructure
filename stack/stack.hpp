#pragma once

namespace jklim {

template<typename E>
class LinkADT {
private :
	void operator = (const LinkADT&) {}
	LinkADT(const LinkADT&) {}
public :
	LinkADT(const E& v = E()) : _value(v) {}
	virtual ~LinkADT() {}

	inline E& value() { return _value; }
protected :
	E _value;
};

template<typename E>
class SingleLink : public LinkADT<E> {
private :
	typedef SingleLink* LinkPointer;
	LinkPointer _next;
public :
	SingleLink() : LinkADT(), _next(nullptr) {}
	SingleLink(const E& v, const LinkPointer& n = nullptr) : LinkADT(v), _next(n) {}
	~SingleLink() {}

	const LinkPointer next() const { return _next; }
	LinkPointer& next() { return _next; }
};

template<typename E>
class DoubleLink : public LinkADT<E> {
private :
	typedef DoubleLink* LinkPointer;
	LinkPointer _next;
	LinkPointer _prev;
public :
	DoubleLink() : LinkADT(), _next(nullptr), _prev(nullptr) {}
	DoubleLink(const E& v, const LinkPointer& n = nullptr, const LinkPointer& p = nullptr)
		: LinkADT(v), _next(n), _prev(p) {}
	~DoubleLink() {}

	const LinkPointer next() const { return _next; }
	LinkPointer& next() { return _next; }
	const LinkPointer prev() const { return _prev; }
	LinkPointer& prev() { return _prev; }
};

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