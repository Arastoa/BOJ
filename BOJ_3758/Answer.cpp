#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Team{
public:
	int rank, total, log, count; // , id;
	int score[101];

	Team() {
		//memset(score, -1, sizeof(int)* 100);
		for (int i = 0; i < 101; i++)
			score[i] = -1;
		total = 0;
		count = 0;
	}
	void set(int num, int _score, int _log){
		log = _log;
		count++;
		if (score[num] > _score)
			return;
		else if (score[num] == -1){
			score[num] = _score;
			total += _score;
		}
		else{
			total += abs(score[num] - _score);
			score[num] = _score;
		}
	}
	bool operator< (const Team& rt){
		if (rt.total > total)
			return true;
		else if (rt.total == total && rt.count < count)
			return true;
		else if (rt.total == total && rt.count == count && rt.log < log)
			return true;

		return false;
	}
};

int main(void){
	int T, rank, my, num, id, score, k, entry, n;
	vector<Team> teams;

	cin >> T;
	for (int i = 0; i < T; i++){
		cin >> n >> k >> my >> entry;
		teams.resize(n);
		my--;
		rank = 1;
		
		for (int j = 0; j < entry; j++){
			cin >> id; cin >> num; cin >> score;
			teams[id - 1].set(num, score, j + 1);
		}

		for (int j = 0; j < teams.size(); j++)
		if (j != my && teams[my] < teams[j]){
			rank++;
			
		}
		cout << rank << endl;
		teams.clear();
	}

	return 0;
}
