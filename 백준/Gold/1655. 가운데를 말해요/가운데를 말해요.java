import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {
	static int N;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		//최소힙과 최대힙 생성 
		PriorityQueue<Integer> minQ = new PriorityQueue<>();
		PriorityQueue<Integer> maxQ = new PriorityQueue<>(Comparator.reverseOrder());
		
		N = Integer.parseInt(br.readLine());
		
		for (int i=1; i<=N; i++) {
			int input = Integer.parseInt(br.readLine());
			
			if (minQ.size() == maxQ.size()) {
				maxQ.add(input);
				
				if (!minQ.isEmpty() && maxQ.peek() > minQ.peek()) {
					minQ.add(maxQ.poll());
					maxQ.add(minQ.poll());
				}
			}
			else {
				minQ.add(input); 
				
				if (maxQ.peek() > minQ.peek()) {
					minQ.add(maxQ.poll());
					maxQ.add(minQ.poll());
				}
			}
			bw.write(maxQ.peek()+"\n"); 
        }
		bw.flush();
		bw.close();
	}
}