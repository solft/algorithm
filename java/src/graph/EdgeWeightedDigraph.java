package graph;

// 가중 간선 방향 그래프
public class EdgeWeightedDigraph {
    private final int V; // 정점의 개수
    private int E; // 간선의 개수
    private Bag<DirectedEdge>[] adj; // 인접 리스트

    public EdgeWeightedDigraph(int V) {
        this.V = V;
        this.E = 0;
        adj = (Bag<DirectedEdge>[]) new Bag[V];
        for (int v = 0; v < V; v++)
            adj[v] = new Bag<>();
    }

    public int V() {
        return V;
    }

    public int E() {
        return E;
    }

    public void addEdge(DirectedEdge e){
        adj[e.from()].add(e);
        E++;
    }

    public Iterable<DirectedEdge> adj(int v) {
        return adj[v];
    }

    public Iterable<DirectedEdge> edges() {
        Bag<DirectedEdge> bag = new Bag<>();
        for(int v = 0; v < V; v++)
            for(DirectedEdge e : adj[v])
                bag.add(e);
        return bag;
    }
}
