#include "MyClass.h"

MyClass::~MyClass()
{
}

void MyClass::AddField(MyField* field) {
	fields_.insert(std::pair<std::string, MyField*>(field->GetName(), field));
}

void MyClass::AddMethod(MyMethod* method) {
	methods_.push_back(method);
}

void MyClass::Check(MyAbstractionDelegate* container) {
	if (!parent)
		parent->Check(container);

	auto abstractMethods = container->GetMethods();
	for (int i = 0; i < abstractMethods->size(); i++) {
		for (int j = 0; j < methods_.size(); j++) {
			if (methods_[j]->IsImplementationToAnother((*abstractMethods)[i])) {
				container->RemoveMethod(methods_[j]);
			}
		}
	}

	auto abstractProperties = container->GetProperties();
	for (int i = 0; i < abstractProperties->size(); i++) {
		for (int j = 0; j < properties_.size(); j++) {
			if (properties_[j]->IsImplementationToAnother((*abstractProperties)[i])) {
				container->RemoveProperty(properties_[j]);
			}
		}
	}

	if (isAbstract_) {
		for (int i = 0; i < methods_.size(); i++){
			if (methods_[i]->IsAbstract()) {
				container->AddMethod(methods_[i]);
			}
		}
		for (int j = 0; j < properties_.size(); j++){
			if (properties_[j]->IsAbstract()) {
				container->AddProperty(properties_[j]);
			}
		}
	}
}
