#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[]){
    srand(time(0));
    int n;
    int len;
    if (argc <= 1){
        n = 250;
        len = 15;
    }
    else if (argc <= 2){
        n = 500;
        len = atoi(argv[1]);
    }
    else if (argc <= 3){
        n = atoi(argv[2]);
        len = atoi(argv[1]);
    }
    if (len <= 0) return 1;
    printf("%d number, from 0 to %d\n", len, n-1);
    int* arr = malloc(sizeof(int) * len);
    //int arr[] = {42, 80, 75, 12, 25};
    //int len = sizeof(arr) / sizeof(arr[0]);
    
    // find max value in the array
    int max = arr[0] = rand() % n;     
    for (int i = 1; i < len; i++){
        arr[i] = rand() % n;
        if (arr[i] > max) max = arr[i];
    }

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

    // Radix sort:
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
    printf("-\nafter radix sort:\n");
    for (int i = 0; i < len; i++)
        printf(format1, arr[i]);
    putchar('\n');
}
