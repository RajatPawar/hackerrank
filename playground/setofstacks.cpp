#include <iostream>

using namespace std;

class SetStacks {
    int topple_limit, top, **stack_arr;
    public:

    SetStacks(int topple) : topple_limit()
}


// Idea is to mod top with topple and as soon as it goes over, you get the index of the stack you must operate with
// using a divide operation - check if that stack exists/create a new one using dyn allocation 
// push is the above, pop is simple too - decrease, check if the decrease is in current stack or previous using div/mod

