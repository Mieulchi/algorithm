import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

/*
 * SW Academy
 * 
 * @author
 * 
 * 
 * 
 * 
 */

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	static int N, M, ans = Integer.MAX_VALUE;
	static int [][] map = new int[8][8];
	
	static int[] dirs = {4, 2, 4, 4, 1};
	
	static int num = 0;
	static int [] shapes = new int[8];
	static int [] cctvR = new int[8];
	static int [] cctvC = new int[8];
	
	static int [] dr = {-1, 0, 1, 0};
	static int [] dc = {0, 1, 0, -1};
	
	static int[][][] arrs = {{{0}, {1}, {2}, {3}}, 
							 {{0, 2}, {1, 3}},
							 {{0, 1}, {1, 2}, {2, 3}, {0, 3}},
							 {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}},
							 {{0, 1, 2, 3}}};
	
	static boolean checkRange(int r, int c) {
		if (r >= 0 && r < N && c >= 0 && c < M) {
			return true;
		}
		
		return false;
	}
	
	static void lazer(int sr, int sc, int shape, int [] arr, int v) {
		
		for(int i = 0; i < arr.length; ++i) {
			int r = sr;
			int c = sc;
			while(checkRange(r, c)) {
				if (map[r][c] == 6) {
					break;
				}
				if (map[r][c] % 10 == 0) {
					map[r][c] += v;
				}
				
				r += dr[arr[i]];
				c += dc[arr[i]];
			}
		}
	}
	
	static void dfs(int depth) {
		if (depth != num) {
			int shape = shapes[depth] - 1;
			for(int dir = 0; dir < dirs[shape]; ++dir) {
				lazer(cctvR[depth], cctvC[depth], shapes[depth], arrs[shape][dir], 10);
				dfs(depth + 1);
				lazer(cctvR[depth], cctvC[depth], shapes[depth], arrs[shape][dir], -10);
			}	
		}
		else {
			int cnt = 0;
			for(int r = 0; r < N; ++r) {
				for(int c = 0; c < M; ++c) {
					if (map[r][c] == 0) {
						cnt++;
					}
				}
			}
			ans = Math.min(ans, cnt);
		}
	}
	
	static void solve() {
		
		dfs(0);
		
		sb.append(ans);
		
	}
	
	public static void main(String[] args) throws IOException {
		
		st = new StringTokenizer(br.readLine().trim());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		for(int r = 0; r < N; ++r) {
			st = new StringTokenizer(br.readLine().trim());
			for(int c = 0; c < M; ++c) {
				map[r][c] = Integer.parseInt(st.nextToken());
				if (map[r][c] >= 1 && map[r][c] < 6) {
					shapes[num] = map[r][c];
					cctvR[num] = r;
					cctvC[num] = c;
					num++;
				}
			}
		}
		
		solve();
 		
		System.out.println(sb);
	}
}