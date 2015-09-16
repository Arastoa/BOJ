#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>
 
using namespace std;
 
typedef struct Kaprekar {
    int count;
    int num;
 
    int max[4];
    int min[4];
     
    int cal_count(){
        if (num == 6174)
            return count;
 
        count++;
        for (int i = 0; i < 4; i++){
            max[i] = num / pow(10, 3 - i);
 
            num -= max[i] * pow(10, 3 - i);
        }
        for (int i = 0; i < 4; i++){
            min[i] = max[i];
        }
 
 
        sort(max, max + 4, greater<int>());
        sort(min, min + 4);
 
        int mNum = 0;
        int nNum = 0;
 
        for (int i = 0; i < 4; i++){
            mNum += max[i] * pow(10, 3 - i);
        }
 
        for (int i = 0; i < 4; i++){
            nNum += min[i] * pow(10, 3 - i);
        }
        num = mNum - nNum;
 
        return cal_count();
    }
 
}Kaprekar;
 
int main(void){
 
    Kaprekar k;
 
    int n,num;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> k.num;
         
        k.count = 0;
        cout << k.cal_count() << endl;
         
    }
 
    return 0;
}
