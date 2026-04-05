import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


/*
 *
 * dp[i] = i개를 놓는 경우의 정답
 *
 * dp[1] = 1
 * dp[2] = 일단 2를 오른쪽에 놔
 * 1을 넣고 2를 넣기 -> 1 2를 먼저 넣고 1을 넣기 -> 2
 * dp[3] = 2, 3을 놓는 경우 : dp[2] = 3(두 개인 경우)
 * 1을 넣어보면 1을 맨 앞에 : 3(dp[2])
 * 2, 3을 넣는 중간에 1을 넣는 경우 : x 2 가능 -> 3 * 2(중간) + 3 * 2(맨 뒤)
 * dp[4] = 2, 3, 4가 놓여있고 1을 끼워넣어
 * 맨앞 : dp[3] = 15
 * 2, 3, 4의 중간에 1을 넣는 경우 : x2 가능 -> 15 x 2 + 15 x 2 + 15 x 2
 *
 */

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static final int MOD = 1000000009;
    static int N;

    static void solve() {
        long ans = 1;
        for(int i = 2; i <= N; i++) {
            ans = ans * (i * 2 - 1);
            ans %= MOD;
        }
        sb.append(ans);
    }

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine().trim());

        solve();

        System.out.println(sb);
    }
}
