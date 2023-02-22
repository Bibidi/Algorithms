import java.io.*;
import java.util.*;
import java.util.Queue;

public class ABC278_D {
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

    public static void main(String[] args) {
        FastReader in = new FastReader();
        FastWriter out = new FastWriter();

        int n = in.nextInt();
        long[] arr = new long[n + 1];
        Queue<Integer> log = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            arr[i] = in.nextLong();
            log.add(i);
        }
        int q = in.nextInt();

        long base = 0;
        for (int i = 0; i < q; i++) {
            int query = in.nextInt();
            if (query == 1) {
                while (!log.isEmpty()) {
                    arr[log.remove()] = 0;
                }
                base = in.nextLong();
            } else if (query == 2) {
                int cur = in.nextInt();
                long val = in.nextLong();
                arr[cur] += val;
                log.add(cur);
            } else {
                out.println(arr[in.nextInt()] + base);
            }
        }

        out.close();
    }
}
