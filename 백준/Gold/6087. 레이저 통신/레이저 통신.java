import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static final int INF = 1_000_000_007;
	static int W, H, ans = INF;

	static int [][] map = new int[100][100];
	static int [][][] visited = new int[100][100][4];

	static int[] dr = { -1, 0, 1, 0 };
	static int[] dc = { 0, 1, 0, -1 };
	
	static int sr = -1, sc = -1, er = -1, ec = -1;

	static class Pair{
		int r;
		int c;
		int dir;
		int v;
		public Pair(int r, int c, int dir, int v) {
			this.r = r;
			this.c = c;
			this.dir = dir;
			this.v = v;
		}
	}
	
	
	static void solve() {

		Deque<Pair> q = new ArrayDeque<>();
		
		for(int i = 0; i < 4; ++i) {
			q.add(new Pair(sr, sc, i, 0));
			visited[sr][sc][i] = 0;
		}
		
		while(!q.isEmpty()) {
			int size = q.size();
			while(size-- > 0) {
				Pair front = q.poll();
				
				int r = front.r;
				int c = front.c;
				int v = front.v;
				int prevDir = front.dir;
				
				if (visited[r][c][prevDir] < v) {
					continue;
				}
				
				if (r == er && c == ec) {
					ans = Math.min(ans, v);
					break;
				}
				
				for(int dir = 0; dir < 4; ++dir) {
					int nr = r + dr[dir];
					int nc = c + dc[dir];
					int nextCnt = visited[r][c][prevDir] + (dir == prevDir ? 0 : 1);
					
					if (nr >= 0 && nr < H && nc >= 0 && nc < W && map[nr][nc] != -1) {
						if (visited[nr][nc][dir] > nextCnt) {
							visited[nr][nc][dir] = nextCnt;
							if (dir == prevDir) {
								q.addFirst(new Pair(nr, nc, dir, nextCnt));
							}
							else {
								q.addLast(new Pair(nr, nc, dir, nextCnt));
							}	
						}
					}
				}
			}
			if (ans != INF) {
				break;
			}
		}
		
		sb.append(ans);
	}

	public static void main(String[] args) throws IOException {

		st = new StringTokenizer(br.readLine().trim());

		W = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());

		for (int r = 0; r < H; ++r) {
			String line= br.readLine().trim();
			for (int c = 0; c < W; ++c) {
				for(int i = 0; i < 4; ++i) {
					visited[r][c][i] = INF;
				}
				Character ch = line.charAt(c);

				if (ch == '*') {
					map[r][c] = -1;
				}
				else if (ch == 'C') {
					if (sr == - 1) {
						sr = r;
						sc = c;
					}
					else {
						er = r;
						ec = c;
					}
				}
			}
		}

		solve();

		System.out.println(sb);
	}
}