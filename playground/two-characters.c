#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int is_alt(char *s) {

  if (!s)
    return 0;
  if (strlen(s) == 1)
    return 0;
  if (strlen(s) == 2) {
    if (*s != *(s + 1))
      return 1;
    else
      return 0;
  }

  char *itr = s + 1;

  while (*itr != '\0') {
    if (*(itr + 1) != '\0') {
      if (*(itr - 1) == *(itr + 1) && *itr != *(itr - 1)) {
        itr++;
        continue;
      } else
        return 0;
    }
    else break;
  }
  return 1;
}

// Complete the alternate function below.
int alternate(char* s) {
  int charmap[26];
  int len = strlen(s);
  char *data = malloc(len + 1);
  strcpy(data, s);
  char *itr = data;
  
  while (*itr != '\0') {
    charmap[*itr - 'a']++;
    itr++;
  }
  
  char *tocpy = (char *) malloc(1001 * sizeof(char));
  int tcpy = 0, biggest = 0;

  for (int firstchar = 0; firstchar < 26; firstchar++) {
    for (int secchar = 0; secchar < 26; secchar++) {
      if (firstchar == secchar)
        continue;
      if(!charmap[firstchar] && !charmap[secchar]) continue;
      else {
            
          itr = data;
          tcpy = 0;

          while(*itr != '\0') {
              if( ( (*itr - 'a') == firstchar) || ((*itr - 'a') == secchar) )
                tocpy[tcpy++] = *itr; 
              itr++;
          }
          tocpy[tcpy] = '\0';
          
          if(is_alt(tocpy)) {
              int l = strlen(tocpy);
              
            if (l > biggest)
              biggest = l;
          }
      }
    }
  }
  return biggest;
}



int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* l_endptr;
    char* l_str = ltrim(rtrim(readline()));
    int l = strtol(l_str, &l_endptr, 10);

    if (l_endptr == l_str || *l_endptr != '\0') { exit(EXIT_FAILURE); }

    char* s = readline();
 
    int result = alternate(s);
    printf("\n\nRESULT: %d", result);
    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}
