#pragma once

enum Visibility
{
	PUBLIC,
	PRIVATE,
	PROTECTED
};

enum DataType
{
	MY_INT,
	MY_FLOAT,
	MY_STRING,
	MY_BOOL,
	MY_CHAR
};

class MyLexeme
{
public:
	MyLexeme();
	virtual ~MyLexeme();

protected:
	bool isStatic_;
	Visibility visibility_;
};

