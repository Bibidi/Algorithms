import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class P09 {
    public static void main(String[] args) {
        Stack<String> exp = new Stack<String>();

        while (!StdIn.isEmpty()) {
            String item = StdIn.readString();

            if (!item.equals(")"))
                exp.push(item);
            else {
                String a, b, op;
                b = exp.pop();
                op = exp.pop();
                a = exp.pop();
                exp.push("( " + a + " " + op + " " + b + " )");
            }
        }
        StdOut.println(exp.pop());
    }
}
