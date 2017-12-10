#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

struct person{
	char id[14];
	int score;
	int location;
	int localRank;
	int allRank;
} people[30005];
bool cmp(person a, person b) {
	return (a.score > b.score) || (a.score == b.score && strcmp(a.id, b.id) < 0);
}
int main() {
	int count, num, i, j, k, sum;
	scanf("%d", &count);
	for (i = 0, j = 0, sum = 0; i < count; i++) {
		scanf("%d", &num);
		sum += num;
		for (; j < sum; j++) {
			scanf("%s%d", people[j].id, &people[j].score);
			people[j].location = i + 1;
		}
		sort(people + j - num, people + j, cmp);
		people[sum - num].localRank = 1;
		for (j = sum - num + 1, k = 2; j < sum; j++, k++) {
			if (people[j].score == people[j - 1].score) {
				people[j].localRank = people[j - 1].localRank;
			}
			else {
				people[j].localRank = k;
			}
			
		}
	}
	sort(people, people + j, cmp);
	printf("%d\n", sum);
	if (sum != 0) {
		people[0].allRank = 1;
		printf("%s %d %d %d\n", people[0].id, 1, people[0].location, people[0].localRank);
		for (i = 1; i < sum; i++) {
			if (people[i].score == people[i - 1].score) {
				people[i].allRank = people[i - 1].allRank;
			}
			else {
				people[i].allRank = i + 1;
			}
			printf("%s %d %d %d\n", people[i].id, people[i].allRank, people[i].location, people[i].localRank);
		}
	}
	return 0;
}