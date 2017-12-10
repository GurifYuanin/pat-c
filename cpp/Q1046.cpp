#include<iostream>
using namespace std;

int main() {
	int nodeNum, line, i, j, index, start, end;
	scanf("%d", &nodeNum);
	int *path = new int[nodeNum];
	int **dis = new int*[nodeNum];
	for (i = 0; i < nodeNum; i++) {
		dis[i] = new int[nodeNum];
		scanf("%d", &path[i]);
	}
	scanf("%d", &line);
	for (i = 0; i < nodeNum; i++) {
		dis[i][i] = 0;
		for (j = 1, index = i + 1; j < nodeNum; j++, index++) {
			dis[i][index % nodeNum] = dis[i][(index - 1) % nodeNum] + path[(index - 1) % nodeNum];
		}
	}
	for (i = 0; i < line; i++) {
		scanf("%d%d", &start, &end);
		start--;
		end--;
		printf("%d\n", dis[start][end] < dis[end][start] ? dis[start][end] : dis[end][start]);
	}
	return 0;
}