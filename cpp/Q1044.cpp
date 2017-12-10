#include<stdio.h>  
#include<algorithm>  
#include<vector>  
#include<iostream>  
using namespace std;
struct A {
	int s;
	int e;
}buf[100002];
int input[100002];
int main() {
	//freopen("F://Temp/input.txt", "r", stdin);  
	int n, m;
	int min = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
		if (min < m)min += input[i];
	}
	int sum = 0;
	int idx = 0;
	for (int i = 0, j = 0; j <= n;) {
		if (sum < m) {
			sum += input[j];
			j++;
		}
		else {
			if (sum == min) {
				buf[idx].s = i;
				buf[idx].e = j - 1;
				idx++;
			}
			else if (sum < min) {
				min = sum;
				idx = 0;
				buf[idx].s = i;
				buf[idx].e = j - 1;
				idx++;
			}
			sum -= input[i];
			i++;
		}
	}
	for (int i = 0; i < idx; i++) {
		//cout << buf[i].s+1 << "-" << buf[i].e + 1 << endl;  
		printf("%d-%d\n", buf[i].s + 1, buf[i].e + 1);
	}
	return 0;
}