#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#pragma warning(disable : 4996)
#define SIZE 10000001
 
using namespace std;
 
double cache[SIZE]={0.0,};
void setting();
 
int main(){
    setting();
    int n; cin>>n;
 
    while(n--){
        int data; scanf("%d",&data);
        printf("%d\n",(int)cache[data]);
    }
     
    return 0;
}
 
void setting(){
    cache[0]=0;
    cache[1]=1;
     
    for(int i=2; i<SIZE ; i++){
        cache[i]=log10((double)i)+cache[i-1];
    }
}
