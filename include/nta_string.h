#ifndef NTA_STRING_H
#define NTA_STRING_H

#include "nta_bool.h"
#include "nta_logger.h"
#include "status.h"

#include <ctype.h>
#include <stddef.h>

typedef struct string
{
    char *data;
    size_t len;
    size_t size;
} string;

string *string_new(void);
void string_free(string *s);
string *string_init(const char *c_str);
string *string_copy(const string *s);

char string_index_get(const string *s, const size_t i);
void string_index_set(string *s, const size_t i, const char *c);

char *string_get_data(const string *s);
size_t string_get_len(const string *s);
size_t string_get_size(const string *s);
bool string_cmp(const string *a, const string *b);
bool string_cmp_c_str(const string *s, const char *c_str);

void string_resize(string *s, const size_t new_size);
void string_clear(string *s);
void string_append_char(string *s, const char *c);
void string_concat_str(string *dest, const string *src);
void string_concat_c_str(string *dest, const char *src);
void string_to_upper(string *s);
void string_to_lower(string *s);

void string_print(const string *s);
void string_fprint(FILE *const fptr, const string *s);
void string_debug_print(const string *s);

#endif /* NTA_STRING_H */
