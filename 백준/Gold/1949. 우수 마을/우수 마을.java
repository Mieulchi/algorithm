import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int N, R, Q;
	static List<Integer>[] list = new ArrayList[10001];
	static int [] arr = new int [10001];
	static int [][] dp = new int[10001][2];
	
	static void dfs(int prev, int node) {
		
		dp[node][1] = arr[node];

		for(int next : list[node]) {
			if (next != prev) {
				dfs(node, next);
				dp[node][1] += dp[next][0];
				dp[node][0] += Math.max(dp[next][0], dp[next][1]);
			}
		}
		
	}
	
	static void solve() {
		dfs(1, 1);
		sb.append(Math.max(dp[1][0], dp[1][1]));
	}

	public static void main(String[] args) throws IOException {
		
		N = Integer.parseInt(br.readLine().trim());
		
		st = new StringTokenizer(br.readLine().trim());
		for (int i = 1; i <= N; ++i) {
			arr[i] = Integer.parseInt(st.nextToken());
			list[i] = new ArrayList<>();
		}
		
		int a, b;
		for (int i = 0; i < N - 1; ++i) {
			st = new StringTokenizer(br.readLine().trim());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			list[a].add(b);
			list[b].add(a);
		}
		
		solve();

		System.out.println(sb);

	}
}
