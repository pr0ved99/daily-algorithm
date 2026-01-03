#include <stdio.h>

int main() {
    char code_str[15];
    scanf("%s", code_str);

    int sum = 0;
    int missing_weight = 0;

    // 1. 이미 있는 숫자들의 합 구하기
    for (int i = 0; i < 13; i++) {
        int weight = (i % 2 == 0) ? 1 : 3; // ISBN 가중치

        if (code_str[i] == '*') {
            missing_weight = weight; // * 자리의 가중치 저장
        } else {
            sum += (code_str[i] - '0') * weight; // 문자를 숫자로 변환하여 합산
        }
    }

    // 2. 0부터 9까지 넣어보며 10의 배수가 되는지 확인
    for (int i = 0; i <= 9; i++) {
        if ((sum + i * missing_weight) % 10 == 0) {
            printf("%d\n", i);
            return 0; // 정답을 찾으면 종료
        }
    }

    return 0;
}
