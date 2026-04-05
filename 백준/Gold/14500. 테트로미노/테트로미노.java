import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static BufferedReader br;
	static StringTokenizer st;
	static StringBuilder sb;
	static int n, m;
	static int arr[][];
	static int ans = 0;
	
	static int shapeR[][] = { { 0, 0, 0 }, { 1, 2, 3 }, { 1, 1, 0 }, { 1, 2, 2 }, {1, 2, 2 }, {0, 0, 1}, {0, 0, 1}, {0, 1, 2}, {0, 1, 2}, {0, 0, -1}, {1, 1, 1},  { 1, 1, 2 }, {1, 1, 2}, {0, -1, -1}, {0, 1, 1}, { 0, 0, 1 }, {-1, 0, 1}, {0, 0, -1}, {1, 1, 2} };
	static int shapeC[][] = { { 1, 2, 3 }, { 0, 0, 0 }, { 0, 1, 1 }, { 0, 0, 1 }, {0, 0, -1}, {1, 2, 0}, {1, 2, 2} , {1, 1, 1}, {1, 0, 0}, {1, 2, 2}, {0, 1, 2},  { 0, 1, 1 }, {0, -1, -1}, {1, 1, 2}, {1, 1, 2},  { 1, 2, 1 }, {1, 1, 1}, { 1, 2, 1}, {0, 1, 0} };
	
	static void solve() {
		for(int r = 0; r < n; ++r) {
			for(int c = 0; c < m; ++c) {
				for(int i = 0; i < 19; ++i) {
					boolean flag = true;
					int sum = arr[r][c];
					for(int j = 0; j < 3; ++j) {
						int checkR = r + shapeR[i][j];
						int checkC = c + shapeC[i][j];
						if (checkR >= n || checkR < 0 || checkC >= m || checkC < 0) {
							flag = false;
							break;
						}
						sum += arr[checkR][checkC];
					}
					if (flag) {
						ans = Math.max(ans, sum);
					}
				}
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		br = new BufferedReader(new InputStreamReader(System.in));
		sb = new StringBuilder();
		
		st = new StringTokenizer(br.readLine().trim());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		arr = new int[n][m];
		
		for (int i = 0; i < n; ++i) {
			st = new StringTokenizer(br.readLine().trim());
			for (int j = 0; j < m; ++j) {
				arr[i][j] = Integer.parseInt(st.nextToken()); 
			}
		}
		solve();
		
		System.out.println(ans);
	}

	
}
