
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapp(float *a, float *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num;
    printf("How many processes?\n");
    scanf("%d", &num);
    int process[num];
    int bt[num];
    int priority[num];
    float wt[num];
    float tt[num];
    float avgtt = 0.0, avgwt = 0.0;
    printf("Enter Process ID, corresponding burst time and priority\n");
    for (int i = 0; i < num; i++) {
        scanf("%d", &process[i]);
        scanf("%d", &bt[i]);
        scanf("%d", &priority[i]);
    }

    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (priority[i] > priority[j]) {
                swap(&bt[i], &bt[j]);
                swap(&process[i], &process[j]);
                swap(&priority[i], &priority[j]);
            }
        }
    }

    for (int i = 0; i < num; i++) {
        wt[i] = 0.0;
        for (int j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
        tt[i] = wt[i] + bt[i];
        avgwt += wt[i];
        avgtt += tt[i];
    }   
    
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (process[i] > process[j]) {
                swap(&process[i], &process[j]);
                swapp(&wt[i], &wt[j]);
                swapp(&tt[i], &tt[j]);
            }
        }
    }
    
    printf("\nWT:\n");
    for (int i = 0; i < num; i++) {
        printf("P%d: %.2f\n", process[i], wt[i]);
    }
    printf("Avg WT: %.2f\n", avgwt / num);
    printf("TT:\n");
    for (int i = 0; i < num; i++) {
        printf("P%d: %.2f\n", process[i], tt[i]);
    }
    printf("Avg TT: %.2f\n", avgtt / num);
    return 0;
}
