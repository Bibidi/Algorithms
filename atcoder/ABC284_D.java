import java.io.*;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class ABC284_D {
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

    public static HashSet<Integer> findPrimes() {
        HashSet<Integer> res = new HashSet<>();
        boolean[] primes = new boolean[3 * 1000000 + 1];
        Arrays.fill(primes, true);
        for (int i = 2; i < primes.length; i++) {
            if (primes[i]) {
                res.add(i);
                for (int j = i * 2; j < primes.length; j += i) {
                    primes[j] = false;
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        FastReader in = new FastReader();
        FastWriter out = new FastWriter();

        HashSet<Integer> primes = findPrimes();
        int t = in.nextInt();
        while (t > 0) {
            long n = in.nextLong();
            long p = 0, q = 0;
            for (long prime : primes) {
                if (n % prime != 0) continue;
                if (n % (prime * prime) == 0) {
                    p = prime;
                    q = n / (prime * prime);
                } else {
                    q = prime;
                    p = Math.round(Math.sqrt((double) (n / prime)));
                }
                break;
            }
            out.println(p + " " + q);
            t--;
        }

        out.close();
    }
}
