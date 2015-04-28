#pragma once

#include <hash_map>
#include <string>

#include "MyLexeme.h"
#include "MyField.h"
#include "MyMethod.h"
#include "MyAbstractionDelegate.h"
#include "MyProperty.h"

class MyClass : public virtual MyLexeme
{
public:
	MyClass(std::string name) : name_(name) { isStatic_ = false; }
	MyClass(std::string name, bool isStatic) : name_(name) { isStatic_ = isStatic; }
	virtual ~MyClass();

	std::string GetName() { return name_; }
	
	void AddField(MyField* field);
	void AddMethod(MyMethod* method);

	void SetParent(MyClass* parent);

private:
	std::string name_;
	
	bool isAbstract_;

	std::hash_map<std::string, MyField*> fields_;
	std::vector<MyMethod*> methods_;
	std::vector<MyProperty*> properties_;

	MyClass* parent;

	void Check(MyAbstractionDelegate* container);
};

