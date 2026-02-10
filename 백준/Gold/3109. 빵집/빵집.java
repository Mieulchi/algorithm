import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int R, C;
	static char[][] arr = new char[10000][500];
	static boolean[] visited = new boolean[10000];
	static boolean[][] cant = new boolean[10000][500];
	static int ans;

	static boolean go(int r, int c) {
		if (c != C - 1) {
			if (!cant[r][c]) {
				arr[r][c] = 'x';
				if (r - 1 >= 0 && arr[r - 1][c + 1] == '.') {
					if (go(r - 1, c + 1)) {
						return true;
					}
				}
				if (arr[r][c + 1] == '.') {
					if (go(r, c + 1)) {
						return true;
					}
				}
				if (r + 1 < R && arr[r + 1][c + 1] == '.') {
					if(go(r + 1, c + 1)) {
						return true;
					}
				}
				cant[r][c] = true;
				return false;
			}
			return false;
		} else {
			arr[r][c] = 'x';
			visited[r] = true;
			return true;
		}
	}

	static void solve() {
		for (int r = 0; r < R; ++r) {

			if (go(r, 0)) {
				++ans;

			}
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		st = new StringTokenizer(br.readLine().trim());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());

		for (int r = 0; r < R; ++r) {
			String line = br.readLine().trim();
			for (int c = 0; c < C; ++c) {
				arr[r][c] = line.charAt(c);
			}
		}

		solve();

		System.out.println(ans);
	}
}