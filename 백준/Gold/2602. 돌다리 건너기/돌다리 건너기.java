import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	static String str, angel, demon;
	static int N;
	
	// dp[i][j][k] = i에 따라 천사/악마, j번까지 왓을 때 k까지 완성한 경우의 수
	static int[][][] dp = new int[2][100][20];
	
	static void solve() {
		N = angel.length();
		int len = str.length();
		
		if (angel.charAt(0) == str.charAt(0)) {
			dp[0][0][0] = 1;
		}
		if (demon.charAt(0) == str.charAt(0)) {
			dp[1][0][0] = 1;
		}
		
		for(int i = 1 ; i < N; ++i) {
			for(int j = 0; j < len; ++j) {
				dp[0][i][j] = dp[0][i - 1][j];
				dp[1][i][j] = dp[1][i - 1][j];
			}
			if (angel.charAt(i) == str.charAt(0)) {
				dp[0][i][0]++;
			}
			if (demon.charAt(i) == str.charAt(0)) {
				dp[1][i][0]++;
			}
			
			for(int j = 1 ; j < len; ++j) {
				if (angel.charAt(i) == str.charAt(j)) {
					dp[0][i][j] += dp[1][i - 1][j - 1];
				}
				if (demon.charAt(i) == str.charAt(j)) {
					dp[1][i][j] += dp[0][i - 1][j - 1];
				}
			}
		}
		sb.append(dp[0][N - 1][len - 1] + dp[1][N - 1][len - 1]);
	}
	
	public static void main(String[] args) throws IOException {
		str = br.readLine().trim();
		angel = br.readLine().trim();
		demon = br.readLine().trim();
		
		solve();
		
		System.out.println(sb);
	}
}
