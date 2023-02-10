import java.io.*;
import java.util.*;

public class ABC065_C {
    public static long mod = (long) 1e9 + 7;

    public static long facto(long x) {
        long ans = 1;
        for (int i = 1; i <= x; i++) {
            ans = (ans * i) % mod;
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());

        long ans = facto(a) * facto(b) % mod;
        long diff = Math.abs(a - b);
        if (diff >= 2) bw.write("0");
        else if (diff == 1) bw.write(ans + "");
        else bw.write((ans * 2) % mod + "");

        bw.close();
        br.close();
    }
}
