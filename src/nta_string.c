#include "nta_string.h"
#include "nta_bool.h"
#include "nta_logger.h"
#include "status.h"

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <assert.h>

LOG(string)

#define STRING_DEFAULT_SIZE 6
#define STRING_SIZE_GROWTH_RATE 2

/* constructor / destructor / init / copy */

string *string_new(void)
{
    string *s = (string*) malloc(sizeof(*s));

    assert(s != NULL);    
    s->data = (char*) malloc(STRING_DEFAULT_SIZE);
    assert(s->data != NULL);    
    s->data[0] = '\0';
    s->len = 0;
    s->size = STRING_DEFAULT_SIZE;
    return s;
}
void string_free(string *s)
{
    assert(s != NULL);
    free(s->data);
    free(s);
}
string *string_init(const char *c_str)
{
    size_t c_str_len;
    string *s;
    
    assert(c_str != NULL);
    c_str_len = strlen(c_str);
    s = string_new();
    if (s->size < c_str_len + 1)
    {
        /* add space for null character. */
        string_resize(s, c_str_len + 1);
    }
    strncpy(s->data, c_str, c_str_len + 1);
    s->len = c_str_len;
    s->data[s->len] = '\0';
    return s;
}
string *string_copy(const string *s)
{
    assert(s != NULL);
    return string_init(s->data);
}

/* string indexing methods */

char string_index_get(const string *s, const size_t i)
{
    assert(s != NULL);
    if (i < 0 || i > s->len)
    {
        string_log_status(STATUS_INDEX_OUT_OF_BOUNDS_ERROR);
        abort();
    }
    return s->data[i];
}
void string_index_set(string *s, const size_t i, const char *c)
{
    assert(s != NULL);
    assert(c != NULL);
    if (i < 0 || i > s->len - 1) /* prevents access to null terminator */
    {
        string_log_status(STATUS_INDEX_OUT_OF_BOUNDS_ERROR);
        abort();
    }
    s->data[i] = *c;
}

/* accessors */

char *string_get_data(const string *s)
{
    assert(s != NULL);
    return s->data;
}
size_t string_get_len(const string *s)
{
    assert(s != NULL);
    return s->len;
}
size_t string_get_size(const string *s)
{
    assert(s != NULL);
    return s->size;
}
bool string_cmp(const string *a, const string *b)
{
    if (a == NULL || b == NULL)
    {
        string_log_warning("string_cmp: comparing with null.\n");
        return (a == NULL && b == NULL) ? TRUE : FALSE;
    }
    return strcmp(a->data, b->data);
}
bool string_cmp_c_str(const string *s, const char *c_str)
{
    if (s == NULL || c_str == NULL)
    {
        string_log_warning("string_cmp_c_str: comparing with null.\n");
        return (s == NULL && c_str == NULL) ? TRUE : FALSE;
    }
    return strcmp(s->data, c_str);
}

/* mutators */

void string_resize(string *s, const size_t new_size)
{
    char *tmp;

    assert(s != NULL);
    if (s->size >= new_size)
    {
        string_log_warning("string_resize: new size is less than or equal to old size, returning...\n");
        return;
    }
    tmp = (char*) malloc(new_size);
    strncpy(tmp, s->data, s->len + 1);
    free(s->data);
    s->data = tmp;
    s->size = new_size;
    s->data[s->len] = '\0';
}
void string_clear(string *s)
{
    assert(s != NULL);
    if (s->len == 0)
    {
        string_log_warning("string_clear: clearing empty string.\n");
    }
    s->data[0] = '\0';
    s->len = 0;
}
void string_append_char(string *s, const char *c)
{
    assert(s != NULL);
    if (s->len + 2 > s->size)
    {
        string_resize(s, s->size * ((unsigned int) STRING_SIZE_GROWTH_RATE));
    }
    s->data[s->len] = *c;
    ++s->len;
    s->data[s->len] = '\0';
}
static void string_p_concat(string *dest, const char *src)
{
    size_t src_len;

    assert(dest != NULL);
    assert(src != NULL);
    src_len = strlen(src);


    if (dest->len + src_len >= dest->size)
    {
        string_resize(dest, dest->len + src_len + 1);
    }
    strcat(dest->data, src);
    dest->len = dest->len + src_len;
    dest->data[dest->len] = '\0';
}
void string_concat_str(string *dest, const string *src)
{
    string_p_concat(dest, src->data);
}
void string_concat_c_str(string *dest, const char *src)
{
    string_p_concat(dest, src);
}
void string_to_upper(string *s)
{
    char *iter_c;
    
    assert(s != NULL);
    iter_c = s->data;
    while (*iter_c != '\0')
    {
        *iter_c = toupper(*iter_c);
        ++iter_c;
    }
}
void string_to_lower(string *s)
{
    char *iter_c;
    
    assert(s != NULL);
    iter_c = s->data;
    while (*iter_c != '\0')
    {
        *iter_c = tolower(*iter_c);
        ++iter_c;
    }
}

/* printing */

void string_print(const string *s)
{
    assert(s != NULL);
    printf("%s", s->data);
}
void string_fprint(FILE *const fptr, const string *s)
{
    assert(fptr != NULL);
    assert(s != NULL);
    fprintf(fptr, "%s", s->data);
}
void string_debug_print(const string *s)
{
    assert(s != NULL);
    printf("string: \"%s\" ", s->data);
    printf("len: %lu ", (unsigned long) s->len);
    printf("size: %lu\n", (unsigned long) s->size);
}