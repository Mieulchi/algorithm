#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int r[101];
int c[101];
int dst[101];
int end[101];

int solution(int** points, size_t points_rows, size_t points_cols, int** routes, size_t routes_rows, size_t routes_cols) {
    int answer = 0;
    int n = routes_rows;
    for(int i = 0; i < n; i++) {
        r[i] = points[routes[i][0] - 1][0];
        c[i] = points[routes[i][0] - 1][1];
        dst[i] = 1;
    }
    
    int cnt = n;
    while (cnt) {
        int tot = 0;
        for(int i = 0; i < 101; i++) {
            for(int j = 0; j < 101; j++) {
                int count = 0;
                for(int k = 0; k < n; k++) {
                    if (!end[k] && r[k] == i && c[k] == j) {
                        count++;
                    }
                }
                if (count > 1) {
                    answer++;
                }
                tot += count;
            }
            if (tot >= n) {
                break;
            }
        }
        for(int i = 0; i < n; i++) {
            if (dst[i] == routes_cols) {
                if (!end[i]) {
                    end[i] = 1;
                    cnt--;
                }
            }
            else {
                if (r[i] < points[routes[i][dst[i]] - 1][0]) {
                    r[i]++;
                }
                else if (r[i] > points[routes[i][dst[i]] - 1][0]) {
                    r[i]--;
                }
                else {
                    if (c[i] < points[routes[i][dst[i]] - 1][1]) {
                        c[i]++;
                    }
                    else if (c[i] > points[routes[i][dst[i]] - 1][1]) {
                        c[i]--;
                    }
                }
                if (r[i] == points[routes[i][dst[i]] - 1][0] && c[i] == points[routes[i][dst[i]] - 1][1]) {
                    dst[i]++;
                }
            }
        }
    }
    
    return answer;
}