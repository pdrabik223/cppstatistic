#pragma once
#include <vector>
#include <string>
#include <fstream>
template <class X,class Y>
class ctx
{
public:
	ctx() = delete; 
	ctx(std::string name) {
		this->name = name;
	}

	void addset(X, Y);

	void json_parser(std::string);



private:
	std::string name;
	std::vector<X> x;
	std::vector<Y> y;
};


