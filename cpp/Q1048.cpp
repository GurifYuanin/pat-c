#include<iostream>
using namespace std;

int main() {
	int length, pay, tmp;
	bool coin[100001] = {false};
	scanf("%d%d", &length, &pay);
	for (int i = 0; i < length; i++) {
		scanf("%d", &tmp);
		coin[tmp] = true;
	}
	for (int i = 1; i <= pay / 2; i++) {
		if (coin[i] && coin[pay - i]) {
			printf("%d %d", i, pay - i);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}