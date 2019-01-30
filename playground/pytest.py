#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the cutTheSticks function below.
def cutTheSticks(arr):
    num_cuts = 1
    result = []
    while num_cuts != 0:
        cut = min(arr)
        num_cuts = 0
        for k,i in enumerate(arr):
            if i >= cut:
                arr[k] =  arr[k] - cut
                num_cuts = num_cuts + 1
        print(arr)
        if num_cuts == len(arr) and cut == 0:
            break
        else:
            result.append(num_cuts)
    return result

if __name__ == '__main__':
    #n = int(input())

    #arr = list(map(int, input()))

    result = cutTheSticks([1,2, 3, 4, 3, 3, 2, 1])

    print('\n'.join(map(str, result)))

