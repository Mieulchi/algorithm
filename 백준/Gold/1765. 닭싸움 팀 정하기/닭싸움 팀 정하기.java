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
	static int N, ans;

	static List<Integer>[][] isFriends = new ArrayList[2][1001];
	static boolean[] visited = new boolean[1001];
	static int [] parent = new int[1001];
	static boolean[] check = new boolean[1001];
	
	static int find(int v) {
		if (parent[v] == v) {
			return v;
		}
		return parent[v] = find(parent[v]);
	}
	
	static void merge(int a, int b) {
		int pa = find(a);
		int pb = find(b);
		
		if (pa != pb) {
			parent[pa] = pb;
		}
	}
	
	static void bfs(int node) {
		Queue<Integer> q = new ArrayDeque<>();
		q.add(node);
		visited[node] = true;

		while(!q.isEmpty()) {
			int prev = q.poll();
			
			for(int i = 0; i < isFriends[1][prev].size(); ++i) {
				int next = isFriends[1][prev].get(i);
				
				merge(prev, next);
				if (!visited[next]) {
					
					visited[next] = true;
					q.add(next);
				}
				
			}
			
			int enemy = 0;
			for(int i = 0; i < isFriends[0][prev].size(); ++i) {
				int next = isFriends[0][prev].get(i);
				if (enemy == 0) {
					enemy = next;
				}
				else {
					merge(enemy, next);
				}
				if (!visited[next]) {
					visited[next] = true;
					q.add(next);
				}
				
			}
			
		}
	}
	
	static void solve() {
		for (int i = 1; i <= N; ++i) {
			if (!visited[i]) {
				bfs(i);
			}
		}
		
		for (int i = 1; i <= N; ++i) {
			int p = find(i);
			if (!check[p]) {
				++ans;
				check[p] = true;
			}
		}
		
		sb.append(ans);
	}

	public static void main(String[] args) throws IOException {
		N = Integer.parseInt(br.readLine().trim());

		int M = Integer.parseInt(br.readLine().trim());

		for (int i = 1; i <= N; ++i) {
			parent[i] = i;
			isFriends[0][i] = new ArrayList<>();
			isFriends[1][i] = new ArrayList<>();
		}

		int f, a, b;
		while (M-- > 0) {
			st = new StringTokenizer(br.readLine().trim());
			f = st.nextToken().charAt(0) == 'F' ? 1 : 0;
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());

			isFriends[f][a].add(b);
			isFriends[f][b].add(a);
		}

		solve();

		System.out.println(sb);
	}
}