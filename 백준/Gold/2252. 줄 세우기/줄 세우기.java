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
	
	static List<Integer>[] list = new ArrayList[32001];
	static int[] indegree = new int[32001];
	static boolean[] visited = new boolean[32001];
	
	static int N, M, D;
	static List<Integer> ans = new ArrayList<>();

	static void topologic_sort(int start) {
		Queue<Integer> q = new ArrayDeque<>();
		q.add(start);
		visited[start] = true;
		
		while(!q.isEmpty()) {
			int size = q.size();
			
			while(size-- > 0) {
				int front = q.poll();
				ans.add(front);
				
				for(int i = 0; i < list[front].size(); ++i) {
					int next = list[front].get(i);
					indegree[next]--;
					if (!visited[next] && indegree[next] == 0) {
						q.add(next);
						visited[next] = true;
					}
				}
			}
		}
	}
	
	static void solve() {
		
		for(int i = 1; i <= N; ++i) {
			if (!visited[i] && indegree[i] == 0) {
				topologic_sort(i);
			}
		}
	}

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine().trim());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		for (int i = 1; i <= N; ++i) {
			list[i] = new ArrayList<>();
		}
		
		int a,b;
		for (int i = 0; i < M; ++i) {
			st = new StringTokenizer(br.readLine().trim());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			list[b].add(a);
			indegree[a]++; 
		}

		solve();

		for(int i = ans.size() - 1; i >= 0; --i) {
			sb.append(ans.get(i)).append(' ');
		}
		System.out.println(sb);
	}
}
