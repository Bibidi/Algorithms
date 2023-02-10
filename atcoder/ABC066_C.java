import java.io.*;
import java.util.*;

public class ABC066_C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());

        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            int cur = Integer.parseInt(st.nextToken());
            if (i % 2 == 0) q.addFirst(cur);
            else q.addLast(cur);
        }

        ArrayList<Integer> ans = new ArrayList<>();
        if (n % 2 == 1) {
            while (q.size() > 0) {
                ans.add(q.removeFirst());
            }
        } else {
            while (q.size() > 0) {
                ans.add(q.removeLast());
            }
        }

        for (int cur : ans) {
            bw.write(cur + " ");
        }

        bw.close();
        br.close();
    }
}
