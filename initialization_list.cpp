#include <iostream>

class Data {
public:
	Data() {
		std::cout << "This is constructor\n";
	}

	// copy constructor
	Data(const Data& data) {
		std::cout << "This is copy constructor\n";
	}

	// copy assignment
	Data& operator=(const Data&) {
		std::cout << "This is copy assignment\n";
		return *this;
	}
};

class Test1 {
public:
	// initialize an Data object without parameter -> Data's constructor
	Test1(Data data) {
		// Data copy assignment
		m_data = data;
	}

private:
	Data m_data;
};

class Test2 {
public:
	Test2(Data data)
		// initialize an Data object with an input object -> Data's copy constructor
		: m_data(data) {}

private:
	Data m_data;
};

class Test3 {
public:
	Test3(Data &data)
		// initialize an Data object with an input object -> Data's copy constructor
		: m_data(data) {}

private:
	Data m_data;
};

int main () {
	Data data;
	std::cout << "\n";

	// call by value -> Data's copy constructor is called
	Test1 test1(data);
	std::cout << "\n";

	// call by value -> Data's copy constructor is called
	Test2 test2(data);
	std::cout << "\n";

	// call by reference -> Data's copy constructor is not called
	Test3 test3(data);

	return 0;
}