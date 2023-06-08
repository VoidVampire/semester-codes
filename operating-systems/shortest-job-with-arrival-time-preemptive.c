#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapp(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num;
    printf("How many processes?\n");
    scanf("%d", &num);
    int process[num];
    int bt[num];
    int remaining_bt[num];
    float wt[num];
    float tt[num];
    int at[num];
    float avgtt = 0.0, avgwt = 0.0;
    int max_at = 0;
    printf("Enter Process ID, burst time, and arrival time:\n");
    for (int i = 0; i < num; i++) {
        scanf("%d", &process[i]);
        scanf("%d", &bt[i]);
        scanf("%d", &at[i]);
        remaining_bt[i] = bt[i];
        if (at[i] > max_at) {
            max_at = at[i];
        }
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

        
    int completed = 0;
    int current_time = 0;
    int min_bt_index;

    while (completed < num) {
        min_bt_index = -1;
        int min_bt = 9999;

        for (int i = 0; i < num; i++) {
            if (at[i] <= current_time && remaining_bt[i] < min_bt && remaining_bt[i] > 0) {
                min_bt = remaining_bt[i];
                min_bt_index = i;
            }
        }

        if (min_bt_index == -1) {
            current_time++;
            continue;
        }

        remaining_bt[min_bt_index]--;

        if (remaining_bt[min_bt_index] == 0) {
            completed++;
            wt[min_bt_index] = current_time - at[min_bt_index] - bt[min_bt_index] + 1;
            tt[min_bt_index] = current_time - at[min_bt_index] + 1;
            avgwt += wt[min_bt_index];
            avgtt += tt[min_bt_index];
        }

        current_time++;
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