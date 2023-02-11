import java.io.*;
import java.util.StringTokenizer;

public class ABC067_C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        long[] arr = new long[n];
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(st.nextToken());
        }

        long[] left_sum = new long[n + 1];
        long[] right_sum = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            left_sum[i] = left_sum[i - 1] + arr[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            right_sum[i] = right_sum[i + 1] + arr[i];
        }

        long ans = (long) 1e15;
        for (int i = 1; i < n; i++) {
            ans = Math.min(ans, Math.abs(left_sum[i] - right_sum[i]));
        }
        bw.write(ans + "");

        bw.close();
        br.close();
    }
}
