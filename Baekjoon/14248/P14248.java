import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class P14248 {
    static int a[] = new int[100001];
    static boolean visited[] = new boolean[100001];
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        
        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int idx = 1;
        while(st.hasMoreTokens()) {
            a[idx++] = Integer.parseInt(st.nextToken());
        }

        int s = Integer.parseInt(br.readLine());

        Queue<int []> q = new LinkedList<int []>();
        
        q.offer(new int[]{s, a[s]});
        int ans = 1;
        while(!q.isEmpty()) {

            int qfront[] = q.poll();
            int here = qfront[0];
            int step = qfront[1];

            int right_there = here + step;
            int left_there = here - step;

            if(right_there <= n && !visited[right_there]) {
                visited[right_there] = true;
                q.offer(new int[]{right_there, a[right_there]});
                ans++;
            }

            if(left_there >= 1 && !visited[left_there]) {
                visited[left_there] = true;
                q.offer(new int[]{left_there, a[left_there]});
                ans++;
            }
        }
        
        sb.append(ans);

        bw.write(sb.toString());
        bw.close();
        br.close();
    }
}