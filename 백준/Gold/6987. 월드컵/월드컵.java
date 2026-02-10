import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


/*
 * SW Academy
 * 1. 네 번의 테스트 케이스에 거쳐 여섯 팀의 정보르 입력받는다.
 * 2. 모든 경기 조합을 고르고 각 경기마다 각 팀이 이기고/비기고/지는 경우를 모두 백트래킹하며 테스트한다. -> 3^15
 *
 *
 *
 */

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static boolean ans = false;


    // win draw lose
    static int [][] result = new int[6][3];
    static int [][] games = new int [6][3];
    static int [] cmp = new int [15];

    static void dfs(int a, int b, int cnt) {
        if (ans) {
            return;
        }
        if (cnt != 15) {
            int nextA = a, nextB = b;
            if (b == 5) {
                nextA++;
                nextB = nextA + 1;
            }
            else {
                nextB++;
            }

            if (games[a][0] + 1 <= result[a][0] && games[b][2] <= result[b][2]) {
                games[a][0]++;
                games[b][2]++;
                dfs(nextA, nextB, cnt + 1);
                games[a][0]--;
                games[b][2]--;
            }
            if (games[a][1] + 1 <= result[a][1] && games[b][1] + 1 <= result[b][1]) {
                games[a][1]++;
                games[b][1]++;
                dfs(nextA, nextB, cnt + 1);
                games[a][1]--;
                games[b][1]--;
            }
            if (games[a][2] + 1 <= result[a][2] && games[b][0] + 1 <= result[b][0]) {
                games[a][2]++;
                games[b][0]++;
                dfs(nextA, nextB, cnt + 1);
                games[a][2]--;
                games[b][0]--;
            }

        }
        else {
            for(int i = 0 ; i < 6; ++i) {
                for(int j = 0; j < 3; ++j) {
                    if (result[i][j] != games[i][j]) {
                        return;
                    }
                }
            }
            ans = true;
        }



    }

    static void solve() {
        ans = false;

        dfs(0, 1, 0);

        int n = ans ? 1 : 0;

        sb.append(n).append(' ');
    }

    public static void main(String[] args) throws NumberFormatException, IOException {

        for(int i = 0 ; i < 4; ++i) {
            st = new StringTokenizer(br.readLine().trim());

            for(int j = 0; j < 6; ++j) {
                result[j][0] = Integer.parseInt(st.nextToken());
                result[j][1] = Integer.parseInt(st.nextToken());
                result[j][2] = Integer.parseInt(st.nextToken());
            }

            solve();
        }

        System.out.println(sb);
    }
}