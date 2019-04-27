package graph;

import java.util.Stack;

// Depth First Paths
// 단일 원점에서 시작하는 경로
public class DepthFirstPaths {
    private boolean[] marked; // dfs()가 해당 정점에서 호출된 적이 있는가? marked[x] = true/false;
    private int[] edgeTo;   // 해당 정점으로 가는 경로의 마지막 정점. edgeTo[x] = y; (x) <-- edge -- (y) -- ... -- (...)
    private final int s; // 원점

    public DepthFirstPaths(Graph G, int s) {
        marked = new boolean[G.V()];
        edgeTo = new int[G.V()];
        this.s = s;
        dfs(G, s);
    }

    private void dfs(Graph G, int v) {
        marked[v] = true;
        for (int w : G.adj(v))
            if(!marked[w]){
                edgeTo[w] = v; // w <---- v;
                dfs(G, w);
            }
    }

    public boolean hasPathTo(int v) {
        return marked[v];
    }

    public Iterable<Integer> pathTo(int v) {
        if (!hasPathTo(v)) return null;
        Stack<Integer> path = new Stack<>();
        for (int x = v; x != s; x = edgeTo[x]) // 도착점 x에서 거꾸로 진행하며 원점 s에 도달할 때까지 반복
            path.push(x);
        path.push(s);
        return path;
    }
}
