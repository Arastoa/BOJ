#include <iostream>
#include <vector>


using namespace std;

void swap(int& a, int& b);
void heap(vector<int>& vt,int n);

int main(){
	
	int n; cin >> n;
	vector<int> vt;
	vt.push_back(1);

	for (int i = 2; i <= n; i++){
		vt.push_back(i);
		swap(vt[vt.size() - 2], vt[vt.size() - 1]);
		heap(vt, vt.size() - 2);

	}


	for (int i = 0; i < vt.size(); i++)
		cout << vt[i] << (i == vt.size() - 1 ? '\n' : ' ');
		 
	return 0;
}


void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

void heap(vector<int>& vt, int n){
	if (n == 0) return;

	int here = n;
	while (vt[(here - 1) / 2] < vt[here]){
		swap(vt[here], vt[(here-1) / 2]);
		here--;
		here /= 2;
	}
}
