#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the separateNumbers function below.
void separateNumbers(char* s) {
    int len = strlen(s), number, min_number = 0, test_till = 0, idx = 0;
    char *test_string = (char*) malloc(sizeof(char) * (len + 1)), *number_string = (char*) malloc(sizeof(char) * (len + 1));
    while(test_till < len) {
        test_till++;
        number = 0;

        for(int i = 0; i < test_till; i++) 
            test_string[i] = s[i];

        for(int i = 0; i < test_till; i++) 
            number = (number * 10) + (s[i] - '0');

        min_number = number;
        idx = test_till;

        // There seems to be some problem with detecting 0 in the beginning 
        // Another problem is when the entire string is detected as a valid number

        while(idx < len) {
            if(strncmp(s, test_string, idx)) break;

            number = number + 1;
            sprintf(number_string, "%d", number);

            int from = idx, to = idx + strlen(number_string);
            while(from < to) test_string[from] = number_string[from - idx], from++;
            idx += strlen(number_string);
        }
        if(idx == len && strlen(number_string) != len) {
          printf("YES %d\n", min_number);
          return;
        }
    }
    printf("NO");
}

int main()
{
    char* q_endptr;
    char* q_str = readline();
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int q_itr = 0; q_itr < q; q_itr++) {
        char* s = readline();

        separateNumbers(s);
    }

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
