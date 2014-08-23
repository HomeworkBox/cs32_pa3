all: test

testdir = tests
basefiles = cplex.cpp qnion.cpp
gxxpaths = -I$(testdir)/gtest-1.6.0/include -L$(testdir)/gtest-1.6.0
gxxargs = -Wall -g3 -O0 $(gxxpaths) $(basefiles)
libs = -lgtest -lpthread

example: $(basefiles) example.cpp
	g++ $(gxxargs) example.cpp -o example

test: $(basefiles) $(testdir)/cplex_tests.cpp $(testdir)/qnion_tests.cpp
	g++ $(gxxargs) $(testdir)/cplex_tests.cpp -o cplex_tests $(libs);\
	g++ $(gxxargs) $(testdir)/qnion_tests.cpp -o qnion_tests $(libs)

gtest:
	cd $(testdir);\
	unzip -o ./gtest-1.6.0.zip;\
	cd ./gtest-1.6.0;\
	./configure;\
	make;\
	cmake .;\
	g++ -I./include -I./ -c ./src/gtest-all.cc;\
	ar -rv libgtest.a gtest-all.o

clean:
	rm -f ./cplex_tests ./qnion_tests ./example
