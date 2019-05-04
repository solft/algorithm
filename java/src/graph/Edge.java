package graph;

// 간선 하나
public class Edge implements Comparable<Edge> {
    private final int v; // 정점 하나
    private final int w; // 나머지 정점
    private final double weight; // 간선 가중치

    public Edge(int v, int w, double weight) {
        this.v = v;
        this.w = w;
        this.weight = weight;
    }

    public double weight() {
        return weight;
    }

    public int either() {
        return v;
    }

    public int other(int vertex) {
        if (vertex == v)
            return w;
        else if(vertex == w)
            return v;
        else
            throw new RuntimeException("Inconsistent edge");
    }

    public int compareTo(Edge that) {
        return Double.compare(this.weight(), that.weight());
    }

    public String toString() {
        return String.format("%d-%d %.5f", v, w, weight);
    }
}
