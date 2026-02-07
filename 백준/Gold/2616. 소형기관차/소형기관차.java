import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

/*
 *
 * SW Academy
 *
 * 1. DP를 잘 짜보자
 *    dp[i][j] = j번 열차가 i번까지 골랐을 때 최대 수송량
 * 2. dp[50000] ? 되려나
 * 3. 
 */

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static int N, M;
    static int [] sum = new int [50001];
    static int [][] dp = new int [50001][3];
    static int ans;

    static void solve() {
        for(int i = 1; i <= M; i++) {
            dp[i][0] = sum[i];
        }
        for (int i = M + 1; i <= N; i++) {
            dp[i][0] = Math.max(dp[i - 1][0], sum[i] - sum[i - M]);
            dp[i][1] = Math.max(dp[i - 1][1], dp[i - M][0] + sum[i] - sum[i - M]);
            dp[i][2] = Math.max(dp[i - 1][2], dp[i - M][1] + sum[i] - sum[i - M]);
        }
        ans = dp[N][2];
    }

    public static void main(String[] args) throws NumberFormatException, IOException {

        N = Integer.parseInt(br.readLine().trim());

        st = new StringTokenizer(br.readLine().trim());
        for (int i = 1; i <= N; ++i) {
            sum[i] = Integer.parseInt(st.nextToken());
            sum[i] += sum[i - 1];

        }
        M = Integer.parseInt(br.readLine().trim());

        solve();

        System.out.println(ans);
    }
}