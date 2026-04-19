#include <stdio.h>

int main() {
    int pages[50], frame[10], time[10];
    int n, f;
    int faults = 0, counter = 0, flag;
    
    printf("Enter no. of pages: \n");
    scanf("%d", &n);
    
    printf("Enter no. of frames: \n");
    scanf("%d",&f);

    printf("Enter page reference string:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    
        for(int i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = 0;
    }
    
    printf("\nLRU Page Replacement Process:\n\n");
    
    for(int i = 0; i < n; i++) {
        flag = 0;
        
        // Check if page is already in memory (HIT)
        for(int j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag = 1;
                break;
            }
        }
        
        // Page fault (MISS) - find LRU page and replace
        if(flag == 0) {
            int pos = 0;
            for(int j = 1; j < f; j++) {
                if(time[j] < time[pos])
                    pos = j;
            }
            
            frame[pos] = pages[i];
            counter++;
            time[pos] = counter;
            faults++;
        }
        
        // Display current frame state
        printf("Page %d => ", pages[i]);
        for(int j = 0; j < f; j++)
            printf("%d ", frame[j]);
        printf("\n");
    }
    
    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
