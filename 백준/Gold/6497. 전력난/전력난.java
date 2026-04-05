import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();

	static class Edge {
		int v1;
		int v2;
		int weight;

		public Edge(int v1, int v2, int weight) {
			this.v1 = v1;
			this.v2 = v2;
			this.weight = weight;
		}
	}

	static int[] parent = new int[200001];
	static List<Edge> list;

	static int n, m, ans;

	static int find(int v) {
		if (parent[v] == v) {
			return v;
		}
		return parent[v] = find(parent[v]);
	}

	static void solve() {

		int cnt = 0;
		for (Edge e : list) {
			if (cnt == m - 1) {
				break;
			}
			int v1 = e.v1;
			int v2 = e.v2;
			int w = e.weight;

			int pa = find(v1);
			int pb = find(v2);

			if (pa != pb) {
				parent[pa] = pb;
				ans -= w;
				cnt++;
			}
		}

		sb.append(ans).append('\n');
	}

	public static void main(String[] args) throws IOException {

		while (true) {
			st = new StringTokenizer(br.readLine().trim());

			ans = 0;
			list = new ArrayList<>();
			
			m = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());
			
			if (m == 0 && n == 0) {
				break;
			}

			int x, y, z;
			for (int i = 0; i < m; ++i) {
				parent[i] = i;
			}
			for (int i = 0; i < n; ++i) {

				st = new StringTokenizer(br.readLine().trim());
				x = Integer.parseInt(st.nextToken());
				y = Integer.parseInt(st.nextToken());
				z = Integer.parseInt(st.nextToken());

				ans += z;

				list.add(new Edge(x, y, z));
			}

			list.sort(Comparator.comparingInt(e -> e.weight));

			solve();
			
		}

		System.out.println(sb);
	}
}