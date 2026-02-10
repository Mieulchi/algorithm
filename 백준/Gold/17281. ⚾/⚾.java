import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int n;

	static int[][] inning = new int[50][9];
	static int[] arr = new int[8];
	static int[] sub = new int[9];

	static int[] bases;
	static int ans;
	
	static class Pair {
		int t;
		int idx;
		public Pair(int t, int idx) {
			this.t = t;
			this.idx = idx;
		}
	}

	static int go(int num) {
		int score = 0;
		for (int i = 3; i >= 0; --i) {
			if (bases[i] > 0) {
				if (i + num > 3) {
					score++;
					bases[i] = 0;
				} else {
					bases[i + num] = 1;
					bases[i] = 0;
				}
			}
		}
		return score;
	}

	static void count_score() {
		
		int now = 0;
		int score = 0;
		
		sub[3] = 0;
		int idx = 0;
		for(int i = 0; i < 8; ++i) {
			sub[idx++] = arr[i];
			if (idx == 3) {
				++idx;
			}
		}

		for (int i = 0; i < n; ++i) {
			bases = new int[4];
			int out = 0;

			while (out < 3) {
				if (inning[i][sub[now]] == 0) {
					++out;
				} else {
					bases[0] = 1;
					score += go(inning[i][sub[now]]);
				}

				now++;
				now %= 9;
			}
			if (ans < score) {
				ans = score;
			}
		}
	}

	static boolean next_permutation() {
		int i = 7;

		while (i > 0 && arr[i - 1] >= arr[i]) {
			--i;
		}

		if (i <= 0) {
			return false;
		}

		int j = 7;
		while (arr[j] <= arr[i - 1]) {
			--j;
		}

		int tmp = arr[i - 1];
		arr[i - 1] = arr[j];
		arr[j] = tmp;

		int k = 7;
		while (i < k) {
			tmp = arr[i];
			arr[i] = arr[k];
			arr[k] = tmp;

			++i;
			--k;
		}

		return true;
	}

	static void solve() {

		for (int i = 1; i < 9; ++i) {
			arr[i - 1] = i;
		}

		do {
			count_score();
		} while (next_permutation());
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		n = Integer.parseInt(br.readLine().trim());

		for (int i = 0; i < n; ++i) {
			st = new StringTokenizer(br.readLine().trim());

			for (int j = 0; j < 9; ++j) {
				inning[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		solve();

		System.out.println(ans);
	}
}