#include<iostream>
using namespace std;

int main() {
	int len1, len2, len, i, j, k;
	scanf("%d", &len1);
	long int *arr1 = new long int[len1];
	for (i = 0; i < len1; i++) {
		scanf("%ld", &arr1[i]);
	}
	scanf("%d", &len2);
	long int *arr2 = new long int[len2];
	for (i = 0; i < len2; i++) {
		scanf("%ld", &arr2[i]);
	}
	len = len1 + len2;
	long int *arr = new long int[len];
	for (i = 0, j = 0, k = 0; i < len1 && j < len2;) {
		if (arr1[i] < arr2[j]) {
			arr[k++] = arr1[i++];
		}
		else {
			arr[k++] = arr2[j++];
		}
	}
	while (i < len1) {
		arr[k++] = arr1[i++];
	}
	while (j < len2) {
		arr[k++] = arr2[j++];
	}
	printf("%ld", arr[(len - 1) / 2]);
	return 0;
}