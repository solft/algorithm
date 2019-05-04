package graph;

import UnionFind.UnionFind;

import java.util.ArrayDeque;
import java.util.PriorityQueue;
import java.util.Queue;

// 크루스칼 알고리즘을 이용해서 MST 구하기
public class KruskalMST {
    private Queue<Edge> mst;

    public KruskalMST(EdgeWeightedGraph G) {
        mst = new ArrayDeque<>();
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        for (Edge e : G.edges())
            pq.add(e);
        UnionFind uf = new UnionFind(G.V());

        while(!pq.isEmpty() && mst.size() < G.V() - 1) {
            Edge e = pq.poll();
            int v = e.either(), w = e.other(v);
            if (uf.connected(v, w)) continue;
            uf.union(v, w);
            mst.add(e);
        }
    }

    public Iterable<Edge> edges() {
        return mst;
    }
}
