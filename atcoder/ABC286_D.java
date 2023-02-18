import java.io.*;
import java.util.StringTokenizer;

public class ABC286_D {
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

    public static boolean find(int[] coins, int[] coinCounts, int[][] dp, int cur, int amount, int target) {
        if (amount > target) return false;
        if (amount == target) return true;
        if (cur >= coins.length) return false;
        if (dp[cur][amount] != 0) return dp[cur][amount] == 1;

        boolean res = false;
        for (int i = 0 ; i <= coinCounts[cur]; i++) {
            res |= find(coins, coinCounts, dp, cur + 1, amount + coins[cur] * i, target);
        }
        dp[cur][amount] = res ? 1 : -1;
        return res;
    }

    public static void main(String[] args) {
        FastReader in = new FastReader();
        FastWriter out = new FastWriter();

        int n = in.nextInt();
        int x = in.nextInt();

        int[] coins = new int[n];
        int[] coinCounts = new int[n];
        for (int i = 0; i < n; i++) {
            coins[i] = in.nextInt();
            coinCounts[i] = in.nextInt();
        }

        int[][] dp = new int[n][x + 1];
        boolean ans = find(coins, coinCounts, dp, 0, 0, x);
        out.println(ans ? "Yes" : "No");

        out.close();
    }
}
