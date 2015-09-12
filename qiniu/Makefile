CXX = g++

test : test.o number.o helper.o
	$(CXX) -o test test.o number.o helper.o

test.o : number.h
number.o : number.h helper.h
helper.o : helper.h

.PHONY : clean
clean :
	rm -f test *.o
