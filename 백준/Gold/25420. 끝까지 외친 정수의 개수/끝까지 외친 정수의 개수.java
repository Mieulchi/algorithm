import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {
	
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static int n, k;

    static boolean[] cant = new boolean[100001];

    
    static int [][] dp = new int[100001][2];

    static int ans;

    static void solve() {

    	for(int i = n - 1; i >= 0; --i) {
    		
    		boolean canWin = false, canMove = false;
    		int winCount = 1000000007, loseCount = 0;
    		
    		for(int j = i + 1; j <= i + k; ++j) {
    			if (j > n) {
    				break;
    			}
    			if (!cant[j]) {
    				canMove = true;
        			if (dp[j][0] == 0) {
        				canWin = true;
        				winCount = Math.min(winCount, dp[j][1] + 1);
        			}
        			else {
        				loseCount = Math.max(loseCount, dp[j][1] + 1);
        			}
    			}
    		}
    		if (!canMove) {
    			dp[i][0] = 0;
    			dp[i][1] = 0;
    		}
    		if (canWin) {
    			dp[i][0] = 1;
    			dp[i][1] = winCount;
    		}
    		else {
    			dp[i][1] = loseCount;
    		}
    	}
    	ans = dp[0][1];
    }

    public static void main(String[] args) throws NumberFormatException, IOException {

        st = new StringTokenizer(br.readLine().trim());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine().trim());
        int idx = 1;
        while (st.hasMoreTokens()) {
            int num = Integer.parseInt(st.nextToken());
            cant[num] = true;
        }

        solve();

        System.out.println(ans);
    }
}