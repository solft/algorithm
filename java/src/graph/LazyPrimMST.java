package graph;

import java.util.ArrayDeque;
import java.util.PriorityQueue;
import java.util.Queue;

// Lazy한 프림 알고리즘을 이용해 MST 찾기
public class LazyPrimMST {
    private boolean[] marked; // MST 정점들
    private Queue<Edge> mst;  // MST 간선들
    private PriorityQueue<Edge> pq; // 횡단 간선들(부적합 포함)
    private double weight; // mst의 총 가중치

    public LazyPrimMST(EdgeWeightedGraph G) {
        pq = new PriorityQueue<>();
        marked = new boolean[G.V()];
        mst = new ArrayDeque<>();
        weight = 0;
        visit(G, 0);
        while(!pq.isEmpty()) {
            Edge e = pq.poll();
            int v = e.either(), w = e.other(v);
            if (marked[v] && marked[w]) continue; // 부적합 간선이면 무시
            mst.add(e);
            weight += e.weight(); // mst의 간선이므로 가중치를 추가한다.
            if(!marked[v]) visit(G, v);
            if(!marked[w]) visit(G, w);
        }
    }

    private void visit(EdgeWeightedGraph G, int v) {
        marked[v] = true;
        for (Edge e : G.adj(v))
            if (!marked[e.other(v)])
                pq.add(e);
    }

    public Iterable<Edge> edges() {
        return mst;
    }

    public double weight() {
        return weight;
    }

    public static void main(String[] args) {
        EdgeWeightedGraph G;
        G = new EdgeWeightedGraph(8); // 정점 8개 짜리 그래프로 테스트
        G.addEdge(new Edge(4, 5, 0.35));
        G.addEdge(new Edge(4, 7, 0.37));
        G.addEdge(new Edge(5, 7, 0.28));
        G.addEdge(new Edge(0, 7, 0.16));
        G.addEdge(new Edge(1, 5, 0.32));
        G.addEdge(new Edge(0, 4, 0.38));
        G.addEdge(new Edge(2, 3, 0.17));
        G.addEdge(new Edge(1, 7, 0.19));
        G.addEdge(new Edge(0, 2, 0.26));
        G.addEdge(new Edge(1, 2, 0.36));
        G.addEdge(new Edge(1, 3, 0.29));
        G.addEdge(new Edge(2, 7, 0.34));
        G.addEdge(new Edge(6, 2, 0.40));
        G.addEdge(new Edge(3, 6, 0.52));
        G.addEdge(new Edge(6, 0, 0.58));
        G.addEdge(new Edge(6, 4, 0.93));

        LazyPrimMST mst = new LazyPrimMST(G);
        for (Edge e : mst.edges())
            System.out.println(e);
        System.out.printf("%.5f\n", mst.weight());
    }
}
