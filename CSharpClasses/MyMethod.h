#pragma once

#include <string>
#include <vector>

#include "MyLexeme.h"
#include "MyField.h"
#include "MyParameter.h"

class MyMethod : public virtual MyLexeme
{
public:
	MyMethod();
	virtual ~MyMethod();

	bool IsAbstract() { return isAbstract_; }
	bool HasSameSignatures(MyMethod* method);
	bool IsImplementationToAnother(MyMethod* method);

	DataType GetReturnType();
	std::vector<MyParameter*>* GetParams() { return &params_; }

	inline friend bool operator == (const MyMethod& lhs, const MyMethod& rhs) {
		return lhs.HasSameSignatures(rhs) && (lhs.IsAbstract() == rhs.IsAbstract());
	}

private:
	std::string name_;
	bool isAbstract_;

	DataType returnValue_;
	std::vector<MyParameter*> params_;
};

