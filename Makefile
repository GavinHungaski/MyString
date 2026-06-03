COMPILE = g++
COMPILE_FLAGS = -Wall -Wextra -std=c++20

all: app.exe

MyString.o: MyString.cpp MyString.hpp
	$(COMPILE) $(COMPILE_FLAGS) -c MyString.cpp

main.o: main.cpp MyString.hpp
	$(COMPILE) $(COMPILE_FLAGS) -c main.cpp

app.exe: main.o MyString.o
	$(COMPILE) $(COMPILE_FLAGS) main.o MyString.o -o app.exe

clean:
	rm -f *.o app.exe