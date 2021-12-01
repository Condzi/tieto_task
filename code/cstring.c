#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "cstring.h"


CString* 
cstring_new(char const* string) {
	CString* result = malloc(sizeof(CString));
	assert(result);

	if (string) {
		result->length = (int64_t)strlen(string);
		result->buffer = malloc(sizeof(*string)*result->length + 1);
		memcpy(result->buffer, string, result->length + 1);
	} else {
		result->buffer = NULL;
		result->length = 0;
	}

	return result;
}

int64_t
cstring_length(CString* cstring) {
	assert(cstring);
	return cstring->length;
}

char
cstring_at(CString* cstring, int64_t idx) {
	assert(cstring);
	assert(cstring->length >= idx);
	assert(idx >= 0);

	return cstring->buffer[idx];
}

void
cstring_replace(CString* cstring, int64_t idx, char new_char) {
	assert(cstring);
	assert(cstring->length >= idx);
	assert(idx >= 0);

	cstring->buffer[idx] = new_char;
}

char const* const
cstring_get_string(CString* cstring) {
	assert(cstring);

	return cstring->buffer;
}