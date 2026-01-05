#include "String.h"
#include<iostream>

String Construct(const char* src)
{

	String* string = (String*)malloc(sizeof(String*));

	string->word = src;
	string->length = sizeof(src);

	return *string;
}

void Print(const String* str)
{
	std::cout << str << std::endl;
}

int Length(const String* str)
{
	int size = sizeof(str) / sizeof(char);
	return size;
}


void Concatenate(String* str, const String* other)
{
	int length = sizeof(str) / sizeof(char);
	for (int i = 0; i < length; ++i)
	{
		str = str + other[i];
	}

	String* newString = (String*)malloc(sizeof(str + &other));
	int newSize = sizeof(newString) / sizeof(char);
}


int Compare(const String* str, const String* other)
{
	int length1 = sizeof(str) / sizeof(char);
	int length2 = sizeof(other) / sizeof(char);

	if (length1 != length2)
		return 1;

	for (int i = 0; i < length1; ++i)
	{
		if (&str[i] != &other[i])
			return 1;
	}

	return 0;
}

int Insert(String* str, const String* insert, int position)
{
	int length = sizeof(str) / sizeof(char);
	for (position; position <= length; ++position)
	{
		int j = 0;
		String* i = &str[position];
		str[position] = insert[j] + i;
		++j;
	}

	return 0;
}

void Destruct(String** str)
{
	free(*str);
	*str = nullptr;
}

String Substring(const String* str, int start, int length)
{
	for (start; start < length; ++start)
	{
		const String newStr = str[start];
	}
	return String();
}





