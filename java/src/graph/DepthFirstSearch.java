package graph;

// Depth First Search
public class DepthFirstSearch {
    private boolean[] marked; // 방문 체크 배열
    private int count;

    public DepthFirstSearch(Graph G, int s) {
        marked = new boolean[G.V()]; // 정점의 수 많큼 방문 체크 배열 생성. 모두 false로 시작
        dfs(G, s); // dfs 시작
    }

    private void dfs(Graph G, int v) {
        marked[v] = true; // v 점을 방문하고
        count++;
        for (int w : G.adj(v)) // v의 인접 리스트를 반복하며
            if (!marked[w])
                dfs(G, w); // 방문하지 않았으면 방문ㄱ
    }

    public boolean marked(int w) { // w를 방문했는지?
        return marked[w];
    }

    public int count() {
        return count;
    }
}
