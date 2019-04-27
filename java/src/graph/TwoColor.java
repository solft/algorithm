package graph;

// 인접한 색은 다르게 2색으로 칠 할 수 있는가?
public class TwoColor {
    private boolean[] marked;
    private boolean[] color;
    private boolean isTwoColorable = true;

    public TwoColor(Graph G) {
        marked = new boolean[G.V()];
        color = new boolean[G.V()];
        for (int s = 0; s < G.V(); s++)
            if (!marked[s])
                dfs(G, s);
    }

    private void dfs(Graph G, int v) {
        marked[v] = true;
        for (int w : G.adj(v))
            if(!marked[w]) {
                color[w] = !color[v]; // 다음에 갈 곳은 현재 색의 반대 색이다.
                dfs(G, w);
            } else if (color[w] == color[v]) // 다음에 갈 곳이 이미 mark되어 있는데
                isTwoColorable = false;
    }

    public boolean isBipartite() { // bipartite (형) 양자간의; 2부로 구성된
        return isTwoColorable;
    }
}
