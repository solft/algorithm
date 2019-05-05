package graph;

// 가중 방향 간선
public class DirectedEdge {
    private final int v; // Edge의 꼬리 정점
    private final int w; // Edge의 머리 정점
    private final double weight; // Edge 가중치

    public DirectedEdge(int v, int w, double weight) {
        this.v = v;
        this.w = w;
        this.weight = weight;
    }

    public double weight() {
        return weight;
    }

    public int from() {
        return v;
    }

    public int to() {
        return w;
    }

    public String toString() {
        return String.format("%d->%d %d.2f", v, w, weight);
    }
}
