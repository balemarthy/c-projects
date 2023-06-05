#include <string.h>
/* strdup --- malloc() storage for a copy of string and copy it */
char *strdup(const char *str) 
  size_t len;
  char *copy;

  len = strlen(str) + 1; /* include room for terminating '\0' */
  copy = malloc(len);

  if (copy != NULL) {
    strcpy(copy, str);
  }
  return copy; /* returns NULL if error */
}
