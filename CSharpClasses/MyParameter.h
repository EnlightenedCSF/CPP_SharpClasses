#pragma once

#include <string>

#include "MyLexeme.h"

class MyParameter
{
public:
	MyParameter(std::string s, DataType t) : name_(s), type_(t) { }
	virtual ~MyParameter();

	std::string GetName() { return name_; }
	DataType GetDataType() { return type_; }

	inline friend bool operator == (const MyParameter& lhs, const MyParameter& rhs) {
		return lhs.GetName().equals(rhs.GetName()) && (lhs.GetDataType() == rhs.GetDataType());
	}

private:
	std::string name_;
	DataType type_;
};

