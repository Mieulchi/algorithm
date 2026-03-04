import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * 
 * dp[i][j][80] = i행 j열에서 k개까지 얻을 수 있는 경우의 수.
 * 
 * target 문자열의 0번 인덱스부터 돌면서 최대 1만 칸을 순회하면서 dp 해보자 
 *  80 x 10000 x 5 x 4 = 4 000 000 * 4 = 16 000 000
 */

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	static int N, M, K;
	static char [][] arr = new char[100][100];
	static String str;
	static int [] dr = {-1, 0, 1, 0};
	static int [] dc = {0, 1, 0, -1};
	static int ans;
	
	static int [][][] dp = new int[100][100][80];
	
	static void solve() {
		
		for(int r = 0; r < N; ++r) {
			for(int c = 0; c < M; ++c) {
				if (arr[r][c] == str.charAt(0)) {
					dp[r][c][0]++;	
				}
			}
		}
		
		int len = str.length();
		
		for(int i = 1; i < len; ++i) {
			for(int r = 0; r < N; ++r) {
				for(int c = 0; c < M; ++c) {
					if (arr[r][c] == str.charAt(i)) {
						for(int dir = 0; dir < 4; ++dir) {
							for(int k = 1; k <= K; ++k) {
								int nextR = r + k * dr[dir];
								int nextC = c + k * dc[dir];
								if (nextR < N && nextR >= 0 && nextC < M && nextC >= 0) {
									dp[r][c][i] += dp[nextR][nextC][i - 1];	
								}	
							}	
						}	
					}
				}
			}
		}
		
		for(int r = 0; r < N; ++r) {
			for(int c = 0; c < M; ++c) {
				ans += dp[r][c][len - 1];
			}
		}
		sb.append(ans);
	}
	
	public static void main(String[] args) throws IOException {
	
		st = new StringTokenizer(br.readLine().trim());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		for(int i = 0; i < N; ++i) {
			String line = br.readLine().trim();
			for(int j = 0; j < M; ++j) {
				arr[i][j] = line.charAt(j);
			}
		}
		str = br.readLine().trim();
		
		solve();
		
		System.out.println(sb);
	}
}
