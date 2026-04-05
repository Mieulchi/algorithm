import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int n, m, q;
	static final int INF = 1000000007;

	static List<Integer>[] graph;

	static int[][] dist = new int[2001][2001];
	static boolean[][] visited = new boolean[2001][2001];

	static class Pair {
		int v;
		int d;

		public Pair(int v, int d) {
			this.v = v;
			this.d = d;
		}
	}

	static PriorityQueue<Pair> pq;

	static void dijkstra(int node) {
		pq = new PriorityQueue<>((o1, o2) -> o1.d - o2.d);

		visited[node][node] = true;
		dist[node][node] = 0;

		for (int i = 0; i < graph[node].size(); ++i) {
			pq.add(new Pair(graph[node].get(i), 1));
		}

		while (!pq.isEmpty()) {
			Pair front = pq.poll();

			int next = front.v;
			int distance = front.d;

			if (!visited[node][next]) {
				dist[node][next] = distance;
				visited[node][next] = true;

				for (int i = 0; i < graph[next].size(); ++i) {
					if (dist[node][graph[next].get(i)] > distance + 1) {
						pq.add(new Pair(graph[next].get(i), distance + 1));
					}
				}
			}
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		st = new StringTokenizer(br.readLine().trim());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		q = Integer.parseInt(st.nextToken());

		int u, v;

		graph = new ArrayList[2001];

		for (int i = 0; i < 2001; ++i) {
			graph[i] = new ArrayList<>();
			for (int j = 0; j < 2001; ++j) {
				dist[i][j] = INF;
			}
		}

		for (int i = 0; i < m; ++i) {
			
			st = new StringTokenizer(br.readLine().trim());
			u = Integer.parseInt(st.nextToken());
			v = Integer.parseInt(st.nextToken());

			graph[u].add(v);
		}
		
		for(int i = 1; i <= n; ++i) {
			dijkstra(i);
		}

		for (int i = 0; i < q; ++i) {
			st = new StringTokenizer(br.readLine().trim());
			u = Integer.parseInt(st.nextToken());
			v = Integer.parseInt(st.nextToken());
			
			int min = INF;
			for(int j = 1; j <= n; ++j) {
				int m = Math.max(dist[j][u], dist[j][v]);
				
				if (m != INF) {
					min = Math.min(min, m);
				}
			}
			
			sb.append(min == INF ? -1 : min).append('\n');
		}

		System.out.println(sb);
	}
}