import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

/*
 * 
 * 
 * 
 * 
 */

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N;

	static boolean [][] tree = new boolean[501][501];

	static boolean[] visited = new boolean[501];

	static long ans;

	static void solve() {

		Queue<Integer> q = new ArrayDeque<>();
		
		for(int i = 1; i <= N; ++i) {
			if (visited[i]) {
				continue;
			}
			
			//방문 안했으면 큐에 넣고
			q.add(i);
			int cnt = -1;
			while (!q.isEmpty()) {
				int front = q.poll();
				++cnt;
				// 직접 못 가는 노드로 워프해봄. 
				// 어차피 걔네끼린 순서 자유라서 최적의 워프가 나옴
				// 예를들어 1 -> 3, 4로 연결했다고 해봐. 2번이 결국 못온다는건 2번이 다 연결되었단 소리
				for(int j = 1; j <= N; ++j) {
					if (!visited[j] && !tree[front][j]) {
						q.add(j);
						visited[j] = true;
					}
				}
			}
			
			ans = Math.max(ans, cnt);
		}

	}

	public static void main(String[] args) throws NumberFormatException, IOException {

		N = Integer.parseInt(br.readLine().trim());

		int a, b;

		for (int idx = 0; idx < N - 1; ++idx) {
			st = new StringTokenizer(br.readLine().trim());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());

			tree[a][b] = true;
			tree[b][a] = true;
		}

		solve();

		System.out.println(ans);
	}
}