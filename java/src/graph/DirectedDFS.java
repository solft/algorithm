package graph;

// 방향 그래프에서의 DFS
public class DirectedDFS {
    private boolean[] marked;

    public DirectedDFS(Digraph G, int s) {
        marked = new boolean[G.V()];
        dfs(G, s);
    }

    public DirectedDFS(Digraph G, Iterable<Integer> sources) {
        marked = new boolean[G.V()];
        for (int s : sources)
            if (!marked[s]) dfs(G, s);
    }

    private void dfs(Digraph G, int v) {
        marked[v] = true;
        for (int w : G.adj(v))
            if (!marked[w]) dfs(G, w);
    }

    public boolean marked(int v){
        return marked[v];
    }

    public static void main(String[] args) {
        Digraph G = new Digraph(5);

        // 그래프 만들기
        G.addEdge(0, 1);
        G.addEdge(1, 2);
//        G.addEdge(2, 3);
        G.addEdge(4, 0);
        G.addEdge(4, 1);
        G.addEdge(4, 2);
        G.addEdge(2, 4);

        // startVertex에서 도달 가능한 vertex 찾기
        int startVertex = 0;
        DirectedDFS reachable = new DirectedDFS(G, startVertex);

        for(int v = 0; v < G.V(); v++)
            if(reachable.marked(v)) System.out.print(v +" ");
        System.out.println();
    }
}
