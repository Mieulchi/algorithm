import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int N, ans, total;
    static int [] arr = new int[1002];

    static int [][] dp = new int[1002][1002];
    static int [] sum = new int[1002];
    
    static void solve() {
        for (int i = 1; i <= N; i++) {
            sum[i] = sum[i - 1] + arr[i];
            for(int j = 1; j <= N; j++) {
                dp[i][j] = 0;
            }
        }

        ans = 0;

        for (int i = 1; i <= N; i++) {
            for(int j = 1; j <= N - i + 1; j++) {
                int s = sum[j + i - 1] - sum[j - 1];
                dp[j][j + i - 1] = s - Math.min(dp[j + 1][j + i - 1], dp[j][j + i - 2]);
            }
        }

        ans = dp[1][N];
    }

    public static void main(String[] args) throws IOException {
        int T;
        T = Integer.parseInt(br.readLine().trim());

        while(T-- > 0) {
            N = Integer.parseInt(br.readLine().trim());
            total = 0;

            st = new StringTokenizer(br.readLine().trim());

            for(int i = 1; i <= N; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
                total += arr[i];
            }

            solve();

            sb.append(ans).append('\n');
        }


        System.out.println(sb);
    }
}
