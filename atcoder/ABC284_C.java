import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class ABC284_C {
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

    public static void findComp(ArrayList<Integer>[] adj, int[] visited, int cur) {
        visited[cur] = 1;
        for (int next : adj[cur]) {
            if (visited[next] == 1) continue;
            findComp(adj, visited, next);
        }
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
            if (visited[i] == 1) continue;
            findComp(adj, visited, i);
            ans++;
        }
        out.println(ans);

        out.close();
    }
}
