import java.io.*;
import java.util.*;

public class ABC278_C {
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
        int q = in.nextInt();

        HashSet<String> follow = new HashSet<>();
        for (int i = 0; i < q; i++) {
            int t = in.nextInt();
            int a = in.nextInt();
            int b = in.nextInt();

            if (t == 1) {
                follow.add(a + "," + b);
            } else if (t == 2) {
                String str = a + "," + b;
                follow.remove(str);
            } else {
                String afb = a + "," + b;
                String bfa = b + "," + a;
                boolean followEach = follow.contains(afb) && follow.contains(bfa);
                out.println(followEach ? "Yes" : "No");
            }
        }

        out.close();
    }
}
