#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int queries, type;
    long number;
    vector<long> stack, max_stack;

    scanf("%d", &queries);

    while(queries--) {
        scanf("%d", &type);
        switch(type) {
            case 1: {
                scanf("%ld", &number);

                stack.push_back(number);

                if(!max_stack.size()) {
                    max_stack.push_back(number);
                    break;
                }

                long max = max_stack.back();
                if(number >= max) max_stack.push_back(number);

                break;
            }
            case 2: {
                long pop = stack.back();
                stack.pop_back();

                if(pop == max_stack.back()) max_stack.pop_back();
                
                break;
            }
            case 3: {
                if(max_stack.size()) cout<<max_stack.back()<<endl;
                break;
            }
            default: {
                break;
            }
        }
    }  
    return 0;
}

