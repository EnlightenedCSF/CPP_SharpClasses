#include "MyProperty.h"


MyProperty::~MyProperty()
{
}

bool MyProperty::HasSameSignatures(MyProperty* prop) {
	bool namesSame = name_.compare(prop->GetName()) == 0;
	bool gettersSettersSame = (hasGetter_ == prop->GetHasGetter()) && (hasSetter_ == prop->GetHasSetter());
	bool readOnlyFlagsSame = isReadOnly_ == prop->IsReadOnly();

	return namesSame && gettersSettersSame && readOnlyFlagsSame;
}

bool MyProperty::IsImplementationToAnother(MyProperty* prop) {
	if (isAbstract_)
		return false;
	return HasSameSignatures(prop);
}