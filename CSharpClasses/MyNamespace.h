#pragma once

#include <string>
#include <hash_map>

#include "MyClass.h"

class MyNamespace
{
public:
	MyNamespace(std::string name) : name_(name) { }
	virtual ~MyNamespace();

	void AddClass(MyClass* myClass);

	friend std::ostream& operator << (std::ostream& out, MyNamespace* n);

private:
	std::string name_;
	std::hash_map<std::string, MyClass*> classes_;
};

