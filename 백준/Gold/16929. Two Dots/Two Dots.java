import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import javax.swing.plaf.synth.SynthSeparatorUI;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int N, M;
	static char[][] map = new char[50][50];
	static int[][] visited = new int[50][50];
	static String ans = "No";
	static int sr, sc;
	static char ch;
	static int[] dr = { -1, 0, 1, 0 };
	static int[] dc = { 0, 1, 0, -1 };
	static int num;

	static void dfs(int r, int c, int cnt) {

		visited[r][c] = num;
		for (int dir = 0; dir < 4; ++dir) {
			int nr = r + dr[dir];
			int nc = c + dc[dir];

			if (nr >= 0 && nr < N && nc >= 0 && nc < M && map[nr][nc] == ch) {
				if (nr == sr && nc == sc && cnt >= 4) {
					ans = "Yes";
					return;
				}
				if (visited[nr][nc] != num) {
					visited[nr][nc] = num;
					dfs(nr, nc, cnt + 1);
				}
			}
		}
	}

	static void solve() {
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < M; ++c) {
				num++;
				sr = r;
				sc = c;
				ch = map[r][c];
				dfs(r, c, 1);
				if (ans.equals("Yes")) {
					break;
				}

			}
			if (ans.equals("Yes")) {
				break;
			}
		}
	}

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine().trim());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		for (int r = 0; r < N; ++r) {
			String s = br.readLine().trim();
			for (int c = 0; c < M; ++c) {
				map[r][c] = s.charAt(c);
			}
		}

		solve();

		System.out.println(ans);

	}
}
