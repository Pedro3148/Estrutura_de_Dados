#include <stdlib.h>
#include <stdio.h>
#include "merge_sort.h"

void merge(int *a, int left, int middle, int right) {
    int index_subarray1, index_subarray2 , index_helper;
    index_subarray1 = left;
    index_subarray2 = middle + 1;

    int length = right - left + 1;
    int helper[length];

    for (index_helper = 0; index_helper < length; index_helper++) {
        if (index_subarray1 <= middle && index_subarray2 <= right){
            if (a[index_subarray1] < a[index_subarray2]) {
                helper[index_helper] = a[index_subarray1];
                index_subarray1++;
            } else {
                helper[index_helper] = a[index_subarray2];
                index_subarray2++;
            }
        } else {
            if (index_subarray1 < middle + 1) {
                helper[index_helper] = a[index_subarray1];
                index_subarray1++;
            } else {
                helper[index_helper] = a[index_subarray2];
                index_subarray2++;
            }
        }
    }
    int i = left;
    for (index_helper = 0; index_helper < length; index_helper++) {
        a[i] = helper[index_helper];
        i++;
    }
}

void merge_sort(int *a, int left, int right) {
    int middle;
    if (left < right) {
        middle = (left + right) / 2;
        merge_sort(a, left, middle);
        merge_sort(a, middle + 1, right);
        merge(a, left, middle, right);
    }
}