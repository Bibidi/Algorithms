import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class ABC288_C {
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

    public static int findCycle(ArrayList<Integer>[] adj, int[] visited, int cur, int prior) {
        visited[cur] = 1;

        int res = 0;
        for (int next : adj[cur]) {
            if (next == prior) continue;
            if (visited[next] == 2) continue;
            if (visited[next] == 1) {
                res++;
                continue;
            }
            if (visited[next] == 0) {
                res += findCycle(adj, visited, next, cur);
            }
        }

        visited[cur] = 2;
        return res;
    }

    public static void main(String[] args) {
        FastReader in = new FastReader();
        FastWriter out = new FastWriter();

        int n = in.nextInt();
        int m = in.nextInt();

        ArrayList<Integer>[] adj = new ArrayList[n + 1];
        for (int i = 0; i < adj.length; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            adj[x].add(y);
            adj[y].add(x);
        }

        int[] visited = new int[n + 1];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i] != 0) continue;
            ans += findCycle(adj, visited, i, 0);
        }
        out.println(ans);

        out.close();
    }
}
