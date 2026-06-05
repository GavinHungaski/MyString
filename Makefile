COMPILE = g++
COMPILE_FLAGS = -Wall -Wextra -std=c++20

all: app.exe

MyString.o: MyString.cpp MyString.hpp
	$(COMPILE) $(COMPILE_FLAGS) -c MyString.cpp

test.o: test.cpp MyString.hpp
	$(COMPILE) $(COMPILE_FLAGS) -c test.cpp

main.o: main.cpp test.hpp
	$(COMPILE) $(COMPILE_FLAGS) -c main.cpp

app.exe: main.o MyString.o test.o
	$(COMPILE) $(COMPILE_FLAGS) main.o MyString.o test.o -o app.exe

clean:
	rm -f *.o app.exe