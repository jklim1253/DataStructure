#pragma once

namespace jklim {

template<typename E>
class LinkADT {
private:
	void operator = (const LinkADT&) {}
	LinkADT(const LinkADT&) {}
public:
	LinkADT(const E& v = E()) : _value(v) {}
	virtual ~LinkADT() {}

	inline E& value() { return _value; }
protected:
	E _value;
};

template<typename E>
class SingleLink : public LinkADT<E> {
private:
	typedef SingleLink* LinkPointer;
	LinkPointer _next;
public:
	SingleLink() : LinkADT(), _next(nullptr) {}
	SingleLink(const E& v, const LinkPointer& n = nullptr) : LinkADT(v), _next(n) {}
	~SingleLink() {}

	const LinkPointer next() const { return _next; }
	LinkPointer& next() { return _next; }
};

template<typename E>
class DoubleLink : public LinkADT<E> {
private:
	typedef DoubleLink* LinkPointer;
	LinkPointer _next;
	LinkPointer _prev;
public:
	DoubleLink() : LinkADT(), _next(nullptr), _prev(nullptr) {}
	DoubleLink(const E& v, const LinkPointer& n = nullptr, const LinkPointer& p = nullptr)
		: LinkADT(v), _next(n), _prev(p) {}
	~DoubleLink() {}

	const LinkPointer next() const { return _next; }
	LinkPointer& next() { return _next; }
	const LinkPointer prev() const { return _prev; }
	LinkPointer& prev() { return _prev; }
};

} // namespace jklim

#ifdef COMMON_EXPORTS
#define COMMONAPI __declspec(dllexport)
#else
#define COMMONAPI __declspec(dllimport)
#endif // COMMON_EXPORT

struct COMMONAPI Version {
	unsigned int major;
	unsigned int minor;
};

Version COMMONAPI GetVersionCommon();
