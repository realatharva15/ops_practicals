#include<stdio.h>
#define MAX 10

int main(){
int n,r;
int count=0;
int alloc[MAX][MAX],max[MAX][MAX],need[MAX][MAX];
int avail[MAX], finish[MAX]={0},safeseq[MAX]; 

printf("Enter the no. of processes: \n");
scanf("%d",&n);
printf("Enter the no. of resources: \n");
scanf("%d",&r);

//filling of the matrices and arrays:
printf("Enter Allocation matrix: \n");
for(int i=0;i<n;i++)
        for(int j=0;j<r;j++)
        scanf("%d",&alloc[i][j]);

printf("Enter Max matrix: \n");
for(int i=0;i<n;i++)
        for(int j=0;j<r;j++)
        scanf("%d",&max[i][j]);

printf("Enter Available matrix : \n");
for(int j=0;j<r;j++)
scanf("%d",&avail[j]);

//calculation of need matrix:
for(int i=0;i<n;i++)
        for(int j=0;j<r;j++)
need[i][j]=max[i][j]-alloc[i][j];

//safety algorithm -  real deal

while(count<n){
int found=0; //boolean hai, atleast one process in safestate=1, if not then 0 (deadlock)

        for(int i=0;i<n;i++){ //for processes to be iterated one by one
                if(!finish[i]){
                        int possible=1;
        for(int j=0;j<r;j++){
        if(need[i][j]>avail[j]){
        possible=0;
        break;
}//if need>avail
}//for2 resource wala

        if(possible==1){   //if possible ==1 wala
        for(int j=0;j<r;j++){ 
        avail[j]+=alloc[i][j];
        } //only this part needs a loop

        found=1;
        safeseq[count++]=i;
        finish[i]=1;
} //if possible==1 wala


}//if (!finish) wala

}// for1 process wala

if(found==0){
        printf("The system is in a DEADLOCK \n");
        return 0;
}

                 }//while
printf("The Safe Sequence is: \n {");
for(int i=0;i<n;i++)
printf("P%d ",safeseq[i]);
printf("}");
}
