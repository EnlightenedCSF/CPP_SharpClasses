#include "MyNamespace.h"


MyNamespace::~MyNamespace()
{
}

void MyNamespace::AddClass(MyClass* myClass) {
	classes_.insert(std::pair<std::string, MyClass*>(myClass->GetName(), myClass));
}

std::ostream& operator << (std::ostream& out, MyNamespace* n) {
	out << n->name_ << "\n===========\n";
	
	int i = 1;
	for (auto pos = n->classes_.begin(); pos != n->classes_.end(); pos++) {
		out << i++ << '\t' << pos->first << "\n";
	}

	return out;
}