DEBUG_FLAGS=-g -ggdb #-fsanitize=undefined -fsanitize=shift -fsanitize=integer-divide-by-zero -fsanitize=unreachable -fsanitize=vla-bound -fsanitize=null -fsanitize=return -fsanitize=signed-integer-overflow -static-libubsan

# Note: g++ and mingw g++ are supposed to be GCC 4.9.2-x at least.
CPP=g++ --std=c++14  #-static-libstdc++
CPP_LIBS=-lpthread  
MINGCPP=i686-w64-mingw32-g++ --std=c++14

all:	ex ex-auto ex-variadic

ex:	ex.cpp
	$(CPP) $(DEBUG_FLAGS) $< -o $@ $(CPP_LIBS)

ex-auto:	ex-auto.cpp
	$(CPP) $(DEBUG_FLAGS) $< -o $@ $(CPP_LIBS)

ex-variadic:	ex-variadic.cpp
	$(CPP) $(DEBUG_FLAGS) $< -o $@ $(CPP_LIBS)

#$(MINGCPP) $(DEBUG_FLAGS) $< -o $@.mingw $(CPP_LIBS)

clean:
	rm -f *.executable

