#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define INF 987654321
 
using namespace std;
 
vector<int> field;
int cache[1001][1001];
int jump(int index, int cnt);
int n; 
 
int main(){
    cin>>n; field=vector<int>(n);
    for(int i=0 ; i< n ; i++) cin>>field[i];
    memset(cache,-1,sizeof(cache));
    int result=jump(0,0);
    if(result==INF) result=-1;
    cout<<result<<endl;
 
    return 0;
}
 
int jump(int index, int cnt){
    if(index==n-1)
        return cnt;
    if(index>=n) return INF;
    if(field[index]==0) return INF;
     
    int& ret=cache[index][cnt];
    if(ret!=-1) return ret;
     
    ret=INF;
    for(int i=1 ; i<=field[index] && i+index<=n ; i++)
        ret=min(ret,jump(index+i,cnt+1));
     
     
    return ret;
}
