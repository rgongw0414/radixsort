## Radix sort

#### how to use:
```bash
gcc rs.c -lm && ./a.out 
gcc rs.c -lm && ./a.out 10 
gcc rs.c -lm && ./a.out 15 1000
```

#### sample output:
```bash
15 number, from 0 to 999

initial:
745 278 157 101 480 139 122  90 675  77 593 921  70 727 652

Radix sort, LSD first
-
round_1
Bucket[0]: 480  90  70
Bucket[1]: 101 921
Bucket[2]: 122 652
Bucket[3]: 593
Bucket[4]:
Bucket[5]: 745 675
Bucket[6]:
Bucket[7]: 157  77 727
Bucket[8]: 278
Bucket[9]: 139
-
round_2
Bucket[0]: 101
Bucket[1]:
Bucket[2]: 921 122 727
Bucket[3]: 139
Bucket[4]: 745
Bucket[5]: 652 157
Bucket[6]:
Bucket[7]:  70 675  77 278
Bucket[8]: 480
Bucket[9]:  90 593
-
round_3
Bucket[0]:  70  77  90
Bucket[1]: 101 122 139 157
Bucket[2]: 278
Bucket[3]:
Bucket[4]: 480
Bucket[5]: 593
Bucket[6]: 652 675
Bucket[7]: 727 745
Bucket[8]:
Bucket[9]: 921
-
after radix sort:
 70  77  90 101 122 139 157 278 480 593 652 675 727 745 921
```
