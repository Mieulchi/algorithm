#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// section_len은 배열 section의 길이입니다.
int solution(int n, int m, int section[], size_t section_len) {
    int answer = 0;
    int location=section[0] + m - 1;
    answer++;
    for(int i=1; i<section_len;i++) {
        if (section[i] <= location) {
            continue;
        }
        else {
            answer++;
            location = section[i] + m -1;
        }
    }
    return answer;
}