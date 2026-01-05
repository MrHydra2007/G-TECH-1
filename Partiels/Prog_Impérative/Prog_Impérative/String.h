#pragma once

struct String
{
	char* word;
	int length;
};

String Construct(const char* src);

void Print(const String* str);

int Length(const String* str);

void Concatenate(String* str, const String* other);

int Compare(const String* str, const String* other);

int Insert(String* str, const String* insert, int position);

void Destruct(String** str);

String Substring(const String* str, int start, int length);

