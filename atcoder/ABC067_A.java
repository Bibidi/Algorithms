import java.io.*;
import java.util.StringTokenizer;

public class ABC067_A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        boolean ans = (a % 3 == 0) || (b % 3 == 0) || ((a + b) % 3 == 0);
        bw.write(ans ? "Possible" : "Impossible");

        bw.close();
        br.close();
    }
}
