#pragma once

#include <vector>

#include "MyMethod.h"
#include "MyProperty.h"

class MyAbstractionDelegate
{
public:
	MyAbstractionDelegate();
	virtual ~MyAbstractionDelegate();

	void AddMethod(MyMethod* method);
	void AddProperty(MyProperty* prop);

	void RemoveMethod(MyMethod* method);
	void RemoveProperty(MyProperty* prop);

	std::vector<MyMethod*>* GetMethods() { return &methods_; }
	std::vector<MyProperty*>* GetProperties() { return &properties_; }

private:
	std::vector<MyMethod*> methods_;
	std::vector<MyProperty*> properties_;
};

