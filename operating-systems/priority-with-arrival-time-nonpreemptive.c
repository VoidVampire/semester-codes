#include <stdio.h>
#include <limits.h>

int main() {
    int num;
    printf("How many processes?\n");
    scanf("%d", &num);
    int process[num];
    int bt[num];
    int priority[num];
    float wt[num];
    float tat[num];
    int at[num];
    float avgtt = 0.0, avgwt = 0.0;
    printf("Enter Process ID, burst time, arrival time and priority:\n");
    for (int i = 0; i < num; i++) {
        scanf("%d", &process[i]);
        scanf("%d", &bt[i]);
        scanf("%d", &at[i]);
        scanf("%d", &priority[i]);
    }

    
    int b[num + 1];
    for (int i = 0; i < num; i++) {
        b[i] = priority[i];
    }
    b[num] = INT_MAX;

    int ct[num];
    int count = 0;
    int time = 0;

    while (count < num) {
        int sm = num;
        for (int i = 0; i < num; i++) {
            if (at[i] <= time) {
                if (b[i] < b[sm] && b[i] > 0) {
                    sm = i;
                } else if (b[i] == b[sm] && at[i] < at[sm] && b[i] > 0) {
                    sm = i;
                }
            }
        }
        b[sm] = b[sm] - priority[sm];
        time = time + bt[sm];

        if (b[sm] == 0) {
            count++;
            ct[sm] = time;
            tat[sm] = ct[sm] - at[sm];
            wt[sm] = tat[sm] - bt[sm];
        }
    }

    printf("\nWT:\n");
    for (int i = 0; i < num; i++) {
        printf("P%d: %.2f\n", process[i], wt[i]);
        avgwt += wt[i];
    }
    printf("Avg WT: %.2f\n", avgwt / num);
    printf("TT:\n");
    for (int i = 0; i < num; i++) {
        printf("P%d: %.2f\n", process[i], tat[i]);
        avgtt += tat[i];
    }
    printf("Avg TT: %.2f\n", avgtt / num);
    return 0;
}