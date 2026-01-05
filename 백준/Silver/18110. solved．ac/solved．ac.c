/*
# 18110 solved.ac
start:	22:04
end:

[문제]
	백준 온라인 저지의 문제들에는 난이도 표기가 없어서 무슨 문제를 풀어야 할지
	판단하기 곤란했기에 solved.ac가 만들어졌다.

	어떤 문제의 난이도는 그 문제를 푼 사람들이 제출한 난이도 의견을 바탕으로
	결정. 난이도 의견은 그 사용자가 생각한 난이도를 의미하는 정수 하나로 주어진다.
	solved.ac가 사용자들의 의견을 바탕으로 난이도를 경정하는 방식은 다음과 같다.

		-	아직 아무 의견이 없다면 문제의 난이도는 0으로 결정
		-	의견이 하나 이상 있다면, 문제의 난이도는 모든 사람의 난이도 의견의 30%
			절사평균으로 결정한다.

			절사평균이란 극단적인 값들이 평균을 왜곡하는 것을 막기 위해 가장
			큰 값들과 가장 작은 값들을 제외하고 평균을 나타내는 것을 말한다.
			30% 절사평균의 경우 위에서 15%, 아래에서 15%를 각각 제외하고
			평균을 계산한다.
			따라서 20명이 투표했다면, 가장 높은 난이도에 투표한 3명과
			가장 낮은 난이도에 투표한 3명의 투표는 평균 계산에 반영하지 않는다

			제외되는 사람의 수는 위, 아래에서 각가 반올림한다.
			25명이 투표한 경우 위, 아래에서 각각 3.75명을 제외해야 하는데,
			이 경우 반올림해 4명씩을 제외한다.

			마지막으로, 계산된 평균도 정수로 반올림된다. 절사평균이 16.7이
			었다면 최종 난이도는 17이 된다.

	사용자들이 어떤 문제에 제출한 난이도 의견 목록이 주어질 때, solved.ac가
	결정한 문제의 난이도를 계산하는 프로그램을 작성하시오.

[아이디어 1]
	n이 입력되면 n의 15%는 얼마인지 계산한다. (반올림 되어야 하므로 double형
	사용)
	qsort 이후 n의 15%의 반올림한 사이즈만큼의 앞뒤값을 뺀 값의 평균을 구한다.

*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	int n;
	if (scanf("%d", &n) == EOF || n == 0) {
		printf("0\n");
		return 0;
	}

	int* levels = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &levels[i]);
	}

	qsort(levels, n, sizeof(int), compare);

	int size = (int)round(n * 0.15);

	double sum = 0;
	for (int i = size; i < n - size; i++) {
		sum += levels[i];
	}

	int count = n - (2 * size);
	if (count <= 0) {
		printf("0\n");
	}
	else {
		printf("%d\n", (int)round(sum / count));
	}

	free(levels);
	return 0;
}