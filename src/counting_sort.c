#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


static const int minVal = 0, maxVal = 9;
static const int diff = maxVal - minVal;


void countingSort (int *arr, size_t len, bool asc);
void printValues (int *arr, size_t len);


int main (int argc, char *argv[]) {
    int arr_1[10] = { 8, 4, 8, 3, 7, 1, 9, 2, 2, 2 };       /// 1 222 3 4 7 88 9
    size_t arr_1_len = sizeof(arr_1) / sizeof(arr_1[0]);

    printf("Values before sorting:\t\t");
    printValues(arr_1, arr_1_len);
    printf("\n\n");

    countingSort(arr_1, arr_1_len, true);

    printf("Values after sorting(asc):\t");
    printValues(arr_1, arr_1_len);
    printf("\n\n");

    countingSort(arr_1, arr_1_len, false);

    printf("Values after sorting(des):\t");
    printValues(arr_1, arr_1_len);
    printf("\n\n");


    return (0);
}


void countingSort (int *arr, size_t len, bool asc) {
    size_t i, j, k = 0;
    size_t countersNum = diff + 1;

    unsigned int *counters = calloc(countersNum, sizeof(*counters));
    if (counters == NULL) {
        perror("mem alloc");
        return;
    }

    /// count vals in <arr>
    for (i = 0; i < len; i++) {
        counters[arr[i]]++;
    }

    /// sort <arr>
    if (asc) {  /// sort in ascending order
        for (i = 0; i < countersNum; i++) {
            for (j = 0; j < counters[i]; j++) {
                arr[k++] = i;
            }
        }
    }
    else {      /// sort in descending order
        for (i = countersNum; (--i < countersNum); ) {
            for (j = 0; j < counters[i]; j++) {
                arr[k++] = i;
            }
        }
    }

    free(counters);
    counters = NULL;
}

void printValues (int *arr, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}
