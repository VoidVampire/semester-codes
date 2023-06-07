#include <stdio.h>

int main(){
    int num;
    printf("How many processes?\n");
    scanf("%d", &num);
    int process[num];
    int bt[num];
    int wt[num];
    int tt[num];
    int avgtt=0, avgwt=0;
    printf("Enter Process ID and corresponding burst time and arrival time\n");
    for (int i=0; i < num; i++){
        scanf("%d",&process[i]);
        scanf("%d",&bt[i]);
    }


    for (int i = 0; i < num; i++) {
        wt[i] = 0;
        for (int j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
        tt[i] = wt[i] + bt[i];
        avgwt += wt[i];
        avgtt += tt[i];
    }   
    printf("\nWT:\n");
    for (int i=0; i < num; i++){
        printf("P%d: %d\n", process[i], wt[i]);
    }
    printf("Avg WT:%d\n", avgwt/num);
    printf("TT:\n");
    for (int i=0; i < num; i++){
        printf("P%d: %d\n", process[i], tt[i]);
    }
    printf("Avg TT:%d\n", avgtt/num);
    return 0;

}
