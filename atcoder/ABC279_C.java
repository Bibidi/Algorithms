import java.io.*;
import java.util.*;

public class ABC279_C {
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

        int h = in.nextInt();
        int w = in.nextInt();
        String[] s = new String[h];
        for (int i = 0; i < h; i++) {
            s[i] = in.next();
        }
        String[] t = new String[h];
        for (int i = 0; i < h; i++) {
            t[i] = in.next();
        }

        HashMap<String, Integer> col = new HashMap<>();
        for (int j = 0; j < w; j++) {
            StringBuffer sb = new StringBuffer();
            for (int i = 0; i < h; i++) {
                sb.append(s[i].charAt(j));
            }
            String curCol = sb.toString();
            col.putIfAbsent(curCol, 0);
            col.put(curCol, col.get(curCol) + 1);
        }

        for (int j = 0; j < w; j++) {
            StringBuffer sb = new StringBuffer();
            for (int i = 0; i < h; i++) {
                sb.append(t[i].charAt(j));
            }
            String curCol = sb.toString();
            col.putIfAbsent(curCol, 0);
            col.put(curCol, col.get(curCol) - 1);
        }

        boolean ans = true;
        for (Map.Entry e : col.entrySet()) {
            int val = (int) e.getValue();
            if (val != 0) ans = false;
        }
        out.println(ans ? "Yes" : "No");

        out.close();
    }
}
