#include <iostream>
#include <string>
#define DIV 1000000007

using namespace std;

int main() {
	int t; cin >> t;

	while (t--) {
		string str; cin >> str;
		long long s, e,result=1;
		
		for (int i = 0; i < str.size(); i++) {
			int cnt = 0;
			if (str[i] == '?') {
				s = i-1;
				if (s == -1) s++;
				for (; i < str.size() && str[i] == '?'; i++);
				e = i;
				if (e < str.size()) {
					if (str[s]!='?' && str[e]!='?'&& str[s] != str[e]) result *= (e - s);
					result %= DIV;
				}
			}
		}

		cout << result << endl;
	}


	return 0;
}
