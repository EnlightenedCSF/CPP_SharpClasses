#include "MyMethod.h"
#include <algorithm>


MyMethod::MyMethod()
{
}


MyMethod::~MyMethod()
{
}

DataType MyMethod::GetReturnType() {
	return returnValue_;
}

bool MyMethod::HasSameSignatures(MyMethod* method) {
	bool returnTypesSame = returnValue_ == method->returnValue_;
	bool paramsSame = std::is_permutation(method->GetParams()->begin(), method->GetParams()->end(), params_.begin());
	return returnTypesSame && paramsSame;
}

bool MyMethod::IsImplementationToAnother(MyMethod* method) {
	if (isAbstract_)
		return false;

	return HasSameSignatures(method);
}