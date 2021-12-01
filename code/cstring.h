#pragma once

#include <stdint.h>

typedef struct CString {
	char* buffer;
	// Without \0.
	int64_t length;
} CString;

CString* 
cstring_new(char const* string);

int64_t
cstring_length(CString* cstring);

char
cstring_at(CString* cstring, int64_t idx);

void
cstring_replace(CString* cstring, int64_t idx, char new_char);

char const* const
cstring_get_string(CString* cstring);