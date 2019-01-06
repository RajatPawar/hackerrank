#include <stdio.h>
#include <stdlib.h>

static int *day_arr[2];

int day_of_year(int, int, int);

int main() {
    day_arr[0] = (int *) malloc(sizeof(int) * 13);
    day_arr[1] = (int *) malloc(sizeof(int) * 13);
    
    day_arr[0] = (int[13]) {0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 31};
    day_arr[1] = (int[13]) {0, 31, 29, 31, 30, 31, 30, 31, 30, 31, 30, 31, 31};
    day_of_year(1, 1, 1);   
    return 0;
}

int day_of_year(int year, int month, int date) {
    printf("%d", day_arr[0][10]);
    return 0; 
}
