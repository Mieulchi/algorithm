import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;


public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static int N, K;
    static int [] a = new int [101];
    static int [] b = new int [101];

    //dp[k][j] = k초 지났고
    static int [][] dp = new int [101][5001];

    static int ans;

    static void solve() {

        for (int i = 0; i <= K; ++i) {
            for (int j = 0; j < 5001; ++j) {
                dp[i][j] = -1;
            }
        }

        dp[0][1] = 0;

        for (int i = 1; i <= K; i++) {
            for (int j = 5000; j >= 0; --j) {
                if (dp[i - 1][j] >= 0) {
                    dp[i][j] = j + dp[i - 1][j];
                    for (int k = 1; k <= N; ++k) {
                        if (dp[i - 1][j] >= a[k]) {
                            dp[i][j + b[k]] = Math.max(dp[i][j + b[k]], dp[i - 1][j] - a[k]);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 5001; ++i) {
            if (dp[K][i] > ans) {
                ans = dp[K][i];
            }
        }
    }

    public static void main(String[] args) throws NumberFormatException, IOException {

        st = new StringTokenizer(br.readLine().trim());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine().trim());
            a[i] = Integer.parseInt(st.nextToken());
            b[i] = Integer.parseInt(st.nextToken());
        }

        solve();

        System.out.println(ans);
    }
}