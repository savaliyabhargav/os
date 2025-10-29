#include<stdio.h>

void bestFit(int blocksize[],int m,int processsize[],int n){
    int allocation[n];
    for (int i = 0;i<  n ; i++) {
        allocation[i] = -1;
    }
    for (int i = 0;i< n ;i++ ) {
        int bestidx = -1;
        for (int j = 0;j< m ;j++) {
            if (blocksize[j]>= processsize[i]) {
                if (bestidx == -1) {
                    bestidx = j;
                }
                else if (blocksize[j] < blocksize[bestidx]) {
                    bestidx = j;
                }
            }
        }
        if (bestidx != -1) {
            allocation[i] = bestidx;
            blocksize[bestidx] -= processsize[i];
        }
    }
    printf("\nProcess NO.\tProcess Size.\tBlock No.\n");
    for (int i = 0;i < n ; i++) {
        printf("%d\t\t%d\t\t",i+1,processsize[i]);
        if (allocation[i] != -1) {
            printf("%d\n",allocation[i]+1);
        }
        else {
            printf("not allocated\n");
        }
    }

}
int main() {
    int m= 5;
    int n = 4;
    int blocksize[]={100,500,200,300,600};
    int processsize[]={212,417,112,426};
    bestFit(blocksize,m,processsize,n);
    return 0;
}
