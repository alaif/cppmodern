DEBUG_FLAGS=-g -ggdb -fsanitize=undefined -fsanitize=shift -fsanitize=integer-divide-by-zero -fsanitize=unreachable -fsanitize=vla-bound -fsanitize=null -fsanitize=return -fsanitize=signed-integer-overflow
CPP=g++-4.9 --std=c++14  #-static-libstdc++
CPP_LIBS=-lpthread
MINGCPP=i686-w64-mingw32-g++ --std=c++14

files=ex.executable

$(filter %.executable,$(files)):	%.executable: %.cpp
	$(CPP) $(DEBUG_FLAGS) $< -o $@ $(CPP_LIBS)
#$(MINGCPP) $(DEBUG_FLAGS) $< -o $@.mingw $(CPP_LIBS)

clean:	%.executable
	rm -f $<

