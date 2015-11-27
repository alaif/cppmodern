#include "ex.h"

// base case overload
void println(std::ostream &out){
  out <<'\n';
}

int foo(int a, const char* b) { return -1; }

// -------------------------------

// a non-optimized way of checking for prime numbers:
bool is_prime (unsigned long x) {
  for (unsigned long i=2; i<x; ++i) if (x%i==0) return false;
  return true;
}

const unsigned long NUMBER =  444444443L ; // computation takes ~5sec
//const unsigned long long int NUMBER =  2147483647L; // computation takes ~long time ;)

int no_future() {
  // call function asynchronously:
  std::packaged_task<bool(unsigned long)> ptask(is_prime);
  std::future<bool> fut = ptask.get_future(); 
  std::thread(std::move(ptask), NUMBER).detach();

  // do something while waiting for function to set future:
  std::cout << "checking, please wait";
  std::chrono::milliseconds span (250);
  while (fut.wait_for(span)==std::future_status::timeout)
    std::cout << '.' << std::flush;

  bool x = fut.get();     // retrieve return value

  std::cout << "\n" << NUMBER << ' ' << (x?"is":"is not") << " prime.\n";
}

// -------------------------------

int main(int argCount, char** main) {
	println(std::cout, "omgomg", "boom","foo");

	std::function<int(int, const char *)> func = foo;
	auto r = func(1, "b");
	println(std::cout, "result:", r, "blah", 3.14, "&foo:", &foo, "&func:", &func);
	
	no_future();

	return 0;
}
