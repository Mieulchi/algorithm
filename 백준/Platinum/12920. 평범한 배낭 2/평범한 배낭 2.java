import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int N, M, ans;
    static List<Stuff> stuff = new ArrayList<>();

    static int [] dp;

    static class Stuff {
        int V, C, K;
        public Stuff(int V, int C, int K) {
            this.V = V;
            this.C = C;
            this.K = K;
        }
    }

    public static void solve() {
        for (int i = 0; i < N; i++) {
            int v = stuff.get(i).V;
            int c = stuff.get(i).C;
            int k = stuff.get(i).K;

            for(int count = 1; k > 0; count *= 2) {
                int usage = Math.min(count, k);

                int weight = v * usage;
                int value = c * usage;

                for(int j = M; j >= weight; j--) {
                    dp[j] = Math.max(dp[j], dp[j - weight] + value);
                    ans = Math.max(ans, dp[j]);
                }
                k -= usage;
            }

        }
    }

    public static void main(String args[]) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine().trim());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        dp = new int [M + 1];

        for (int i = 0; i < N; ++i) {
            st = new StringTokenizer(br.readLine().trim());
            int v = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            stuff.add(new Stuff(v, c, k));
        }
        solve();
        System.out.println(ans);

    }
}