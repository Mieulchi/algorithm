import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


    /*
        상자가 1번부터 N개

        내가 풀어야 할 문제는? 카드끼리 모을 떄 최소 횟수가 되도록 하는 것
        
        각 상자마다 해당 상자의 특정 컬러를 선택 시
        
        나가야하는 카드 양 / 들어와야하는 카드 양이 정해진다
        
        1번상자에 각 카드 색을 채워보는 것이 초기 상태

        n번 상장에 대해서도 각 카드로 채워보고 해당 색으로 채운 상태를 갱신해보자

        각 bitmask 상태마다 해당 비트를 어떤 박스에서 채웠는지 저장해보자

     */

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static int N, M, total;
    static int [][] box = new int [51][14];

    //dp[bitmask][i][j] = i번 상자까지 고려해섯 bitmask 상태로 만들었을때의 최대 제자리 카드 수
    static int [][] dp = new int[51][1 << 14];

    static void solve() {

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j < (1 << M); j++) {
                dp[i][j] = -1;
            }
        }

        dp[0][0] = 0;
        for (int i = 1; i <= N; i++) {
            for (int bitmask = 0; bitmask < (1 << M); ++bitmask) {

                dp[i][bitmask] = dp[i - 1][bitmask];

                for (int j = 0; j < M; ++j) {

                    int prevMask = bitmask - (1 << j);

                    if (((bitmask >> j) & 1) == 1) {
                        if (dp[i - 1][prevMask] != -1) {
                            dp[i][bitmask] = Math.max(dp[i][bitmask], dp[i - 1][prevMask] + box[i][j]);
                        }
                    }
                }
            }
        }

        sb.append(total - dp[N][(1 << M) - 1]);
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine().trim());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for(int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine().trim());
            for(int j = 0; j < M; j++) {
                box[i][j] = Integer.parseInt(st.nextToken());
                total += box[i][j];
            }
        }

        solve();

        System.out.println(sb);
    }
}
