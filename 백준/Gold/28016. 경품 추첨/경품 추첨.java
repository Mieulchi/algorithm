import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int [][] board = new int[100][100];
    static BigInteger[][] dp = new BigInteger[100][100];
    static int N, M;

    public static void solve() {
        for (int i = 0 ; i < N; ++i) {
            for(int j = 0; j < M; j++) {
                dp[i][j] = BigInteger.ZERO;
            }
        }

        for (int i = 0 ; i < M; ++i) {
            if (board[0][i] == 2) {
                dp[0][i] = new BigInteger("2").pow(100);
                break;
            }
        }

        for (int i = 0 ; i < N - 1; ++i) {
            for (int j = 0 ; j < M; ++j) {
                if (dp[i][j].equals(BigInteger.ZERO)) {
                    continue;
                }
                if (board[i + 1][j] == 0) {
                    dp[i + 1][j] = dp[i + 1][j].add(dp[i][j]);
                }
                else {
                    boolean checkRight = (j + 1 < M && board[i][j + 1] != 1 && board[i + 1][j + 1] != 1);

                    boolean checkLeft = (j - 1 >= 0 && board[i][j - 1] != 1 && board[i + 1][j - 1] != 1);

                    BigInteger half = dp[i][j].divide(BigInteger.valueOf(2));

                    if (checkRight && checkLeft) {
                        dp[i + 1][j + 1] = dp[i + 1][j + 1].add(half);
                        dp[i + 1][j - 1] = dp[i + 1][j - 1].add(half);
                    }
                    else if (checkRight) {
                        dp[i + 1][j + 1] = dp[i + 1][j + 1].add(half);
                    }
                    else if (checkLeft) {
                        dp[i + 1][j - 1] = dp[i + 1][j - 1].add(half);
                    }
                }
            }
        }
        BigInteger max = BigInteger.ZERO;
        int idx = -1;
        for (int i = 0; i < M; ++i) {
            if (dp[N - 1][i].compareTo(max) > 0) {
                max = dp[N - 1][i];
                idx = i;
            }
        }
        sb.append(idx);
    }

    public static void main(String args[]) throws Exception {

        st = new StringTokenizer(br.readLine().trim());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0 ; i < N ; i++) {
            st = new StringTokenizer(br.readLine().trim());
            for (int j = 0 ; j < M ; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        solve();

        System.out.println(sb);
    }
}