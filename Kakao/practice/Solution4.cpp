#include<vector>
#include <string.h>
using namespace std;

int result = 0;
int n,m;
int cache[1000][1000];

int DPSolution(const vector<vector<int> >& board, int y, int x){
    if(y==n || x == m) return 0;
    
    int& ret = cache[y][x];
    if(ret!=-1) return ret;
    
    int down = DPSolution(board, y+1, x);
    int right = DPSolution(board, y, x+1);
    int cross = DPSolution(board, y+1, x+1);
    if(!board[y][x])
        ret =0;
    else if(down == 0 || right == 0 || cross == 0)
        ret = 1;
    else{
        if(down == cross && right == cross)
            ret = down+1;
        else
            ret = min(down,min(cross, right))+1;
        
    }
    result = max(result, ret);
    return ret;
}

int solution(vector<vector<int> > board)
{
    int answer = 0;
    memset(cache, -1, sizeof(cache));
    n = board.size(); m = board[0].size();
    
    answer = DPSolution(board,0, 0);
    
    return result * result;
}
