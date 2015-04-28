#pragma once

#include <string>

#include "MyLexeme.h"

class MyField : public virtual MyLexeme
{
public:
	MyField(Visibility v, DataType d, std::string n) : name_(n), dataType_(d) { visibility_ = v; isStatic_ = false; }
	MyField(Visibility v, DataType d, std::string n, bool isStatic) : name_(n), dataType_(d)  { isStatic_ = isStatic; visibility_ = v; }
	virtual ~MyField();

	std::string GetName(){ return name_; }

protected:
	std::string name_;
	DataType dataType_;
};

