#include "array_operations.hh"
#include <iostream>
#include <algorithm>


int greatest_v1(int *itemptr, int size)
{
    int greatest = -1000;
    for (int* i = itemptr; i < itemptr + size; ++i) {
        if (*i > greatest) {
            greatest = *i;
        }
    }
    return greatest;
}

int greatest_v2(int *itemptr, int *endptr)
{
    int greatest = -1000;
    for (int* i = itemptr; i < endptr; ++i) {
        if (*i > greatest) {
            greatest = *i;
        }
    }
    return greatest;
}

void copy(int *itemptr, int *endptr, int *targetptr)
{
    int k = 0;
    for (int* i = itemptr; i < endptr; ++i) {
        targetptr[k] = *i;
        ++k;
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *leftptr, int *rightptr)
{
    int *i = leftptr,
            *j = rightptr - 1;
    while (i < j) {
        swap(i, j);
        ++i;
        --j;
    }
}
