#ifndef CSTRING_H
#define CSTRING_H

#include <stdint.h>

/*
 * A simple wrapper for a C-style string.
 */
typedef struct CString {
	char* buffer; //!< Array of size length + 1, where last element is \0.
	size_t length; //!< Length of the string without the NULL-terminator.
} CString;

/*
 * Allocates CString object and copies the 'string' to its buffer.
 * 
 * @param[in] string - NULL-terminated string
 *
 * @return: allocated CString or NULL if out of memory.
 */
CString* 
cstring_new(const char* string);

/*
 * Destroys a CString object and its buffer.
 * 
 * @param[in] cstring - CString object created using cstring_new.
 */
void
cstring_delete(CString* cstring);

/*
 * Getter for CString->length.
 * 
 * @param[in] cstring - CString object created using cstring_new.
 *
 * @return: length of the string without NULL-terminator. 0 if cstring is NULL.
 */
size_t
cstring_length(CString* cstring);

/*
 * Getter for individual element of the string.
 * 
 * @param[in] cstring - CString object created using cstring_new.
 * @param[in] idx - index of the character.
 *
 * @return: copy of the character at position 'idx'. 0 if cstring is NULL or idx is out of bounds.
 */
char
cstring_at(CString* cstring, size_t idx);

/*
 * Replace a character in the CString.
 * 
 * @param[in] cstring - CString object created using cstring_new.
 * @param[in] idx - index of the character.
 * @param[in] new_char - character that should be replaced with.
 *
 */
void
cstring_replace(CString* cstring, size_t idx, char new_char);

/*
 * Get the C-style, NULL-terminated array of chars representation of a string.
 * 
 * @param[in] cstring - CString object created using cstring_new.
 *
 * @return: pointer to a NULL-terminated string held by the CString. NULL if cstring is NULL.
 */
const char*
cstring_get_string(CString* cstring);

#endif