import java.io.*;

public class ABC068_B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int ans = 1;
        while (2 * ans <= n) {
            ans *= 2;
        }
        bw.write(ans + "");

        bw.close();
        br.close();
    }
}
