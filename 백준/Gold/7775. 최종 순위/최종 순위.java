import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	static int n, p, k, d;
	static int [] arr = new int[1000];
	
	//p가 d개의 수로 표현 되는지만  확인하면 돼
	static void solve() {
		if (d == 1) {
			for(int i = 0; i < k; ++i) {
				arr[i] = p / k;
			}
			//남음
			int left = p - (k * (p / k));
			if (left > 0) {
				if (k == n || p / k < left) {
					sb.append("Wrong information");
					return;
				}
				else {
					arr[k] = left;
				}
			}
		}
		else {
			if (p >= (d * (d - 1)) / 2) {
				int num = 0;
				for(int i = d - 1; i >= 0; --i) {
					arr[i] = num++;
				}
				arr[0] += p - (d * (d - 1)) / 2;
			}
			else {
				sb.append("Wrong information");
				return;
			}
		}
		
		for(int i = 0 ; i < n; ++i) {
			sb.append(arr[i]).append('\n');
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		st = new StringTokenizer(br.readLine().trim());
		
		n = Integer.parseInt(st.nextToken());
		p = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		
		solve();
		
		System.out.println(sb);
	}
}