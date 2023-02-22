import java.io.*;
import java.util.*;

public class ABC277_C {
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

    static int find(HashMap<Integer, Integer> parent, int cur) {
        if (parent.get(cur) == cur) return cur;
        parent.put(cur, find(parent, parent.get(cur)));
        return parent.get(cur);
    }

    static void merge(HashMap<Integer, Integer> parent, int x, int y) {
        x = find(parent, x);
        y = find(parent, y);

        if (x == y) return;
        parent.put(y, x);
    }

    public static void main(String[] args) {
        FastReader in = new FastReader();
        FastWriter out = new FastWriter();

        int n = in.nextInt();
        HashMap<Integer, Integer> parent = new HashMap<>();
        parent.put(1, 1);
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            parent.putIfAbsent(x, x);
            parent.putIfAbsent(y, y);
            merge(parent, x, y);
        }

        int ans = 1;
        for (Map.Entry entry : parent.entrySet()) {
            int p1 = find(parent, (int) entry.getKey());
            int p2 = find(parent, 1);
            if (p1 == p2) {
                ans = Math.max(ans, (int) entry.getKey());
            }
        }
        out.println(ans);

        out.close();
    }
}
