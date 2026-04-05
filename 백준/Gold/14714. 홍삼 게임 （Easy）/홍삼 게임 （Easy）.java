import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static int N, A, B, dA, dB;

    static long ans;
    static boolean[][][] visited = new boolean[2][500][500];

    static void solve() {

        Queue<int[]> q = new ArrayDeque<>();

        q.add(new int[]{A, B});
        visited[0][A][B] = true;

        int cnt = 0;
        while (!q.isEmpty()) {

            ++cnt;
            int size = q.size();

            while (size-- > 0) {

                int[] curr = q.poll();
                int a = curr[0];
                int b = curr[1];

                if (cnt % 2 == 1) {
                    int [] nextA = { (a + dA) % N, (a - dA + N) % N };

                    for (int next : nextA) {
                        if (next == b){
                            System.out.println(cnt);
                            return;
                        }

                        if (!visited[1][next][b]) {
                            visited[1][next][b] = true;
                            q.add(new int[]{next, b});
                        }
                    }
                }
                else {
                    int [] nextB = { (b + dB) % N, (b - dB + N) % N };

                    for (int next : nextB) {
                        if (next == a){
                            System.out.println(cnt);
                            return;
                        }

                        if (!visited[0][a][next]) {
                            visited[0][a][next] = true;
                            q.add(new int[]{a, next});
                        }
                    }
                }
            }
        }

        System.out.println("Evil Galazy");
    }

    public static void main(String[] args) throws NumberFormatException, IOException {

        st = new StringTokenizer(br.readLine().trim());

        N = Integer.parseInt(st.nextToken());
        A = Integer.parseInt(st.nextToken()) - 1;
        B = Integer.parseInt(st.nextToken()) - 1;
        dA = Integer.parseInt(st.nextToken());
        dB = Integer.parseInt(st.nextToken());

        solve();

    }
}