import edu.princeton.cs.algs4.Digraph;
import edu.princeton.cs.algs4.DirectedDFS;

public class TransitiveClosureEx {
    private DirectedDFS[] all;

    public TransitiveClosureEx(Digraph G) {
        all = new DirectedDFS[G.V()];
        for (int v = 0; v < G.V(); v++)
            all[v] = new DirectedDFS(G, v);
    }

    public boolean reachable(int v, int w) {
        return all[v].marked(w);
    }

    public static void main(String[] args) {

    }
}
