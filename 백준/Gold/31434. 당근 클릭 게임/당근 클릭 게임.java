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

    //dp[k][j] = k초 지났고 보유량이 j일 때 가능한 최대 클릭당 수확량
    static int [][] dp = new int [101][5002];

    static int ans;

    static void solve() {

        dp[0][0] = 1;
        for (int i = 1; i <= K; i++) {
            for (int j = 5001; j >= 0; --j) {
                if (dp[i - 1][j] > 0) {
                    dp[i][j + dp[i - 1][j]] = Math.max(dp[i][j + dp[i - 1][j]], dp[i - 1][j]);
                    for (int k = 1; k <= N; ++k) {
                        if (j >= a[k] && dp[i - 1][j] > 0) {
                            dp[i][j - a[k]] = Math.max(dp[i][j - a[k]], dp[i - 1][j] + b[k]);
                        }
                    }
                }
            }
        }

        for (int i = 5001; i >= 0; --i) {
            if (dp[K][i] > 0) {
                ans = i;
                break;
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