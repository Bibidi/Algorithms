import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdOut;

public class P05 {
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        Stack<Integer> st = new Stack<Integer>();
        while (n > 0) {
            st.push(n % 2);
            n /= 2;
        }
        for (int d : st) StdOut.print(d);
        StdOut.println();
    }
}
