# Compiler
CXX = g++

# Executable name
CXXFLAGS = -std=c++11 -Wall -Wextra

.DEFAULT_GOAL := main

.PHONY: clean

hangman_login_test: hangmanLoginTester.o hangmanLogin.o
	$(CXX) $(CXXFLAGS) hangmanLoginTester.o hangmanLogin.o -o hangman_login_test
	./hangman_login_test

hangmanLoginTester.o: hangmanLoginTester.cpp hangmanLogin.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

hangmanLogin.o: hangmanLogin.cpp hangmanLogin.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o main