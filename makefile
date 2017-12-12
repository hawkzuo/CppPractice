CPP = g++
OFLAG = -o

all: c2 c3

c2: Chapter02.o
	$(CPP) $(OFLAG) c2 Chapter02.o

c3: Chapter03.o
	$(CPP) $(OFLAG) c3 Chapter03.o

Chapter02.o: Chapter02.cpp
	$(CPP) -c Chapter02.cpp

Chapter03.o: Chapter03.cpp
	$(CPP) -c Chapter03.cpp

clean:
	rm *.o
	rm c2
	rm c3