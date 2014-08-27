//
//  bad-tweet.cpp
//  pa3x
//
//  Created by FT: Felicia Truong & Tyler Weimin Ouyang on 8/25/14.
//  Copyright (c) 2014 Tyler Weimin Ouyang. All rights reserved.
//
#include <cstring>
#include <iostream>

using std::cout;

class tweet {
private:
	static const int MaxTextLen = 4095; // no tweet can be longer than that
	char *_text;		// text of the tweet
	int _len; 			// the length of text
	time_t _timestamp;  // time stamp of the tweet
public:
	tweet();
	~tweet();
	void set_text(const char *msg);
	void print() const;
};

tweet::tweet() : _text(0), _len(0) {
	_text = new char[MaxTextLen + 1]();
	_timestamp = time(NULL);
}

//tweet::tweet(const tweet& other){
//    _text = other._text;
//    _len = other._len;
//    _timestamp = other._timestamp;
//}

tweet::~tweet() {
	delete [] _text;
}

void tweet::set_text(const char *str) {
	if(!str)
		return;

	_len = strlen(str);
	if(_len > MaxTextLen)
		_len = MaxTextLen;

    _text = new char[_len+1];
    strcpy(_text, str);
	_text[_len] = '\0';
}

void tweet::print() const {
	std::string ts(ctime(&_timestamp));
	cout << "tweet {\n"
		<< "    len = " << _len << "\n"
		<< "    text = '" << (_text ? _text : "") << "'\n"
		<< "    timestamp = '" << ts.substr(0, ts.length() - 1) << "'\n"
		<< "}\n\n";
}

int main() {
	const int n = 3;
	tweet **ptweets = new tweet*[n];

	// Creating a proto-tweet and duplicating it, so that all
	// 3 subsequently created tweets have the same timestamp
	const tweet *proto = new tweet();

	ptweets[0] = new tweet(*proto);
	ptweets[0]->set_text("Going to the movies today.");

	ptweets[1] = new tweet(*proto);
	ptweets[1]->set_text("I'd vote for [censored] too if I was a [beep].");

	ptweets[2] = new tweet(*proto);
	ptweets[2]->set_text("Is it friday yet?");

	cout << "Tweets:\n\n";
	for(int i = 0; i < n; i++)
		ptweets[i]->print();

	delete proto;
    for(int i = 0; i < n; i++)
        delete ptweets[i];
	delete [] ptweets;
}
