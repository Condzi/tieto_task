#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "cstring.h"


CString* 
cstring_new(const char* string) {
	CString* result = malloc(sizeof(CString));
	if (!result) {
		perror("malloc() failed in cstring_new");
		return NULL;
	}

	result->length = strlen(string);
	result->buffer = malloc(sizeof(*string)*result->length + 1);
	if (!result->buffer) {
		perror("malloc() failed in cstring_new");
		return NULL;
	}

	memcpy(result->buffer, string, result->length + 1);

	return result;
}

void
cstring_delete(CString* cstring) {
	free(cstring->buffer);
	free(cstring);
}

size_t
cstring_length(CString* cstring) {
	return cstring->length;
}

char
cstring_at(CString* cstring, size_t idx) {
	assert(cstring);
	assert(cstring->length >= idx);

	return cstring->buffer[idx];
}

void
cstring_replace(CString* cstring, size_t idx, char new_char) {
	assert(cstring);
	assert(cstring->length >= idx);

	cstring->buffer[idx] = new_char;
}

const char*
cstring_get_string(CString* cstring) {
	assert(cstring);

	return cstring->buffer;
}