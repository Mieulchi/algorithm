import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


/*
 *
 *  문제 : 모든 인덱스에서 모든 길이에 대해 팰린드롬을 판단하는 것 자체가 시간초과(N^3)
 *
 *  문제를 분할 가능한 문제로 만들어보자
 *
 *
 *
 *
 */

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static String str;
    static boolean [][] isPalindrome = new boolean [2501][2501];
    static int [] dp = new int [2501];

    static void solve() {

        int len = str.length();

        for(int i = 0; i < len; i++) {
            isPalindrome[i][i] = true;
        }
        for(int i = 0; i < len - 1; i++) {
            if (str.charAt(i) == str.charAt(i + 1)) {
                isPalindrome[i][i + 1] = true;
            }
        }

        for (int i = 2; i < len; i++) {
            for (int j = 0; j < len - i; j++) {
                isPalindrome[j][j + i] = (str.charAt(j) == str.charAt(j + i) && isPalindrome[j + 1][j + i - 1]);
            }
        }

        dp[0] = 1;
        for (int i = 1; i < len; ++i) {
            dp[i] = (isPalindrome[0][i] ? 1 : i + 1);
            for (int j = 0; j < i; ++j) {
                dp[i] = Math.min(dp[i], dp[j] + (isPalindrome[j + 1][i] ? 1 : i - j));
            }
        }
        sb.append(dp[len - 1]);

    }

    public static void main(String[] args) throws IOException {
        str = br.readLine().trim();

        solve();

        System.out.println(sb);
    }
}
