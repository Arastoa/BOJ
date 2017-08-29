#include<vector>
#include <string.h>
#include <math.h>
#define LAND_MAX_SIZE 100001
using namespace std;


int n,m;
int cache[LAND_MAX_SIZE][4][4];

int dpSol(const vector<vector<int> >& land, int pos, int cul, int t){
    if(pos == n) return 0;
    int& ret = cache[pos][cul][t];
    
    if(ret!=-1) return ret;
    ret = 0;
    
    for(int i=0 ; i<4 ;i++){
        if(i==cul) continue;
        ret = max(ret, dpSol(land, pos+1,i,cul) + land[pos][cul]);
    }
    
    return ret;
}

int solution(vector<vector<int> > land)
{
    n = land.size();
    m = land[0].size();
    memset(cache, -1, sizeof(cache));
    
	int answer = 0;
    
    for(int i=0 ; i<4 ; i++)
        answer = max(answer, dpSol(land, 0,i, i));

	return answer;
}
