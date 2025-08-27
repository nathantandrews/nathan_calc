#include "string_extras.h"

#include <string.h>
#include <ctype.h>

void string_to_upper(char *s)
{
    while (*s != '\0')
    {
        *s = toupper(*s);
        ++s;
    }
}
void string_to_lower(char *s)
{
    while (*s != '\0')
    {
        *s = tolower(*s);
        ++s;
    }
}
