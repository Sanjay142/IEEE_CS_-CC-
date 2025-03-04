#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

struct Stack{
    int a[MAX];
    int min[MAX];
    int max[MAX];
    int t;
}s;

void push(int x){
    if(s.t==MAX-1)return;
    s.a[++s.t]=x;
    if(s.t==0){s.min[s.t]=x;s.max[s.t]=x;}
    else{
        s.min[s.t]=x<s.min[s.t-1]?x:s.min[s.t-1];
        s.max[s.t]=x>s.max[s.t-1]?x:s.max[s.t-1];
    }
}

void pop(){if(s.t>=0)s.t--;}

int top(){return s.t>=0?s.a[s.t]:-1;}

int getMin(){return s.t>=0?s.min[s.t]:-1;}

int getMax(){return s.t>=0?s.max[s.t]:-1;}

int main(){
    s.t=-1;
    push(5);push(1);push(10);push(0);
    printf("Top:%d Min:%d Max:%d\n",top(),getMin(),getMax());
    pop();
    printf("Top:%d Min:%d Max:%d\n",top(),getMin(),getMax());
    return 0;
}
