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
	static List<Integer>[] list = new ArrayList[100001];
	static int [] dp = new int[100001];
	
	static int dfs(int prev, int node) {
		
		boolean flag = false;
		dp[node] = 1;
		
		for(int next : list[node]) {
			if (next != prev) {
				dp[node] += dfs(node, next);
			}
		}
		
		return dp[node];
	}
	
	static void solve() {
		dp[R] = dfs(R, R);
	}

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine().trim());

		N = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		Q = Integer.parseInt(st.nextToken());

		for (int i = 1; i <= N; ++i) {
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
		
		while (Q-- > 0) {
			a = Integer.parseInt(br.readLine().trim());
			sb.append(dp[a]).append('\n');
		}

		System.out.println(sb);

	}
}
