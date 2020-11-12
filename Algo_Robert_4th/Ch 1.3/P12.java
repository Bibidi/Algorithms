/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdOut;

public class P12 {
    public static Stack<String> copy(Stack<String> st) {
        Stack<String> temp = new Stack<String>();
        Stack<String> ret = new Stack<String>();

        for (String s : st) {
            temp.push(s);
        }

        for (String s : temp) {
            ret.push(s);
        }

        return ret;
    }

    public static void main(String[] args) {
        Stack<String> a = new Stack<String>();
        a.push("123");
        a.push("234");
        Stack<String> ans = copy(a);
        for (String s : ans)
            StdOut.println(s);
    }
}
