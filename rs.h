#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void radixsort(int* arr, int len){
    // input: reference to array, length of array
    // sort the input array

    if (arr == NULL || len <= 0) return;
    // find max value in the array
    int max = arr[0];     
    for (int i = 1; i < len; i++)
        if (arr[i] > max) max = arr[i];

    // count max digit num
    int digit = 0; 
    do{
        max /= 10;
        digit += 1;
    }while (max > 0);

    // format field for printf
    char format1[1+10+1+1] = "%";
    char format2[3];
    sprintf(format2, "%d", digit);
    strcat(format1, format2);
    strcat(format1, "d "); // format1: "%xd ", x: digit
    
    printf("\ninitail:\n");
    for (int i = 0; i < len; i++)
        printf(format1, arr[i]);
    putchar('\n');

    int** bucket = malloc(sizeof(int*) * 10);
    int bucket_num[10];
    for (int i = 0; i < 10; i++){
        bucket_num[i] = 0;
        bucket[i] = malloc(sizeof(int) * len);
    }

    printf("\nRadix sort, LSD first\n");
    for (int i = 0; i < digit; i++){
        printf("-\nround_%d\n", i+1);
        for (int j = 0; j < len; j++){
            // put arr element into bucket, from LSD to MSD.
            int index = (int)(arr[j]/pow(10, i)) % 10;
            bucket[index][bucket_num[index]] = arr[j];
            bucket_num[index]++; 
        }
        int index = 0;
        for (int d = 0; d < 10; d++){
            // By FIFO, clean the bucket, then store in arr, from bucket[0] to bucket[9].
            int x = 0;
            printf("Bucket[%d]: ", d);
            while (bucket_num[d] > 0){
                printf(format1, bucket[d][x]);
                arr[index++] = bucket[d][x];
                bucket[d][x++] = 0;
                bucket_num[d]--;
            }
            putchar('\n');
        }
    } 
    free(bucket);

    printf("-\nafter radix sort:\n");
    for (int i = 0; i < len; i++)
        printf(format1, arr[i]);
    putchar('\n');
}
