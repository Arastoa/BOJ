#include <iostream>
#include <set>
#include <stdio.h>
#include <string>

using namespace std;

set<string> passwordSet;
set<char> cset;
string target = "";
void make_password(string str, int start,int jcount ,int mcount);
void print_strset();
int n;

int main(){
	int C;

	cin >> n >> C;

	for (int i = 0; i < C; i++){
		char data;
		cin >> data;
		cset.insert(data);
	}

	
	set<char>::iterator itr = cset.begin();
	while (itr != cset.end())
		target = target + *itr++;

	for (int i = 0; i < target.length() - n+1; i++)
		make_password("" ,i,0,0);
	print_strset();

	return 0;
}

void make_password(string str, int start, int jcount, int mcount){
	if (start == target.length()) return;
	

	str = str + target[start];
	int tmpj = jcount, tmpm = mcount;

	switch (target[start]){
	case 'i': case 'a': case 'e': case 'o':case 'u':
		tmpm++;
	default:
		tmpj++;
	}

	for (int i = start + 1; i < target.length(); i++)
		make_password(str, i,tmpj,tmpm);

	if (str.length() == n && tmpm && tmpj>=2){
		passwordSet.insert(str);
	}
}
void print_strset(){
	set<string>::iterator itr = passwordSet.begin();

	while (itr != passwordSet.end())
		cout << *itr++ << endl;

}
