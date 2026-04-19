#include<stdio.h>
int main(){
int n;
int at[20],bt[20],tat[20],ct[20],wt[20];

printf("Enter the no. of processes: \n");
scanf("%d",&n);

for(int i=0;i<n;i++){

printf("Enter Arrival Time of P%d: ",i+1);
scanf("%d",&at[i]);

printf("Enter Burst Time of P%d: ",i+1);
scanf("%d",&bt[i]);
}

ct[0]=at[0]+bt[0];
tat[0]=ct[0]-at[0];
wt[0]=tat[0]-bt[0];

for(int i=1; i<n;i++){
if(at[i]>ct[i-1]){
ct[i]=at[i]+bt[i];
tat[i]=ct[i]-at[i];
wt[i]=tat[i]-bt[i];
}
else{
ct[i]=ct[i-1]+bt[i];
tat[i]=ct[i]-at[i];
wt[i]=tat[i]-bt[i];
}
}

printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
for(int i=0;i<n;i++){
        printf("P%d    \t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
        }
return 0;
}
