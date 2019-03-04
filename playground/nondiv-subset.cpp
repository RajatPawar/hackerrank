int max(int a, int b) {
    return (a >= b) ? a : b;
}

int min(int a, int b) { return (a <= b) ? a : b; }

/*
 * The idea is to do the following 
 * 1) Store remainders of all the numbers when divided by k
 * 2) We know that if two numbers have remainder x & k - x,
 *    then their sum would be divisible by k.
 * 3) So, store how many numbers have remainder 0, 1, x.. k/2
 * 4) Now, count maximum of either x or k-x but not both (point 2)
 * 5) There's a special case for remainders 0 & k/2 - more than 1 of 
 *    these would violate the condition. (two numbers with rem(0) = sum/k -> rem 0)
 * 6) So, we take the lesser of the remainders 0 count - either 1 or 0. Same for k/2.
*/

int nonDivisibleSubset(int k, vector<int> S) {
    int rem[k];
    memset(rem, 0, sizeof(rem));

    for(int i = 0; i < S.size(); i++) 
        rem[S[i] % k]++;

    int set_size = min(rem[0], 1);
    
    if(!(k % 2)) rem[k/2] = min(rem[k/2], 1);

    for(int itr = 1; itr <= k/2; itr++) 
        set_size += max(rem[itr], rem[k - itr]);

    return set_size;
}

