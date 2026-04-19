#include <stdio.h>
#include <limits.h>
int main() {

int n, i, smallest;
int at[20], bt[20], rt[20], finish;
int time = 0, completed = 0;
int wt[20], tat[20];
float avg_wt = 0, avg_tat = 0;
printf("Enter number of processes: ");
scanf("%d", &n);
// Input arrival & burst times
for (i = 0; i < n; i++) {
printf("Enter Arrival Time of P%d: ", i + 1);
scanf("%d", &at[i]);
printf("Enter Burst Time of P%d: ", i + 1);
scanf("%d", &bt[i]);
rt[i] = bt[i]; // Remaining time initially = burst time
}
// SRTF Scheduling
printf("\nGantt Chart Order (Process Execution):\n");
while (completed != n) {
smallest = -1;
for (i = 0; i < n; i++) {
if (at[i] <= time && rt[i] > 0) {
if (smallest == -1 || rt[i] < rt[smallest])
smallest = i;
}
}
// If no process has arrived yet
if (smallest == -1) {
time++;
continue;
}
// Reduce the remaining time of the selected process
rt[smallest]--;
printf("P%d ", smallest + 1);
// If a process completes
if (rt[smallest] == 0) {
completed++;
finish = time + 1;
tat[smallest] = finish - at[smallest];
wt[smallest] = tat[smallest] - bt[smallest];
avg_wt += wt[smallest];
avg_tat += tat[smallest];
}
time++;
}

// Output Table
printf("\n\nProcess\tAT\tBT\tWT\tTAT\n");
for (i = 0; i < n; i++) {
printf("P%d\t%d\t%d\t%d\t%d\n",
i + 1, at[i], bt[i], wt[i], tat[i]);
}
printf("\nAverage Waiting Time = %.2f", avg_wt / n);
printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);
return 0;
}
