package graph;

public class Graph {
    private final int V;    // 정점(vertex) 개수
    private int E;          // 간선(edge) 개수
    private Bag<Integer>[] adj; // 인접 리스트

    public Graph(int V) {
        this.V = V;
        this.E = 0;
        adj = (Bag<Integer>[]) new Bag[V]; // 정점 수만큼 리스트 배열 생성
        for (int v = 0; v < V; v++)
            adj[v] = new Bag<Integer>();
    }

    public int V() { return V; }
    public int E() { return E; }

    public void addEdge(int v, int w) {
        adj[v].add(w);
        adj[w].add(v);
        E++;
    }

    public Iterable<Integer> adj(int v) {
        return adj[v];
    }
}
