import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	static int N;
	static int [] A = new int[500000];
	static HashMap<Integer, Integer> map = new HashMap<>();
	
	static int [] B = new int[500000];
	static int cnt;
	
	static void solve() {
		if (cnt == 0) {
			sb.append(1);
			return;
		}
		int ans = 0;
		
		//서로 다른 양의 정수
		PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
		for(int i = 0; i < N; ++i) {
			pq.add(A[i]);
		}
		
		for(int i = N - 1; i > 0; --i) {
			int max = pq.poll();
			if (max == A[i]) {
				continue;
			}
			
			if (max < A[i]) {
				pq.add(max);
				continue;
			}
			
			int idx = map.get(max);
			
			if (B[i] == A[i]) {
				cnt++;
			}
			if (B[idx] == A[idx]) {
				cnt++;
			}
			
			int tmp = map.get(max);
			map.put(max, i);
			map.put(A[i], tmp);
			
			
			tmp = A[i];
			A[i] = A[idx];
			A[idx] = tmp;
			
			if (B[i] == A[i]) {
				cnt--;
			}
			if (B[idx] == A[idx]) {
				cnt--;
			}
			
			if (cnt == 0) {
				ans = 1;
				break;
			}
		}
		
		sb.append(ans);
	}

	public static void main(String[] args) throws IOException {
		
		N = Integer.parseInt(br.readLine().trim());

		st = new StringTokenizer(br.readLine().trim());
		for(int idx = 0; idx < N; ++idx) {
			A[idx] = Integer.parseInt(st.nextToken());
			map.put(A[idx], idx);
		}
			
		st = new StringTokenizer(br.readLine().trim());
		for(int idx = 0; idx < N; ++idx) {
			B[idx] = Integer.parseInt(st.nextToken());
			if (A[idx] != B[idx]) {
				cnt++;
			}
		}
		
		solve();

		System.out.println(sb);
	}
}
