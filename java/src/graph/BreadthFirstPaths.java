package graph;

import java.util.LinkedList;
import java.util.Stack;

public class BreadthFirstPaths {
    private boolean[] marked; // 여기 정점에서 bfs를 했는가?
    private int[] edgeTo; // 이 정점으로 오기 이전에 거친 정점. edgeTo[x] = y, (x) <---- y
    private final int s; // 원점

    public BreadthFirstPaths(Graph G, int s) {
        marked = new boolean[G.V()];
        edgeTo = new int[G.V()];
        this.s = s;
        bfs(G, s);
    }

    private void bfs(Graph G, int s) {
        LinkedList<Integer> queue = new LinkedList<>();
        marked[s] = true;
        queue.offer(s); // queue에 삽입
        while(!queue.isEmpty()) {
            int v = queue.poll(); // 다음 정점 꺼내기
            for (int w : G.adj(v)) {
                if (!marked[w]) {
                    edgeTo[w] = v;
                    marked[w] = true;
                    queue.offer(w);
                }
            }
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

    public static void main(String[] args) {

        // 0 --- 1 --- 2
        //       |     |
        //       |     |
        //       3 --- 4 --- 5
        Graph g = new Graph(6);
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(1, 3);
        g.addEdge(2, 4);
        g.addEdge(3, 4);
        g.addEdge(4, 5);

        BreadthFirstPaths bfs = new BreadthFirstPaths(g, 0);
        System.out.println("TEST CODE");
        var test = bfs.pathTo(5);
        System.out.println(test);
    }
}
