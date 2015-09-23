#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#pragma warning (disable : 4996)
using namespace std;

const int ALPHABETS = 26;
int toNum(char ch) { return ch - 'A'; }

int test,n, k;
long long cache[17][1 << 17];
long long algo(int index, int visited);

int main(){
	int t; cin >> t;
	while (t--){
		memset(cache, -1, sizeof(cache));
		cin >>test>> n >> k;
		cout <<test<< ' '<< algo(0, 0)<<endl;
	}
	return 0;
}

long long algo(int index, int visited){
	if (index == n) return 1;
	long long& ret = cache[index][visited];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < n; i++){
		if (index == i && index < k) continue;
		if (!(visited & (1 << i))) ret += algo(index+1, visited | (1 << i));
	}
	return ret;
}
