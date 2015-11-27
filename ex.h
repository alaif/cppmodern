#ifndef _EX_H_
#define _EX_H_

#include <iostream>
#include <functional>
#include <future>
#include <chrono>
#include <utility>
#include <thread>


// base case overload
void println(std::ostream &out);

// variadic template
template <typename HEAD, typename ... T>
void println(std::ostream & out,HEAD const &h, T const & ... tail){
  out << h; // cut off head
  if (sizeof...(tail)){
    out <<", ";
  }
  println(out,tail...); // recurse on tail...
}

// -------------------------------

bool is_prime (unsigned long x);
int no_future();

#endif
