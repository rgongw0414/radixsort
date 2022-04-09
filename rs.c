#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[]){
    printf("10^0 = %d\n", (int)(pow(10, 0)));
    srand(time(0));
    //int len = atoi(argv[1]);
    //if (len <= 0) return 1;
    //int* arr = malloc(sizeof(int) * len);
    int arr[] = {42, 80, 75, 12, 25};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    int digit = 0; 
    int max = arr[0]; // max value in the array
    for (int i = 1; i < len; i++)
        if (arr[i] > max) max = arr[i];
    do{
        max /= 10;
        digit += 1;
    }while (max > 0);

    // format field for sprintf
    char format1[1+10+1+1] = "%";
    char format2[3];
    sprintf(format2, "%d", digit);
    strcat(format1, format2);
    strcat(format1, "d");
    
    //char** table = malloc(sizeof(char*) * len); // save input as a (len*digit) 2-D array: table
    for (int i = 0; i < len; i++){
        //arr[i] = rand() % 100;
        printf("%d ", arr[i]);
        //table[i] = malloc(sizeof(char) * digit);
        //sprintf(table[i], format1, arr[i]); // convert int to string
        //if (table[i][0] == ' ') table[i][0] = '0';
        //printf("%s ", table[i]);
    }
    putchar('\n');
    
    int** bucket = malloc(sizeof(int*) * 10);
    int bucket_num[10];
    for (int i = 0; i < 10; i++){
        bucket_num[i] = 0;
        bucket[i] = malloc(sizeof(int) * len);
    }

    for (int i = 0; i < digit; i++){
        for (int j = 0; j < len; j++){
            int index = (int)(arr[j]/pow(10, i)) % 10;
            bucket[index][bucket_num[index]] = arr[j];
            bucket_num[index]++;
        }
        int index = 0;
        for (int d = 0; d < 10; d++){
            int x = 0;
            while (bucket_num[d] > 0){
                arr[index++] = bucket[d][x];
                bucket[d][x++] = 0;
                bucket_num[d]--;
            }
        }
    } 
    for (int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');
}
