// Build and execute like this: g++ --std=c++14 exvariadic.cpp && ./a.exe
//                              i686-w64-mingw32-g++ --std=c++14 exvariadic.cpp  && ./a.exe
// This code is copied over from C++ journal: http://accu.org/index.php/journals/2087
#include <iostream>
#include <utility>

// base case overload
void println(std::ostream &out){
  out <<'\n';
}
// variadic template
template <typename HEAD, typename ... T>
void println(std::ostream & out,HEAD const &h, T const & ... tail){
  out << h; // cut off head
  if (sizeof...(tail)){
    out <<", ";
  }
  println(out,tail...); // recurse on tail...
}

// ---------------


// ---------------

int main(int argNum, char** args) {
	println(std::cout, "blah", "foo", "bar");

	return 0;
}
