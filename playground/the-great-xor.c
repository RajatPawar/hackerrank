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

long theGreatXor(long x) {
    
    long result = 0;
    
    // Keeps track of current bit position
    int bit_pos = 0;

    // Add to result all the 2^positions where we encounter 0
    // My logic is that these 0's when XORed with 1 will give 
    // numbers greater than x which is why we count it.

    while(x) {
      if (!(x & 1)) // The LSB is 0
        result += pow(2, bit_pos);
      x >>= 1;
      bit_pos++;
    }

    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* q_endptr;
    char* q_str = readline();
    int q = strtol(q_str, &q_endptr, 10);

    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int q_itr = 0; q_itr < q; q_itr++) {
        char* x_endptr;
        char* x_str = readline();
        long x = strtol(x_str, &x_endptr, 10);

        if (x_endptr == x_str || *x_endptr != '\0') { exit(EXIT_FAILURE); }

        long result = theGreatXor(x);

        fprintf(fptr, "%ld\n", result);
    }

    fclose(fptr);

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

