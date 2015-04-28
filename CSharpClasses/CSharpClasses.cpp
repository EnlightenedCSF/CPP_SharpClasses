// CSharpClasses.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <Windows.h>

#include "MyNamespace.h"
#include "MyField.h"
#include "MyMethod.h"

int main()
{
	MyNamespace n("Task");
	MyClass* a = new MyClass("Human");
	n.AddClass(a);

	a->AddField(new MyField(PUBLIC, MY_INT, "height"));
	a->AddField(new MyField(PUBLIC, MY_FLOAT, "weight"));
	a->AddField(new MyField(PUBLIC, MY_BOOL, "isSingle")); 

	std::cout << &n;

	system("pause");
	return 0;
}

