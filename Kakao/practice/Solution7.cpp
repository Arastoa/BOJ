#include <string>
#include <vector>
#include <string.h>
#define INF 987654321
using namespace std;

int cache[20001][100];
int strsSize;
string target;
int targetSize;

int DPSol(const vector<string>& strs, int pos, int arrPos) {
	if (pos == targetSize) return 0;

	int& ret = cache[pos][arrPos];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 0; i< strsSize; i++) {
		int j = 0;
		int strLen = strs[i].size();
		for (; j<strLen; j++) {
			if (pos + j >= targetSize || target[pos + j] != strs[i][j])
				break;
		}
		if (j == strLen) {
			ret = min(ret, DPSol(strs, pos + j, i) + 1);
		}
	}
	return ret;
}

int solution(vector<string> strs, string t)
{
	int answer = INF;
	strsSize = strs.size();
	target = t;
	targetSize = target.size();
	memset(cache, -1, sizeof(cache));

	for (int i = 0; i< strsSize; i++) {
		answer = min(answer, DPSol(strs, 0, i));
	}

	return  (answer == INF ? -1 : answer);
}
