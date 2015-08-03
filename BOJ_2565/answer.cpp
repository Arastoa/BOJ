#include <iostream>
#include <set>
#include <vector>

#define MaxSize 501

using namespace std;

int lis[MaxSize], size=0;

void setLIS(set<pair<int,int> >& data);

int main(){
	

	int n; cin >> n;
	set<pair<int, int> > s;
	vector<int> lis;

	for(int i=0 ; i< n ; i++){
		int a, b; cin >> a >> b;

		s.insert(make_pair(a, b));
	}

	setLIS(s);
	cout << s.size() - size << endl;

	return 0;
}

void setLIS(set<pair<int, int> >& data)
{
	int s, e, m;
	lis[0] = -1;
	for (set<pair<int, int> >::iterator itr = data.begin(); itr != data.end(); itr++)
	{
		if (lis[size] < itr->second) lis[++size] = itr->second;
		else
		{
			s = 1;
			e = size;
			while (s <= e)
			{
				m = (s + e) / 2;
				if (lis[m] == itr->second) break;
				else if (lis[m] < itr->second) s = m + 1;
				else e = m - 1;
			}
			m = (s + e) / 2;
			if (lis[m] >= itr->second) lis[m] = itr->second;
			else lis[m + 1] = itr->second;
		}
	}
}
