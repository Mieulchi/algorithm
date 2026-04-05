import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));  
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	
	static int N, M, K;
	static long [] arr = new long [500001];
	static long [] tree = new long [2000004];
	static int ans;
	
	public static void make_tree(int node, int left, int right) {
		if (left == right) {
			tree[node] = arr[left];
			return;
		}
		
		int mid = (left + right) / 2;
		
		make_tree(node * 2, left, mid);
		make_tree(node * 2 + 1, mid + 1, right);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
	
	public static void update(int node, int left, int right, long idx, long value) {
		if (left == right && idx == left) {
			tree[node] += value;
			return;
		}
		int mid = (left + right) / 2;
		if (idx <= mid) {
			update(node * 2, left, mid, idx, value);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		}
		else {
			update(node * 2 + 1, mid + 1, right, idx, value);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		}
	}
	
	public static void get(int node, int left, int right, long s, long e, long find) {
		if (right < s || left > e) {
			return;
		}
		
		if (left == right) {
			ans = left;
			return;
		}
		
		int mid = (left + right) / 2;
		
		if (find <= tree[node * 2]) {
			get(node * 2, left, mid, s, e, find);
		}
		else {
			get(node * 2 + 1, mid + 1, right, s, e, find - tree[node * 2]);
		}
		
		
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		st = new StringTokenizer(br.readLine().trim());
		
		N = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine().trim());

		for(int i = 1; i <= N; ++i) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		make_tree(1, 1, N);
		st = new StringTokenizer(br.readLine().trim());
		M = Integer.parseInt(st.nextToken());
		
		for(int i = 0; i < M; ++i) {
			st = new StringTokenizer(br.readLine().trim());
			long a, b, c;
			a = Long.parseLong(st.nextToken());
		 
			if (a == 1) {
				b = Long.parseLong(st.nextToken());
				c = Long.parseLong(st.nextToken());
				update(1, 1, N, b, c);
			}
			else {
				b = Long.parseLong(st.nextToken());
				get(1, 1, N, 1, N, b);
				sb.append(ans + "\n");
			}
		}
		
		
		System.out.println(sb);
	}
}
 