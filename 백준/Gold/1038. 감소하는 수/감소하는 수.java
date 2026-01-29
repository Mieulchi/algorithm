import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;


class Main {
	static BufferedReader br;
	static StringTokenizer st;
	static StringBuilder sb;
	static long N, ans;
	static int[][] dp = new int[11][10];

	public static void find(int cnt, int i, int j) {
		if (i - 1 > 0) {
			for (int o = 0; o < j; ++o) {
				cnt += dp[i - 1][o];
				if (cnt >= N) {
					System.out.print(o);
					find(cnt - dp[i - 1][o], i - 1, j - 1);
					return;
				}
			}
		}
	}

	public static boolean solve() {
		dp[1][0] = 1;
		int cnt = 0;
		for (int i = 1; i < 10; ++i) {
			dp[1][i]++;
			cnt++;
		}
		for (int i = 2; i < 11; ++i) {
			for (int j = i - 1; j < 10; ++j) {
				for (int k = 0; k < j; ++k) {
					dp[i][j] += dp[i - 1][k];
				}
				cnt += dp[i][j];
				if (cnt >= N) {
					System.out.print(j);
					find(cnt - dp[i][j], i, j);
					return true;
				}
			}
		}
		return false;
	}

	public static void main(String args[]) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		sb = new StringBuilder();

		// st = new StringTokenizer(br.readLine().trim());
		N = Integer.parseInt(br.readLine());
		if (N < 10) {
			System.out.println(N);
		} else {
			if (!solve()) {
				System.out.println(-1);
			}
		}

	}
}