#include<stdio.h>
#include<stdlib.h>

struct Interval{
    int start,end;
};

struct Interval intervals[1000];
int n=0;

int cmp(const void *a,const void *b){
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}

void addInterval(int s,int e){
    intervals[n].start=s;
    intervals[n++].end=e;
    qsort(intervals,n,sizeof(struct Interval),cmp);
    int idx=0;
    for(int i=1;i<n;i++){
        if(intervals[idx].end>=intervals[i].start){
            if(intervals[idx].end<intervals[i].end)intervals[idx].end=intervals[i].end;
        }else intervals[++idx]=intervals[i];
    }
    n=idx+1;
}

void getIntervals(){
    for(int i=0;i<n;i++)printf("[%d,%d] ",intervals[i].start,intervals[i].end);
    printf("\n");
}

int main(){
    addInterval(1,5);
    addInterval(6,8);
    addInterval(4,7);
    getIntervals();
    return 0;
}
