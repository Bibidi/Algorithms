import java.io.*;
import java.util.HashSet;
import java.util.StringTokenizer;

public class ABC289_C {
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

    public static int recur(HashSet<Integer>[] set, boolean[] checked, int n, int cur) {
        if (cur == checked.length) {
            HashSet<Integer> nSet = new HashSet<>();
            for (int i = 0; i < checked.length; i++) {
                if (checked[i]) {
                    nSet.addAll(set[i]);
                }
            }
            return nSet.size() == n ? 1 : 0;
        }

        checked[cur] = true;
        int ans = recur(set, checked, n, cur + 1);
        checked[cur] = false;
        ans += recur(set, checked, n, cur + 1);
        return ans;
    }

    public static void main(String[] args) {
        FastReader in = new FastReader();
        FastWriter out = new FastWriter();

        int n = in.nextInt();
        int m = in.nextInt();

        HashSet<Integer>[] set = new HashSet[m];
        for (int i = 0; i < m; i++) {
            int x = in.nextInt();
            set[i] = new HashSet<>();

            for (int j = 0; j < x; j++) {
                set[i].add(in.nextInt());
            }
        }

        boolean[] checked = new boolean[m];
        int ans = recur(set, checked, n, 0);
        out.println(ans);

        out.close();
    }
}
