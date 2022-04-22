CXX = g++
CXXFLAGS = -std=c++17 -Wall $(INCLUDES)
INCLUDES = -I../../helpers

src = $(wildcard *.cpp) \
	  $(wildcard ../../helpers/*.cpp)
obj = $(src:.cpp=.o)

myprog: $(obj)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(obj) myprog
