#include<vector>
using namespace std;

bool solution(vector<int> arr)
{
	bool answer = true;
    int size = arr.size();
    
    int collect = 0;
    int compare = 0;
    for(int i=1 ; i<= size ; i++)
        collect^=i;
    
    for(int i=0 ; i< size; i++)
        compare ^= arr[i];
    
    answer = collect == compare;
    
	return answer;
}
