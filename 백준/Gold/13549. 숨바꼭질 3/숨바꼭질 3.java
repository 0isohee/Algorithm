import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;

public class Main {
	static int N, K, map[];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s[] = br.readLine().split(" ");
		N = Integer.parseInt(s[0]);
		K = Integer.parseInt(s[1]);
		map = new int [1000001];
		Arrays.fill(map, -1);
		
		//0과 1 알고리즘 이용한 BFS
		
		//step 1. 가중치가 0인 것 먼저 넣기
		//step 2. 가중치가 1인 것 고려 
		BFS(N,K);
		System.out.println(map[K]);
	}
	
	private static void BFS(int n, int k) {
		LinkedList<Integer> queue = new LinkedList<>();
		queue.offer(n);
		map[n] = 0;
		
		while(!queue.isEmpty()) {
			int pos = queue.poll();
			
			if(pos == k) return;
			
			//1. 가중치가 0인 것
			if(pos * 2 <= 1000000 && map[pos * 2] == -1) {
				queue.addFirst(pos*2);
				map[pos*2] = map[pos];
			}
			//2. 가중치가 1인 것
			if(pos > 0 && map[pos - 1] == -1) {
				queue.offer(pos - 1);
				map[pos - 1] = map[pos] + 1;
			}
			//2. 가중치가 1인 것
			if (pos < 1000000 && map[pos + 1] == -1) {
				queue.offer(pos + 1);
				map[pos + 1] = map[pos] + 1;
			}
		}
	}
}
