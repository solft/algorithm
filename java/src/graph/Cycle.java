package graph;

// Graph에 cycle이 있는지 체크
// 보통의 dfs와 다른 점은 dfs 시 현재 정점과 이전 정점을 같이 보낸다.
// 만약 갈 정점이 이미 mark 되어 있는데 이전 정점이 아니라면 cycle이 존재한다는 의미이다.
public class Cycle {
    private boolean[] marked;
    private boolean hasCycle;

    public Cycle(Graph G) {
        marked = new boolean[G.V()];
        for (int s = 0; s < G.V(); s++)
            if (!marked[s])
                dfs(G, s, s);
    }

    private void dfs(Graph G, int v, int u) {
        marked[v] = true;
        for (int w : G.adj(v))
            if (!marked[w])
                dfs(G, w, v);
            else if (w != u)
                hasCycle = true;
    }

    public boolean hasCycle() {
        return hasCycle;
    }
}
