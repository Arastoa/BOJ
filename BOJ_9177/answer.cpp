#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

int cache[201][201];
string s, s1, comp;
int ns, ns1, ncomp;
int judge(int sp, int s1p, int compp);

int main(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> s >> s1 >> comp;
		memset(cache, -1, sizeof(cache));
		ns = s.size(), ns1 = s1.size(), ncomp = comp.size();
		printf("Data set %d: ", i);
		if (judge(0,0,0)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}

int judge(int sp, int s1p, int compp){
	if (compp == ncomp) return 1;
	int& ret = cache[sp][s1p];
	if (ret != -1) return ret;
	ret = 0;
	if (comp[compp] == s[sp] && sp<ns) ret |= judge(sp + 1, s1p, compp + 1);
	if (comp[compp] == s1[s1p] && s1p<ns1) ret |= judge(sp, s1p + 1, compp + 1);

	return ret;
}
