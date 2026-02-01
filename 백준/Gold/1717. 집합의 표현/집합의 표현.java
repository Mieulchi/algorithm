import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int N, M;
    static int [] parent = new int [1000001];

    public static int find(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    public static void union(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa != pb) {
            parent[pb] = pa;
        }
    }

    public static void main(String args[]) throws Exception {

        st = new StringTokenizer(br.readLine().trim());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int a, b;

        for (int i = 1; i <= N ; ++i) {
            parent[i] = i;
        }

        for (int i = 0 ; i < M ; i++) {
            st = new StringTokenizer(br.readLine().trim());
            int query = Integer.parseInt(st.nextToken());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            if (query == 0) {
                union(a, b);
            }
            else {
                if (find(a) == find(b)) {
                    sb.append("YES\n");
                }
                else {
                    sb.append("NO\n");
                }

            }
        }

        System.out.println(sb);
    }
}