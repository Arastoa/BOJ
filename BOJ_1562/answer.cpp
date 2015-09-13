#include <iostream>
#include <string.h>
#define DIV 1000000000
using namespace std;

int cache[101][10][1024];
int stairNum(int index, int num,int bit);
int n,judge=1023;

int main(){

	cin >> n; memset(cache, -1, sizeof(cache));
	int result = 0;
	for (int i = 1; i < 10; i++){
		result += stairNum(1, i,  1<<i);
		result %= DIV;
	}

	cout << result << endl;
	return 0;
}

int stairNum(int index, int num, int bit){
	if (index == n) {
        bit|=(1<<num);

		if (bit == judge)
			return 1;
		return 0;
	}
   
	int& ret = cache[index][num][bit];
	if (ret != -1) return ret;
	ret = 0;
	if (num == 0){
		ret += stairNum(index + 1, num + 1,bit | (1<<(num+1)));
	}
	else if (num == 9){
		ret += stairNum(index + 1, num - 1, bit | (1 << (num -1)));
	}
	else ret += stairNum(index + 1, num - 1, bit | (1 << (num -1))) + stairNum(index + 1, num + 1, bit | (1 << (num +1)));

	ret %= DIV;

	return ret;
}
