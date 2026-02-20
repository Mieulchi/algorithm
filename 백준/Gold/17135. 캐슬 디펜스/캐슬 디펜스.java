import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static int[][] map = new int[15][15];
	static int[][] cpy = new int[15][15];
	static boolean[][] visited = new boolean[15][15];

	static int[] dr = { -1, 0, 0 };
	static int[] dc = { 0, 1, -1 };

	static int N, M, D, ans;

	static class Pair {
		int r;
		int c;

		public Pair(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}

	static Pair bfs(int idx) {
		
		for(int r = 0; r < N; ++r) {
			Arrays.fill(visited[r], false);
		}

		Queue<Pair> q = new ArrayDeque<>();
		q.add(new Pair(N - 1, idx));
		visited[N - 1][idx] = true;

		Pair pair = null;

		int cnt = 1;
		while (!q.isEmpty() && cnt <= D) {
			++cnt;
			int size = q.size();

			boolean found = false;

			int minC = 20;

			while (size-- > 0) {
				Pair front = q.poll();

				int r = front.r;
				int c = front.c;

				if (cpy[r][c] == 1) {
					found = true;
					if (c < minC) {
						pair = front;
						minC = c;
					}
				}

				for (int i = 0; i < 3; ++i) {
					int nextR = r + dr[i];
					int nextC = c + dc[i];
					if (nextR >= 0 && nextR < N && nextC >= 0 && nextC < M && !visited[nextR][nextC]) {
						q.add(new Pair(nextR, nextC));
						visited[nextR][nextC] = true;
					}
				}
			}
			if (found) {
				break;
			}

		}

		return pair;

	}

	static int simulate(int bitmask) {
		for (int r = 0; r < N; ++r) {
			for (int c = 0; c < M; ++c) {
				cpy[r][c] = map[r][c];
			}
		}

		int cnt = 0;

		int idx = 0;
		int[] archers = new int[3];
		for (int c = 0; c < M; ++c) {
			if (((bitmask >> c) & 1) == 1) {
				archers[idx++] = c;
			}
		}

		Pair[] pairs = new Pair[3];
		for (int time = 0; time <= N; ++time) {

			// 세 궁수 별 처치할 적 위치 탐색
			for (idx = 0; idx < 3; ++idx) {
				pairs[idx] = bfs(archers[idx]);
			}

			// 제거된 적 중복 검사 후 추가
			for (idx = 0; idx < 3; ++idx) {
				if (pairs[idx] != null) {
					boolean flag = true;
					for (int dup = 0; dup < idx; ++dup) {
						if (pairs[dup] != null) {
							if (pairs[idx].r == pairs[dup].r && pairs[idx].c == pairs[dup].c) {
								flag = false;
							}
						}
					}

					if (flag) {
						cpy[pairs[idx].r][pairs[idx].c] = 0;
						cnt++;
					}
				}
			}

			// 적 이동
			for (int r = N - 1; r > 0; --r) {
				for (int c = 0; c < M; ++c) {
					cpy[r][c] = cpy[r - 1][c];
				}
			}
			for (int c = 0; c < M; ++c) {
				cpy[0][c] = 0;
			}
		}

		return cnt;
	}

	static void dfs(int depth, int bitmask, int num) {
		if (depth != 3) {
			for (int idx = num; idx <= M - (3 - depth); ++idx) {
				dfs(depth + 1, bitmask + (1 << idx), idx + 1);
			}
		} else {
			ans = Math.max(ans, simulate(bitmask));
		}
	}

	static void solve() {
		for (int i = 0; i <= M - 3; ++i) {
			dfs(1, (1 << i), i + 1);
		}
	}

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine().trim());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());

		for (int r = 0; r < N; ++r) {
			st = new StringTokenizer(br.readLine().trim());
			for (int c = 0; c < M; ++c) {
				map[r][c] = Integer.parseInt(st.nextToken());
			}
		}

		solve();

		System.out.println(ans);
	}
}
