#include <iostream>
#include <set>

using namespace std;

bool decision(const set<int> stable, int horeses, int gap);
int optimize(const set<int> stable, int horses);

int main(){
	int n, horses;
	cin >> n >> horses;
	set<int> stable;

	for (int i = 0; i < n; i++){
		int data;
		cin >> data;
		stable.insert(data);
	}
	cout << optimize(stable, horses) << endl;
	return 0;
}

bool decision(const set<int> stable, int horeses, int gap){
	set<int>::iterator itr = stable.begin();
	int limit = -1;
	int put = 0;
	while (itr != stable.end()){
		if (limit <= *itr){
			put++;
			limit = *itr + gap;
		}
		itr++;
	}
	return put >= horeses;
}
int optimize(const set<int> stable, int horses){
	int lo = 0, hi = 1000000001;
	for (int it = 0; it < 100; it++){
		int mid = (lo + hi) / 2;
		if (decision(stable, horses, mid))
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}
