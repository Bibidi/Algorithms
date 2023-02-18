import java.io.*;
import java.util.StringTokenizer;

public class ABC287_D {
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

    public static boolean match(char x, char y) {
        return x == '?' || y == '?' || x == y;
    }

    public static void main(String[] args) {
        FastReader in = new FastReader();
        FastWriter out = new FastWriter();

        String s = in.next();
        String t = in.next();

        int[] pre = new int[t.length() + 1];
        pre[0] = 1;
        for (int i = 0; i < t.length(); i++) {
            if (!match(s.charAt(i), t.charAt(i))) break;
            pre[i + 1] = 1;
        }

        s = new StringBuffer(s).reverse().toString();
        t = new StringBuffer(t).reverse().toString();

        int[] suf = new int[t.length() + 1];
        suf[0] = 1;
        for (int i = 0; i < t.length(); i++) {
            if (!match(s.charAt(i), t.charAt(i))) break;
            suf[i + 1] = 1;
        }

        for (int i = 0; i <= t.length(); i++) {
            if ((pre[i] & suf[t.length() - i]) == 1) out.println("Yes");
            else out.println("No");
        }

        out.close();
    }
}
