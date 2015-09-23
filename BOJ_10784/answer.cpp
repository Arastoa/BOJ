#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;

double price(int k);
double p, a, b, c, d;
int n;
int main(){

	cin >> p >> a >> b >> c >> d>>n;
	double maxPoint = 0, result=0;

	for (int i = 1; i <= n; i++){
		double temp = price(i);
		maxPoint = max(maxPoint, temp);
		result = max(result, maxPoint - temp);
	}

	printf("%.6lf\n", result);

	return 0;
}

double price(int k){
	return p*(sin(a*(double)k + b) + cos(c*(double)k + d) + 2);
}
