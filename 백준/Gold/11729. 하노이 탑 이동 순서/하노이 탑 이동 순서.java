import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int N;

    public static void hanoi_tower(int n, int from, int to, int tmp) {
        if (n > 0) {
            hanoi_tower(n - 1, from, tmp, to);
            sb.append(from + " " + to + '\n');
            hanoi_tower(n - 1, tmp, to, from);
        }
    }

    public static void main(String args[]) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine().trim());

        N = Integer.parseInt(st.nextToken());
        sb.append((1 << N) - 1);
        sb.append('\n');

        hanoi_tower(N - 1, 1, 2, 3);
        sb.append("1 3\n");
        hanoi_tower(N - 1, 2, 3, 1);

        System.out.println(sb);
    }
}