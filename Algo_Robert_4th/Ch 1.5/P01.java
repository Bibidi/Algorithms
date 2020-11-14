/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class P01 {
    private int[] id;
    private int count;
    private int access;

    public P01(int N) {
        count = N;
        id = new int[N];
        for (int i = 0; i < N; i++)
            id[i] = i;
    }

    public int count() {
        return count;
    }

    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    public int find(int p) {
        access++;
        return id[p];
    }

    public void union(int p, int q) {
        int pID = find(p);
        int qID = find(q);

        if (pID == qID) return;
        for (int i = 0; i < id.length; i++) {
            if (id[i] == pID) id[i] = qID;
        }
        access += id.length;
        count--;
    }

    public static void main(String[] args) {
        P01 uf = new P01(10);

        while (!StdIn.isEmpty()) {
            int a = StdIn.readInt();
            int b = StdIn.readInt();
            uf.union(a, b);
        }

        for (int i : uf.id) {
            StdOut.print(i + " ");
        }
        StdOut.println();
        StdOut.println("access " + uf.access);
    }
}
