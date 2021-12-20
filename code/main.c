#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cstring.h"

int main() {
	const char* source = "Hello, sailor!";
	CString* cstring = cstring_new(source);

	assert(cstring_length(cstring) == 14);
	assert(cstring_at(cstring, 0) == 'H');
	assert(cstring_at(cstring, 13) == '!');
	assert(strcmp(source, cstring_get_string(cstring)) == 0);

	cstring_replace(cstring, 7, 'S');
	assert(cstring_at(cstring, 7) == 'S');

	puts(cstring_get_string(cstring));
	puts("If you see this message, all tests have passed :)");

	cstring_delete(cstring);
}