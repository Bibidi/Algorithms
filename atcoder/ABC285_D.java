import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class ABC285_D {
    static class FastReader {
        private final BufferedReader br;
        private StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            if (st != null && st.hasMoreTokens()) {
                return st.nextToken();
            }

            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
            return st.nextToken();
        }

        String nextLine() {
            if (st != null && st.hasMoreTokens()) {
                return st.nextToken("\n");
            }

            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
    static class FastWriter {
        private final BufferedWriter bw;

        public FastWriter() {
            bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        public void print(Object object) {
            try {
                bw.append(object.toString());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        public void println(Object object) {
            try {
                bw.append(object.toString()).append("\n");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        public void close() {
            try {
                bw.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static boolean findCycle(int[] next, int[] visited, int cur) {
        visited[cur] = 1;
        int nxt = next[cur];
        if (nxt == -1) {
            visited[cur] = 2;
            return false;
        }

        boolean ans = visited[nxt] == 1;
        if (visited[nxt] == 0) {
            ans |= findCycle(next, visited, nxt);
        }

        visited[cur] = 2;
        return ans;
    }

    public static void main(String[] args) {
        FastReader in = new FastReader();
        FastWriter out = new FastWriter();

        int n = in.nextInt();
        String[][] list = new String[n][2];
        HashMap<String, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            list[i][0] = in.next();
            list[i][1] = in.next();
            map.put(list[i][0], i);
        }

        int[] next = new int[n];
        Arrays.fill(next, -1);
        for (int i = 0; i < n; i++) {
            if (map.containsKey(list[i][1])) {
                next[i] = map.get(list[i][1]);
            }
        }

        boolean haveCycle = false;
        int[] visited = new int[n];
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                haveCycle |= findCycle(next, visited, i);
            }
        }
        out.println(haveCycle ? "No" : "Yes");

        out.close();
    }
}
