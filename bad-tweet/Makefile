all: bad-tweet.cpp
	g++ -g3 -O0 ./bad-tweet.cpp -o ./bad-tweet

leaks: all
	valgrind --tool=memcheck --leak-check=full ./bad-tweet

clean:
	rm -f ./bad-tweet
