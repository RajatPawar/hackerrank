#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NEIGHBOURS 8
char* readline();
char** split_string(char*);

int is_valid_point(int x, int y, int grid_row, int grid_col) {
    if(x < 0 || x >= grid_row) return 0;
    if(y < 0 || y >= grid_col) return 0;
    return 1;
}

int get_region(int **grid, int x, int y, int **visited, int grid_row, int grid_col) {
    
    if(visited[x][y])
      return 0;
    
    visited[x][y] = 1;
    
    if(grid[x][y] == 0) return 0;
    if(!x & !y && grid[x][y]) printf("\nDEBUG: Visiting (%d, %d)", x, y);

    int neighbours[MAX_NEIGHBOURS * 2], counter = 0; // Two coordinates for each point
    memset(neighbours, -1, sizeof(neighbours));
    for(int i = -1; i < 2; i++) { // Generate all neighbors
        for(int j = -1; j < 2; j++) {
            if(i == x && j == y) continue;
            if(is_valid_point(x + i, y + j, grid_row, grid_col)) {
                if(visited[x + i][y + j]) continue;
                neighbours[counter++] = x + i;
                neighbours[counter++] = y + j;
            }
        }
    }

    int region = 1;
    for(int i = 0; i < MAX_NEIGHBOURS * 2; i += 2) {
        if(neighbours[i] == -1) break;
        
        region += get_region(grid, neighbours[i], neighbours[i + 1], visited, grid_row, grid_col);
    }
    return region;
}

void set_zero(int **arr, int row, int col) {
    for(int i = 0; i < row; i++) 
        for(int j = 0; j < col; j++) 
            arr[i][j] = 0;
}

// Complete the maxRegion function below.
int maxRegion(int grid_rows, int grid_columns, int** grid) {
    int **visited = (int**) malloc(sizeof(int*) * grid_rows);
    int max_region = -1, region_size = -1;
    
    for(int i = 0; i < grid_rows; i++) 
        visited[i] = (int*) malloc(sizeof(int) * grid_columns);

    for(int i = 0; i < grid_rows; i++) {
        for(int j = 0; j < grid_columns; j++) {
            if(grid[i][j]) {
              set_zero(visited, grid_rows, grid_columns);
              region_size = get_region(grid, i, j, visited, grid_rows, grid_columns);
              if (region_size > max_region)
                max_region = region_size;
            }
        }
    }
    return max_region;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* m_endptr;
    char* m_str = readline();
    int m = strtol(m_str, &m_endptr, 10);

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    int** grid = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        *(grid + i) = malloc(m * (sizeof(int)));

        char** grid_item_temp = split_string(readline());

        for (int j = 0; j < m; j++) {
            char* grid_item_endptr;
            char* grid_item_str = *(grid_item_temp + j);
            int grid_item = strtol(grid_item_str, &grid_item_endptr, 10);

            if (grid_item_endptr == grid_item_str || *grid_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(*(grid + i) + j) = grid_item;
        }
    }

    int grid_rows = n;
    int grid_columns = m;

    int res = maxRegion(grid_rows, grid_columns, grid);

    fprintf(fptr, "%d\n", res);

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

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

