package graph;

// 가중 간선 그래프
public class EdgeWeightedGraph {
    private final int V; // 정점의 개수
    private int E; // 간선의 개수
    private Bag<Edge>[] adj; // 인접리스트

    public EdgeWeightedGraph(int V){
        this.V = V;
        this.E = 0;
        adj = (Bag<Edge>[]) new Bag[V];
        for (int v = 0; v < V; v++)
            adj[v] = new Bag<>();
    }

    public int V() { return V; }
    public int E() { return E; }

    public void addEdge(Edge e) {
        int v = e.either(), w = e.other(v);
        adj[v].add(e);
        adj[w].add(e);
        E++;
    }

    public Iterable<Edge> adj(int v) {
        return adj[v];
    }

    public Iterable<Edge> edges() {
        Bag<Edge> b = new Bag<>();
        for(int v = 0; v < V; v++)
            for(Edge e : adj[v])
                if(e.other(v) > V)
                    b.add(e);
        return b;
    }
}
