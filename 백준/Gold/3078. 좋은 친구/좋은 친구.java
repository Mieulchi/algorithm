import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Main {
     
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
 
    static int N, K;
   
    static int [] len = new int [300001];
    static int [][] sum = new int [300001][21];
    static long ans;
     
    static void solve() throws IOException {
    	for(int i = 1; i <= N; ++i) {
    		String name = br.readLine().trim();
    		len[i] = name.length();
    		sum[i][len[i]]++;
    		for(int j = 2; j <= 20; ++j) {
        		sum[i][j] += sum[i - 1][j];	
    		}
    	}
    	
    	for(int i = 1; i < N; ++i) {
    		int next = Math.min(N, i + K);
        	ans += (sum[next][len[i]] - sum[i][len[i]]);
    	}
    }
 
    public static void main(String[] args) throws NumberFormatException, IOException {
        
    	st = new StringTokenizer(br.readLine().trim());
    	N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        
        solve();
        
        System.out.println(ans);
    }
}