import java.io.*;
import java.util.*;

public class ABC065_A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int x, a, b;
        st = new StringTokenizer(br.readLine());
        x = Integer.parseInt(st.nextToken());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());

        if (b <= a) bw.write("delicious");
        else if (b <= a + x) bw.write("safe");
        else bw.write("dangerous");

        bw.close();
        br.close();
    }
}