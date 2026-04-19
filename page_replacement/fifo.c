#include<stdio.h>

int main(){
int n,f,flag;
int page[50],frame[10];
int index=0,fault=0;

printf("Enter the no. of pages: \n");
scanf("%d",&n);

printf("Enter the no. of frames \n");
scanf("%d",&f);

printf("Enter the Page Reference String: \n");
for(int i=0;i<n;i++){
scanf("%d",&page[i]);
}

for(int j=0;j<f;j++){
frame[j]=-1;
}

printf("FIFO Page Replacement Process: \n");

for(int i=0;i<n;i++){
flag=0;

        for(int j=0;j<f;j++){
                if(frame[j]==page[i]){
                flag=1;
                break;
                }
        }
if(flag==0){
frame[index]=page[i];
index=(index+1)%f;
fault++;
}

printf("Page %d =>",page[i]);
        for(int j=0;j<f;j++)
        printf("%d",frame[j]);
        printf("\n");
}
printf("Total Page Faults: %d",fault);
return 0;
}
