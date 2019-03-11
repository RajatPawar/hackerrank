#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, queries, temp, from, to, type;
    vector<int> arr;

    scanf("%d %d", &n, &queries);
    printf("\nN: %d, queries: %d", n, queries);

    while(n-- > 0) {
        scanf("%d", &temp);
        printf("\nArr elem: %d", temp);
        arr.push_back(temp);
    }

    while(queries-- > 0) {
        scanf("%d %d %d", &type, &from, &to);

        switch(type) {
            case 1: {
                printf("\nBefore: ");
    for(vector<int>::iterator itr = arr.begin(); itr != arr.end(); itr++) 
        printf("%d ", *itr);
                // Front
                vector<int>::iterator itr = arr.begin(),
                start = arr.begin(), 
                end = arr.begin();

                advance(itr, from - 1);
                advance(end, to);
                for(; itr < end; itr++, start++) {
                    temp = *itr;
                    arr.erase(itr);
                    arr.insert(start, temp);
                }
                printf("\nAfter: ");
    for(vector<int>::iterator itr = arr.begin(); itr != arr.end(); itr++) 
        printf("%d ", *itr);
                break;
            }
            case 2: {
                printf("\nBefore: ");
    for(vector<int>::iterator itr = arr.begin(); itr != arr.end(); itr++) 
        printf("%d ", *itr);
                vector<int>::iterator itr;

                itr = arr.begin() + from - 1;

                //vector<int> temp;

             for(unsigned i = from - 1; i < to; i++) {
                    printf("\nPoints to %d", temp);
                    itr = arr.begin() + from - 1;
                    itr = arr.erase(itr);
                    temp = *itr;
                }
                // arr.push_back(temp);

                printf("\nAfter: ");
    for(vector<int>::iterator itr = arr.begin(); itr != arr.end(); itr++) 
        printf("%d ", *itr);
                break;
            }
            default: {
                perror("\nWrong input");
                exit(1);
            }
        }
    } 
    printf("\n");
    for(vector<int>::iterator itr = arr.begin(); itr != arr.end(); itr++) 
        printf("%d ", *itr);

    return 0;
}
