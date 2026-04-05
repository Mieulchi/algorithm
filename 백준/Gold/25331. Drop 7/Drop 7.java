import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N;

	static int[][] arr = new int[7][7];
	static int[][] cpy = new int[7][7];
	
	static int ans = 50;
	
	static class Pair {
		int r, c;
		public Pair(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}

	public static boolean remove() {
		boolean ret = false;
		List<Pair> list = new ArrayList<>();
		for(int r = 0; r < 7; ++r) {
			int garo = 0;
			int sero = 0;
			for (int c = 0; c < 7; ++c) {
				if (cpy[r][c] != 0) {
					garo++;
				}
				else {
					if (garo > 0) {
						for(int i = c; i >= c - garo; --i) {
							if (cpy[r][i] == garo) {
								list.add(new Pair(r, i));
							}
						}
						garo = 0;
					}
				}
				
				if (cpy[c][r] != 0) {
					sero++;
				}
				else {
					if (sero > 0) {
						for(int i = c; i >= c - sero; --i) {
							if (cpy[i][r] == sero) {
								list.add(new Pair(i, r));
							}
						}
						sero = 0;
					}
				}
			}
			
			if (garo > 0) {
				for(int i = 6; i > 6 - garo; --i) {
					if (cpy[r][i] == garo) {
						list.add(new Pair(r, i));
					}
				}
			}
			if (sero > 0) {
				for(int i = 6; i > 6 - sero; --i) {
					if (cpy[i][r] == sero) {
						list.add(new Pair(i, r));
					}
				}
			}
		}
		for(int i = 0; i < list.size(); ++i) {
			int r = list.get(i).r;
			int c = list.get(i).c;
			cpy[r][c] = 0;
			ret = true;
		}
		
		return ret;
	}
	
	public static boolean move() {
		boolean ret = false;
		
		for(int r = 6; r > 0; --r) {
			for(int c = 0; c < 7; ++c) {
				if (cpy[r][c] == 0) {
					for(int i = 1; i <= r; ++i) {
						if (cpy[r - i][c] != 0) {
							cpy[r][c] = cpy[r - i][c];
							cpy[r - i][c] = 0;
							ret = true;			
							break;
						}
					}
				
				}
			}
		}
		
		return ret;
	}
	
	public static void solve() {
		for(int i = 0; i < 7; ++i) {
			
			for(int r = 0; r < 7; ++r) {
				for(int c = 0; c < 7; ++c) {
					cpy[r][c] = arr[r][c];
				}
			}
			
			cpy[0][i] = N;

			move();
			
			while(true) {
				boolean removed = remove();
				boolean moved = move();
				if (!moved && !removed) {
					break;
				}
			}
			
			int cnt = 0;
			for(int r = 0; r < 7; ++r) {
				for(int c = 0; c < 7; ++c) {
					if (cpy[r][c] != 0) {
						++cnt;
					}
				}
			}
			ans = Math.min(ans, cnt);
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		for (int r = 0; r < 7; ++r) {
			st = new StringTokenizer(br.readLine().trim());
			for (int c = 0; c < 7; ++c) {
				arr[r][c] = Integer.parseInt(st.nextToken());
			}
		}
		N = Integer.parseInt(br.readLine().trim());
		solve();
		System.out.println(ans);
	}
}
