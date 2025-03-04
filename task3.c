#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct CacheEntry{
    int key,value;
    time_t expiry;
};

struct CacheEntry cache[1000];
int n=0;

void cleanExpired(){
    time_t now=time(NULL);
    int j=0;
    for(int i=0;i<n;i++){
        if(cache[i].expiry>now)cache[j++]=cache[i];
    }
    n=j;
}

void set(int key,int value,int expiryTime){
    cleanExpired();
    for(int i=0;i<n;i++){
        if(cache[i].key==key){
            cache[i].value=value;
            cache[i].expiry=time(NULL)+expiryTime;
            return;
        }
    }
    cache[n].key=key;
    cache[n].value=value;
    cache[n++].expiry=time(NULL)+expiryTime;
}

int get(int key){
    cleanExpired();
    for(int i=0;i<n;i++){
        if(cache[i].key==key)return cache[i].value;
    }
    return -1;
}

int main(){
    set(1,100,5);
    set(2,200,3);
    printf("%d\n",get(1));
    sleep(4);
    printf("%d\n",get(2));
    printf("%d\n",get(1));
    return 0;
}
