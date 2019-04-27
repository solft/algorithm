package graph;

// Connect Component
// 두 요소가 연결되어 있는지 확인하는 용도
// union-find와의 비교:
//      이론적으로는 DFS를 이용한 컴포넌트 검사가 상수 시간을 보장하기 때문에 빠르지만
//      실제로는 union-find가 전체 그래프에 대한 표현을 생성할 필요가 없어서 더 빠르다.
public class CC {
    private boolean[] marked;
    private int[] id;   // component 종류. 0 ~ count-1 의 종류가 있다.
    private int count;  // component 종류 개수.

    public CC(Graph G) {
        marked = new boolean[G.V()];
        id = new int[G.V()];
        for (int s = 0; s < G.V(); s++) {
            if (!marked[s]) {
                dfs(G, s);
                count++;
            }
        }
    }

    private void dfs(Graph G, int v) {
        marked[v] = true;
        id[v] = count;
        for (int w : G.adj(v))
            if (!marked[w])
                dfs(G, w);
    }

    public boolean connected(int v, int w) {
        return id[v] == id[w];
    }

    public int id(int v) {
        return id[v];
    }

    public int count() {
        return count;
    }
}

