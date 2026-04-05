import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	static int n;
	
	static int [] coins = new int[101];
	static int [] coinCount = new int[101];
	static boolean [] dp = new boolean[50001];
	static int[] used = new int[50001];
	
	static int sum;
	
	static void solve() {
		Arrays.fill(dp, 0, sum / 2 + 1, false);
		int ans = 0;
		dp[0] = true;
		for (int i = 1; i <= n; ++i) {

			Arrays.fill(used, 0, sum / 2 + 1, 0);
			
			int v = coins[i];
			int c = coinCount[i];
			
			for(int j = v; j <= sum / 2; ++j) {
				if (dp[j - v] && !dp[j] && used[j - v] < c) {
					dp[j] = true;
					used[j] = used[j - v] + 1;
				}
			}
			if (dp[sum / 2]) {
				ans = 1;
				break;
			}
		}

		sb.append(ans);
		
	}
	
	public static void main(String[] args) throws IOException {
		
		for (int tc = 0; tc < 3; ++tc) {
			n = Integer.parseInt(br.readLine().trim());
			sum = 0;
			
			for(int i = 1; i <= n; ++i) {
				st = new StringTokenizer(br.readLine().trim());
				coins[i] = Integer.parseInt(st.nextToken());
				coinCount[i] = Integer.parseInt(st.nextToken());
				
				sum += coins[i] * coinCount[i];
			}
			
			if (sum % 2 == 0) {
				solve();
			}
			else {
				sb.append(0);
			}
			sb.append('\n');
		}
		
		System.out.println(sb);
	}
}