package graph;

// 코사라주-샤리르 알고리즘
public class KosarajuSharirSCC {
    private boolean[] marked; // 도달된 정점
    private int[] id; // 컴포넌트 식별자
    private int count; // 강한 컴포넌트의 개수

    public KosarajuSharirSCC(Digraph G) {
        marked = new boolean[G.V()];
        id = new int[G.V()];
        DepthFirstOrder order = new DepthFirstOrder(G.reverse());
        for (int s : order.reversePostorder())
            if(!marked[s]){
                dfs(G, s);
                count++;
            }
    }

    private void dfs(Digraph G, int v) {
        marked[v] = true;
        id[v] = count;
        for (int w : G.adj(v))
            if(!marked[w])
                dfs(G, w);
    }

    public boolean stronglyConnected(int v, int w) {
        return id[v] == id[w];
    }

    public int id(int v) {
        return id[v];
    }

    public int count() {
        return count;
    }
}
