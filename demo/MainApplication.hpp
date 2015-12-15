#pragma once

template<typename Class>
class singleton {
protected :
	singleton() {}
	virtual ~singleton() {}
public :
	static Class& GetReference() {
		static Class instance;
		return instance;
	}
};
#define Get(Cls) Cls::GetReference()

struct Function {
	virtual void operator ()() = 0;
};

class MainApplication : public singleton<MainApplication> {
	friend class singleton<MainApplication>;
private :
	MainApplication() {}
	~MainApplication() {}
public :
	void initialize() {

	}
	void menu() {

	}
	void run() {

	}
	void run(Function& f) {
		f();
	}
};