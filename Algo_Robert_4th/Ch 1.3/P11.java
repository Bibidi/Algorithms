import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class P11 {
    public static void main(String[] args) {
        Stack<Integer> val = new Stack<Integer>();
        while (!StdIn.isEmpty()) {
            String item = StdIn.readString();
            if (item.equals("+")) {
                int t = val.pop();
                val.push(val.pop() + t);
            }
            else if (item.equals("*")) {
                int t = val.pop();
                val.push(val.pop() * t);
            }
            else val.push(Integer.parseInt(item));
        }
        StdOut.print(val.pop());
    }
}
