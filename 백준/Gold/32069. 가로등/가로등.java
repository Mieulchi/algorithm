import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static long [] arr = new long [300000];

	static List<Integer> lights = new ArrayList<>();
	
	static long L;
	static int N, K;
	
	static void solve() {
		for(int i = 0; i < Math.min(N, K); ++i) {
			lights.add(0);
		}
		
		for(int i = 1 ; i <= K && lights.size() < K; ++i) {
			for (int j = 0; j < N; ++j) {
				if (j == 0 || j == N - 1) {
					if (j == 0) {
						if (arr[j] - i >= 0) {
							lights.add(i);
						}
					}
					if (j == N - 1) {
						if (arr[j] + i <= L) {
							lights.add(i);
						}
					}
				}
				if (j != N - 1 && arr[j] + i <= arr[j + 1] - i) {
					if (arr[j] + i == arr[j + 1] - i) {
						lights.add(i);
					} 
					else {
						lights.add(i);
						lights.add(i);
					}
				}				
				
				if (lights.size() >= K) {
					break;
				}
			}
		}
	}
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		st = new StringTokenizer(br.readLine().trim());
		
		L = Long.parseLong(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine().trim());
		for(int i = 0; i < N; ++i) {
			arr[i] = Long.parseLong(st.nextToken());
		}

		solve();

		for(int i = 0 ; i < K; ++i) {
			sb.append(lights.get(i) + " \n");
		}
		
		System.out.println(sb);
	}
}
 