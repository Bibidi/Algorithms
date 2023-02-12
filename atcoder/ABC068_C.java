import java.io.*;
import java.util.HashSet;
import java.util.StringTokenizer;

public class ABC068_C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        HashSet<Integer>[] arr = new HashSet[n + 1];
        for (int i = 1; i < arr.length; i++) {
            arr[i] = new HashSet<>();
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            arr[x].add(y);
            arr[y].add(x);
        }

        boolean ans = false;
        for (int i = 1; i <= n; i++) {
            if (arr[i].contains(1) && arr[i].contains(n)) {
                ans = true;
                break;
            }
        }

        bw.write(ans ? "POSSIBLE" : "IMPOSSIBLE");

        bw.close();
        br.close();
    }
}
