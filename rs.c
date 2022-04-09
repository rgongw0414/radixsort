#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int (int argc, char* argv[]){
    int len = atoi(argv[1]);
    if (len <= 0) return 1;
    int* arr = malloc(sizeof(int) * len);
    srand(time(0));
    for (int i = 0; i < len; i++){
        arr[i] = rand();
        printf("%d ", arr[i]);
    }
}
