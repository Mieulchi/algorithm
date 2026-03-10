import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/*
 * SW Academy
 *
 * 1. 테스트케이스 T회에 걸쳐 정점과 간선을 입력받는다.
 * 2. 크루스칼 알고리즘을 통해 MST를 구성 후 답을 출력한다.
 *      2-1. 간선을 PriorityQueue에 저장하여 최소 간선을 뽑아나간다.
 *      2-2. union-find 사용하여 싸이클이 생기지 않도록 간선을 선택한다. 간선이 n - 1개 선택되었다면 종료한다.
 *
 */

public class Solution {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int V, E;
    static int [] parent = new int[100001];
    static long ans;

    static class Edge {
        int v1;
        int v2;
        int weight;
        Edge(int v1, int v2, int weight) {
            this.v1 = v1;
            this.v2 = v2;
            this.weight = weight;
        }
    }

    static Edge [] edges = new Edge[200001];

    static void union(int v1, int v2) {
        int pa = find(v1);
        int pb = find(v2);

        if (pa != pb) {
            parent[pa] = pb;
        }
    }

    static int find(int v) {
        if (parent[v] == v) {
            return v;
        }
        return parent[v] = find(parent[v]);
    }

    static void solve() {
        int cnt = 0;

        for(int i = 0; i < E; ++i) {
            if (cnt == V - 1) {
                break;
            }
            Edge e = edges[i];
            int v1 = e.v1;
            int v2 = e.v2;
            int weight = e.weight;
            if (find(v1) != find(v2)) {
                ans += weight;
                union(v1, v2);
                ++cnt;
            }
        }
    }

    static void init() throws IOException {

        ans = 0;

        st = new StringTokenizer(br.readLine().trim());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        for(int i = 1; i <= V; i++) {
            parent[i] = i;
        }

        int a, b, c;
        for(int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine().trim());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            edges[i] = new Edge(a, b, c);
        }

       Arrays.sort(edges, 0, E, Comparator.comparingInt(e -> e.weight));
    }

    public static void main(String[] args) throws IOException {

        int T;
        T = Integer.parseInt(br.readLine().trim());
        //T = 10;

        for (int test_case = 1; test_case <= T; ++test_case) {

            init();

            solve();

            sb.append('#').append(test_case).append(' ').append(ans).append('\n');

        }

        System.out.println(sb);
    }
}