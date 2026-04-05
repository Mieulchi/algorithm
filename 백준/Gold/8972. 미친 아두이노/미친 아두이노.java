import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;


class Main {
	static BufferedReader br;
	static StringTokenizer st;
	static StringBuilder sb;
	static int R, C;
	static char [][] arr;
	static char [][] cpy;
	static String move;
	static int ans;
	
	static int dr[] = { 0, 1, 1, 1, 0, 0, 0, -1, -1, -1 };
	static int dc[] = { 0, -1, 0, 1, -1, 0, 1, -1, 0, 1 };
	
	static class Pair {
		int r, c;
		public Pair(int r, int c) {
			this.r = r;
			this.c = c;
		}
	}
	
	static Pair jongsu;
	static List<Pair> krajXs = new ArrayList<>();
	
	public static void copy(char [][] dst, char [][] src) {
		for(int r = 0; r < R; ++r) {
			for(int c = 0; c < C; ++c) {
				dst[r][c] = src[r][c];
			}
		}
	}
	
	public static boolean solve() {
		Stack<Pair> stack = new Stack<>();
		for(int moves = 0 ; moves < move.length(); ++moves) {
			
			for(int r = 0; r < R; ++r) {
	        	for(int c = 0; c < C; ++c) {
	        		cpy[r][c] = '.';
	        	}
	        }
			
			cpy[jongsu.r][jongsu.c] = '.';
			jongsu.r += dr[move.charAt(moves) - '0'];
			jongsu.c += dc[move.charAt(moves) - '0'];
			if (arr[jongsu.r][jongsu.c] == 'R') {
				System.out.println("kraj " + (moves + 1));
	        	return false;
			}
			cpy[jongsu.r][jongsu.c] = 'I';
			
			for(int r = 0; r < R; ++r) {
				for(int c = 0; c < C; ++c) {
					
					if (arr[r][c] == 'R') {
						int minDist = 1000000007;
						int mIndex = 0;
						
						for(int krajMv = 1; krajMv < 10; ++krajMv) {
					        int iNextR = r + dr[krajMv];
					        int iNextC = c + dc[krajMv];
					        if (iNextR >= 0 && iNextR < R && iNextC >= 0 && iNextC < C) {
						        int dist = Math.abs(iNextR - jongsu.r) + Math.abs(iNextC - jongsu.c); 
						        if (dist < minDist) {
						            minDist = dist;
						            mIndex = krajMv;    
						        }
					        }
					    }
						
						int nextR = r + dr[mIndex];
				        int nextC = c + dc[mIndex];
				        
				        if (cpy[nextR][nextC] == 'I') {
				        	System.out.println("kraj " + (moves + 1));
				        	return false;
				        }
				        else if (cpy[nextR][nextC] == 'R') {
				        	stack.push(new Pair(nextR, nextC));
				        }
				        else {
				        	cpy[nextR][nextC] = 'R';
				        }
					}
				}
			}
			
			while(!stack.empty()) {
				Pair p = stack.pop();
				cpy[p.r][p.c] = '.';
			}
			
			copy(arr, cpy);
		}
		return true;
	}
	
	public static void main(String args[]) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        
        st = new StringTokenizer(br.readLine().trim());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        arr = new char[R][C];
        cpy = new char[R][C];
        
        for(int r = 0; r < R; ++r) {
        	String s = br.readLine();
        	for(int c = 0; c < C; ++c) {
        		arr[r][c] = s.charAt(c);
        		cpy[r][c] = '.';
        		if (arr[r][c] == 'R') {
        			krajXs.add(new Pair(r, c));
        		}
        		else if (arr[r][c] == 'I') {
        			jongsu = new Pair(r, c);
        		}
        	}
        }
        move = br.readLine().trim();
        if (solve()) {
        	for(int r = 0; r < R; ++r) {
        		for(int c = 0; c < C; ++c) {
        			sb.append(arr[r][c]);
        		}
        		sb.append('\n');
        	}
        	System.out.println(sb);
        }
        
	}
}