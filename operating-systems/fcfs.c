#include <stdio.h>

int main() {
    int num;
    printf("How many processes?\n");
    scanf("%d", &num);
    int process[num];
    int bt[num];
    float wt[num];
    float tt[num];
    float avgtt = 0.0, avgwt = 0.0;
    printf("Enter Process ID and corresponding burst time\n");
    for (int i = 0; i < num; i++) {
        scanf("%d", &process[i]);
        scanf("%d", &bt[i]);
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