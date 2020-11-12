/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class P03 {
    public static void main(String[] args) {
        Stack<Integer> st = new Stack<Integer>();

        int cur = -1;
        for (int i = 0; i < 10; i++) {
            int item = StdIn.readInt();
            if (item < cur) {
                int temp = st.pop();
                if (temp != item) {
                    break;
                }
                StdOut.print(temp + " ");
            }
            else {
                while (cur < item) {
                    st.push(++cur);
                }
                StdOut.print(st.pop() + " ");
            }
        }
    }
}
