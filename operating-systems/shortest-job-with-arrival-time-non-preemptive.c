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
    float wt[num];
    float tt[num];
    int at[num];
    float avgtt = 0.0, avgwt = 0.0;
    printf("Enter Process ID and corresponding burst time\n");
    for (int i = 0; i < num; i++) {
        scanf("%d", &process[i]);
        scanf("%d", &bt[i]);
        scanf("%d", &at[i]);
    }

    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (at[i] > at[j]) {
                swap(&bt[i], &bt[j]);
                swap(&at[i], &at[j]);
                swap(&process[i], &process[j]);
            }
        }
    }
        
    
    int completed[num];
    for (int i = 0; i < num; i++) {
        completed[i] = 0;
    }

    int current_time = 0;
    int remaining = num;

    while (remaining > 0) {
        int shortest = -1;
        for (int i = 0; i < num; i++) {
            if (completed[i] == 0 && at[i] <= current_time) {
                if (shortest == -1 || bt[i] < bt[shortest]) {
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            current_time++;
            continue;
        }

        completed[shortest] = 1;
        wt[shortest] = current_time - at[shortest];
        tt[shortest] = wt[shortest] + bt[shortest];
        avgwt += wt[shortest];
        avgtt += tt[shortest];
        current_time += bt[shortest];
        remaining--;
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