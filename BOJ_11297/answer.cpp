#include <iostream>
#include <string>
#include <stdio.h>
#define DIV 25

using namespace std;

int main() {

	while (1) {
		int m, d, y; cin  >> d >> m >> y;
		if (m == 0 && d == 0 && y == 0) break;
		int cy = d+m+y;
		
		cy %= DIV;
		cy++;
		char ch; getchar();
		while ((ch = getchar()) != '\n') {
			if (ch <'a' || ch>'z') {
				printf("%c",ch);
				continue;
			}
			ch = (ch - cy);
			if (ch < 'a') ch = ch+DIV+1;
			printf("%c", ch);
		}
		printf("\n");
	}

	return 0;
}
