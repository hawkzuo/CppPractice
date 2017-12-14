# compiler name
CPP = g++
# bin output flag
OFLAG = -o
# compile flag
CFLAG = -c
# C++ 11 standard flag
CPP11 = -std=c++11

all: c2 c3 c4

c2: Chapter02.o
	$(CPP) $(OFLAG) c2 Chapter02.o

c3: Chapter03.o
	$(CPP) $(OFLAG) c3 Chapter03.o

c4: Chapter04.o Stack.o
	$(CPP) $(OFLAG) c4 Chapter04.o Stack.o

Chapter02.o: Chapter02.cpp
	$(CPP) $(CFLAG) Chapter02.cpp

Chapter03.o: Chapter03.cpp
	$(CPP) $(CFLAG) Chapter03.cpp

Chapter04.o: Chapter04.cpp
	$(CPP) $(CFLAG) Chapter04.cpp

Stack.o: Stack.cpp
	$(CPP) $(CPP11) $(CFLAG) Stack.cpp


clean:
	rm *.o
	rm c2 c3 c4
