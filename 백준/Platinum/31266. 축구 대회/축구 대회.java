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
 */

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static int N;
    static int [] a = new int [200001];
    static int [] b = new int [200001];
    static int [] c = new int [200001];
    static int [] d = new int [200001];

    //3rd arr means bitmasks 101 -> forward1, middle0, defence1
    static int [][][][] dp = new int [200001][12][8][2];

    static int ans;

    static void solve() {

        dp[1][1][1][0] = a[1];
        dp[1][1][2][0] = b[1];
        dp[1][1][4][0] = c[1];
        dp[1][1][0][1] = d[1];

        for (int i = 2; i <= N; i++) {
            for(int j = 1; j < 12; ++j) {
                for(int k = 1; k < 8; ++k) {

                    if (dp[i - 1][j - 1][k][0] > 0) {
                        // 1. forward
                        dp[i][j][k | 4][0] = Math.max(dp[i][j][k | 4][0], dp[i - 1][j - 1][k][0] + a[i]);

                        // 2. middle
                        dp[i][j][k | 2][0] = Math.max(dp[i][j][k | 2][0], dp[i - 1][j - 1][k][0] + b[i]);

                        // 3. defence
                        dp[i][j][k | 1][0] = Math.max(dp[i][j][k | 1][0], dp[i - 1][j - 1][k][0] + c[i]);

                        // 4. GK
                        dp[i][j][k][1] = Math.max(dp[i][j][k][1], dp[i - 1][j - 1][k][0] + d[i]);
                    }
                }
            }
        }

        ans = dp[N][11][7][1];
    }

    public static void main(String[] args) throws NumberFormatException, IOException {

        N = Integer.parseInt(br.readLine().trim());

        for (int i = 1 ; i <= N; ++i) {
            st = new StringTokenizer(br.readLine().trim());
            a[i] = Integer.parseInt(st.nextToken());
            b[i] = Integer.parseInt(st.nextToken());
            c[i] = Integer.parseInt(st.nextToken());
            d[i] = Integer.parseInt(st.nextToken());
        }

        solve();

        System.out.println(ans);
    }
}