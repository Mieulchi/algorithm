import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N, M, A, B;
	static int[][] arr = new int[100][100];
	static int[][][] dp = new int[100][100][201];

	static int mx, ans;

	public static void solve() {
		dp[0][0][0] = 1;
		dp[0][0][1] = arr[0][0];
		for (int i = 1; i < N; i++) {
			if (arr[i][0] == 2) {
				break;
			}
			for (int j = 0; j < 200; ++j) {
				if (dp[i - 1][0][j] > 0) {
					dp[i][0][j + arr[i][0]] = dp[i - 1][0][j];
				}
			}

		}
		for (int c = 1; c < M; ++c) {
			if (arr[0][c] != 2) {
				for (int j = 0; j < 200; ++j) {
					if (dp[0][c - 1][j] > 0) {
						dp[0][c][j + arr[0][c]] += dp[0][c - 1][j];
					}

				}
			}
			for (int r = 1; r < N; ++r) {
				if (arr[r][c] != 2) {
					for (int j = 0; j < 200; ++j) {
						if (dp[r - 1][c][j] > 0) {
							dp[r][c][j + arr[r][c]] += dp[r - 1][c][j];
						}
						if (dp[r][c - 1][j] > 0) {
							dp[r][c][j + arr[r][c]] += dp[r][c - 1][j];
						}

					}
				}
			}
		}
		for (int i = 200; i >= 0; --i) {
			if (dp[N - 1][M - 1][i] > 0) {
				ans = dp[N - 1][M - 1][i];
				break;
			}
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		st = new StringTokenizer(br.readLine().trim());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		A = Integer.parseInt(st.nextToken());
		B = Integer.parseInt(st.nextToken());

		int r, c;
		for (int i = 0; i < A; ++i) {
			st = new StringTokenizer(br.readLine().trim());
			r = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			arr[r - 1][c - 1] = 1;
		}
		for (int i = 0; i < B; ++i) {
			st = new StringTokenizer(br.readLine().trim());
			r = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			arr[r - 1][c - 1] = 2;
		}

		solve();

		System.out.println(ans);
	}
}