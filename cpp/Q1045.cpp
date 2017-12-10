#include<iostream>
using namespace std;


int main() {
	int len1, len2;
	scanf("%d%d", &len1, &len1);
	len1++;
	int *arr1 = new int[len1];
	for (int i = 1; i < len1; i++) {
		scanf("%d", &arr1[i]);
	}
	scanf("%d", &len2);
	len2++;
	int *arr2 = new int[len2];
	for (int i = 1; i < len2; i++) {
		scanf("%d", &arr2[i]);

	}
	// Initial the table
	int **table = new int*[len1];
	for (int i = 0; i < len1; i++) {
		table[i] = new int[len2];
		table[i][0] = 0;
	}
	for (int i = 0; i < len2; i++) {
		table[0][i] = 0;
	}
	// Write the able
	for (int i = 1; i < len1; i++) {
		for (int j = 1; j < len2; j++) {
			if (arr1[i] == arr2[j]) {
				table[i][j] = table[i][j - 1] + 1;
			}
			else {
				table[i][j] = table[i][j - 1] > table[i - 1][j] ? table[i][j - 1] : table[i - 1][j];
			}
		}
	}
	printf("%d", table[len1 - 1][len2 - 1]);
	return 0;
}

