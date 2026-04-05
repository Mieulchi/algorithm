import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;

	static int N;
	static long ans;

	static int [] arr = new int [500000];
	static int [] tmp = new int [500000];
	
	static void merge_sort(int left, int right) {
		if (left < right) {
			int mid = (left + right) / 2;
			merge_sort(left, mid);
			merge_sort(mid + 1, right);
			merge(left, mid, right);
		}
	}
	
	static void merge(int left, int mid, int right) {
		int i = left;
		int j = mid + 1;
		int k = left;
		
		while(i <= mid && j <= right) {
			if (arr[i] <= arr[j]) {
				tmp[k++] = arr[i++];
			}
			else {
				ans += (mid - i + 1);
				tmp[k++] = arr[j++];
			}
		}
		
		while (i <= mid) {
            tmp[k++] = arr[i++];
        }
        while (j <= right) {
            tmp[k++] = arr[j++];
        }

        for (int t = left; t <= right; t++) {
            arr[t] = tmp[t];
        }
	}
	
	static void solve() {
		merge_sort(0, N - 1);
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		N = Integer.parseInt(br.readLine().trim());

		st = new StringTokenizer(br.readLine().trim());
		
		for(int i = 0; i < N; ++i) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		solve();

		System.out.println(ans);
	}
}