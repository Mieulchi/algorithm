import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static int N, M;
    static List<Integer> [] graph = new ArrayList [10001];
    static int [] visited = new int [10001];

    static int mx;
    static List<Integer> ans = new ArrayList<>();
    static int count;
    static int cnt = 0;

    public static void solve() throws IOException {

        for (int node = 1; node <= N; ++node) {
            graph[node] = new ArrayList<>();
        }

        for (int i = 0; i < M; ++i) {
            st = new StringTokenizer(br.readLine().trim());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            graph[b].add(a);
        }

        for (int node = 1; node <= N; ++node) {
            count = 0;
            ++cnt;

            Queue<Integer> q = new ArrayDeque<>();
            visited[node] = cnt;
            q.add(node);

            while(!q.isEmpty()) {
                int size = q.size();

                while (size-- > 0) {
                    int front = q.poll();
                    visited[front] = cnt;

                    for (int i = 0; i < graph[front].size(); ++i) {
                        int next = graph[front].get(i);
                        if (visited[next] != cnt) {
                            visited[next] = cnt;
                            ++count;
                            q.add(next);
                        }
                    }
                }
            }

            if (count > mx) {
                mx = count;
                ans.clear();
                ans.add(node);
            }
            else if (count == mx) {
                ans.add(node);
            }


        }

        for (int i = 0; i < ans.size(); ++i) {
            sb.append(ans.get(i)).append(' ');
        }
    }


    public static void main(String[] args) throws NumberFormatException, IOException {
        st = new StringTokenizer(br.readLine().trim());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        solve();

        System.out.println(sb);
    }
}