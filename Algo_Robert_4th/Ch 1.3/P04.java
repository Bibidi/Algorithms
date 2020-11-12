import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class P04 {
    public static void main(String[] args) {
        Stack<Character> st = new Stack<Character>();

        boolean ok = true;
        while (!StdIn.isEmpty()) {
            char item = StdIn.readChar();
            if (item == '(' || item == '{' || item == '[')
                st.push(item);
            else {
                if (st.size() == 0) {
                    ok = false;
                    break;
                }

                if (item == ')') {
                    if (st.pop() != '(') {
                        ok = false;
                        break;
                    }
                }
                else if (item == '}') {
                    if (st.pop() != '{') {
                        ok = false;
                        break;
                    }
                }
                else if (item == ']') {
                    if (st.pop() != '[') {
                        ok = false;
                        break;
                    }
                }
            }
        }

        if (st.size() == 0 && ok) StdOut.println("Yes");
        else StdOut.println("No");
    }
}
