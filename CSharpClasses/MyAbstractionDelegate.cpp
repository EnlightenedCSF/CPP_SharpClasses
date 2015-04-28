#include "MyAbstractionDelegate.h"


MyAbstractionDelegate::MyAbstractionDelegate()
{
}


MyAbstractionDelegate::~MyAbstractionDelegate()
{
}

void MyAbstractionDelegate::AddMethod(MyMethod* method) {
	methods_.push_back(method);
}

void MyAbstractionDelegate::AddProperty(MyProperty* prop) {
	properties_.push_back(prop);
}

void MyAbstractionDelegate::RemoveMethod(MyMethod* method) {
	auto pos = std::find(methods_.begin(), methods_.end(), method);

	if (pos != methods_.end()) {
		methods_.erase(pos);
	}
}

void MyAbstractionDelegate::RemoveProperty(MyProperty* prop) {
	auto pos = std::find(properties_.begin(), properties_.end(), prop);

	if (pos != properties_.end()) {
		properties_.erase(pos);
	}
}