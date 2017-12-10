#include<iostream>
using namespace std;

int main() {
	int num, tmp;
	int arr[100001] = {0};
	scanf("%d", &num);
	int *order = new int[num];
	for (int i = 0; i < num; i++) {
		scanf("%d", &tmp);
		order[i] = tmp;
		arr[tmp]++;
	}
	for (int i = 0; i < num; i++) {
		if (arr[order[i]] == 1) {
			printf("%d", order[i]);
			return 0;
		}
	}
	printf("None");
	return 0;
}