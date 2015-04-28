#pragma once

#include "MyField.h"

class MyProperty : public virtual MyField
{
public:
	MyProperty(Visibility v, DataType d, std::string n) : MyField(v, d, n) { isStatic_ = false; hasGetter_ = true; hasSetter_ = true; }
	MyProperty(Visibility v, DataType d, std::string n, bool isStatic) : MyField(v, d, n, isStatic)  { hasGetter_ = true; hasSetter_ = true; }
	virtual ~MyProperty();

	void SetHasGetter(bool hasGetter) { hasGetter_ = hasGetter; }
	void SetHasSetter(bool hasSetter) { hasSetter_ = hasSetter; }

	bool GetHasGetter(){ return hasGetter_; }
	bool GetHasSetter(){ return hasSetter_; }

	bool IsAbstract() { return isAbstract_; }
	bool IsReadOnly() { return isReadOnly_; }

	bool HasSameSignatures(MyProperty* prop);
	bool IsImplementationToAnother(MyProperty* prop);

private:
	bool hasGetter_;
	bool hasSetter_;

	bool isReadOnly_;
	bool isAbstract_;
};

