import java.io.*;
import java.util.*;

public class ABC277_D {
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

    public static long findSum(HashMap<Long, Long> values, HashSet<Long> visited, long m,  long cur) {
        visited.add(cur);
        long res = cur * values.get(cur);
        long next = (cur - 1 + m) % m;
        if (values.containsKey(next) && !visited.contains(next))
            res += findSum(values, visited, m, next);
        next = (cur + 1) % m;
        if (values.containsKey(next) && !visited.contains(next))
            res += findSum(values, visited, m, next);
        return res;
    }

    public static void main(String[] args) {
        FastReader in = new FastReader();
        FastWriter out = new FastWriter();

        int n = in.nextInt();
        int m = in.nextInt();
        HashMap<Long, Long> values = new HashMap<>();
        long total = 0;
        for (int i = 0; i < n; i++) {
            long x = in.nextLong();
            total += x;
            values.putIfAbsent(x, 0L);
            values.put(x, values.get(x) + 1);
        }

        long max = 0;
        HashSet<Long> visited = new HashSet<>();
        for (Map.Entry entry : values.entrySet()) {
            long cur = (long) entry.getKey();
            if (!visited.contains(cur)) {
                max = Math.max(max, findSum(values, visited, m, cur));
            }
        }
        out.println(total - max);

        out.close();
    }
}
