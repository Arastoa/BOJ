#include <vector>
#include <string.h>
using namespace std;

int cache[100000][4][2];
int n;

int DPSol(const vector<int>& sticker, int pos, int offset, bool isSelectFirst){
    if(pos>=n) return 0;
    if(pos == n-1){
        if(isSelectFirst)
             return 0;
        return sticker[pos];
    }
    int& ret = cache[pos][offset][(int)isSelectFirst];
    if(ret != -1) return ret;
    
    ret = 0;
    ret = max(ret, DPSol(sticker, pos + 2, 1, isSelectFirst) + sticker[pos]);  
    ret = max(ret, DPSol(sticker, pos + 3, 2, isSelectFirst) + sticker[pos]);
    
    return ret;
}

int solution(vector<int> sticker)
{
	int answer = 0;
	n = sticker.size();

	if (n == 1)
		return sticker[0];

	memset(cache, -1, sizeof(cache));
	answer = DPSol(sticker, 0, 0, true);
	answer = max(answer, DPSol(sticker, 1, 0, false));
	answer = max(answer, DPSol(sticker, 2, 0, false));

	return answer;
}
