// Build and execute like this: g++ --std=c++14 ex.cpp && ./a.exe
#include <iostream>

auto incr(auto x) { return ++x; }

int main(int argNum, char** args) {
	std::cout << "func result=" << incr(42) << "\n";

	int a = 0b101010;
	std::cout << "func result=" << incr(a) << "\n";

	return 0;
}
