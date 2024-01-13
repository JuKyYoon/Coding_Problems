import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

class P22233 {
    static HashSet<String> hs = new HashSet<>();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int n = Integer.parseInt(st.nextToken()); // number of keywords on a memo
        int m = Integer.parseInt(st.nextToken()); // number of posts on a blog

        // write a keyword about up to 10 keyword

        // insert
        for(int i=0; i<n; i++) {
            String keyword = br.readLine();
            hs.add(keyword);
        }

        // delete
        for(int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine(), ",");
            while(st.hasMoreTokens()) {
                hs.remove(st.nextToken());
            }

            sb.append(hs.size()).append("\n");
        }
        
        bw.write(sb.toString());
        br.close();
        bw.close();
    }
}