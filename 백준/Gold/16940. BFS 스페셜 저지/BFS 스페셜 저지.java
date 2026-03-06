import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	
	static int N, ans = 1;
	static boolean[] visited = new boolean[100001];
	static List<Integer> [] list = new ArrayList[100001];
	static Queue<Integer> sequence = new ArrayDeque<>();
	
	static void solve() {
		
		Queue<Integer> q = new ArrayDeque<>();
		q.add(1);
		visited[1] = true;
		int front = sequence.poll();
		if (front != 1) {
			sb.append(0);
			return;
		}
		
		while(!q.isEmpty()) {
			front = q.poll();
			
			int cnt = 0;
			
			for(int i = 0; i < list[front].size(); ++i) {
				int next = list[front].get(i);
				if (!visited[next]) {
					visited[next] = true;
					cnt++;
				}
			}
			
			for(int i = 0; i < cnt; ++i) {
				int next = sequence.poll();
				q.add(next);
				if (!visited[next]) {
					ans = 0;
					break;
				}
			}
			if (ans == 0) {
				break;
			}
		}
	
		sb.append(ans);
	}
	
	public static void main(String[] args) throws IOException {
	
		N = Integer.parseInt(br.readLine().trim());
		
		for(int i = 1; i <= N; ++i) {
			list[i] = new ArrayList<>();
		}
		
		int a, b;
		for(int i = 0 ; i < N - 1; ++i) {
			st = new StringTokenizer(br.readLine().trim());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			list[a].add(b);
			list[b].add(a);
		}
		
		st = new StringTokenizer(br.readLine().trim());
		for(int i = 0; i < N; ++i) {
			sequence.add(Integer.parseInt(st.nextToken()));
		}
		
		solve();
		
		System.out.println(sb);
	}
}
