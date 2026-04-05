import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * Longest Common Subsequence
 * 
 */

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int ans;
	static String [] s = new String[3];
	static int [] len = new int[3];
	static int [][][] dp = new int[101][101][101];
	
	static void solve() {
		for(int i = 1; i <= len[0]; ++i) {
			for(int j = 1; j <= len[1]; ++j) {
				for(int k = 1; k <= len[2]; ++k) {
					if (s[0].charAt(i - 1) == s[1].charAt(j - 1) && 
						s[1].charAt(j - 1) == s[2].charAt(k - 1)) {
						dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
					}
					else {
						dp[i][j][k] = Math.max(dp[i - 1][j][k], Math.max(dp[i][j - 1][k], dp[i][j][k - 1]));
					}
				}
			}                 
		}
		
		sb.append(dp[len[0]][len[1]][len[2]]);
	}

	public static void main(String[] args) throws IOException {

		for(int i = 0;i < 3; ++i) {
			s[i] = br.readLine().trim();
			len[i] = s[i].length();
		}

		solve();
		
		System.out.println(sb);
	}
}