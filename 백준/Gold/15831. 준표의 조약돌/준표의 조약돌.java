import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main
{
	static BufferedReader br;
	static StringBuilder sb;
	static StringTokenizer st;
	static int N, B, W;
	static int black[], white[];
	static int ans;
	static String str;
	
	public static int lower_bound(int[] arr, int key) {
		int left = 1, right = arr.length;
		
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (arr[mid] < key) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		
		return left;
	}
		
	
	public static void solve() {
		for(int start = 1; start <= N; ++start) {
			int findB = black[start] + B + 1;
			if (str.charAt(start - 1) == 'B') {
				findB--;
			}
			
			int findW = white[start] + W;
			if (str.charAt(start - 1) == 'W') {
				findW--;
			}
			
			int bIdx = lower_bound(black, findB);
			int wIdx = lower_bound(white, findW);
			
			if (bIdx > 0 && wIdx > 0) {
				if (bIdx - 1 >= wIdx) {
					ans = Math.max(ans, bIdx - start);
				}
			}
		}
	}
	
	public static void main(String args[]) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		sb = new StringBuilder();
		
		st = new StringTokenizer(br.readLine().trim());
		N = Integer.parseInt(st.nextToken());
		B = Integer.parseInt(st.nextToken());
		W = Integer.parseInt(st.nextToken());
		
		
		str = br.readLine().trim();
		
		black = new int [str.length() + 1];
		white = new int [str.length() + 1];
		
		for(int i = 1; i <= str.length(); ++i) {
			black[i] += black[i - 1] ;
			white[i] += white[i - 1];
			if (str.charAt(i - 1) == 'B') {
				black[i]++;
			}else {
				white[i]++;
			}	
		}
		
		solve();
		
		System.out.println(ans);
		                                                                            
	}
}