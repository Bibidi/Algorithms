import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class P10 {
    public static void main(String[] args) {
        Stack<String> st = new Stack<String>();

        while (!StdIn.isEmpty()) {
            String item = StdIn.readString();
            if (item.equals("+"))
                st.push(item);
            else if (item.equals("*"))
                st.push(item);
            else if (item.equals(")"))
                StdOut.print(st.pop() + " ");
            else if (item.equals("("))
                StdOut.print();
            else
                StdOut.print(item + " ");
        }
    }
}
