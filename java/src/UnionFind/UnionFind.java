package UnionFind;

public class UnionFind {
    private int[] id; // 부모 링크 (사이트가 인덱스로 사용됨)
    private int[] sz; // 각 root node가 속한 tree의 node 개수(덩어리 크기)
    private int count; // 컴포넌트들의 개수

    public UnionFind(int N) {
        count = N;
        id = new int[N];
        for (int i = 0; i < N; i++) id[i] = i;
        sz = new int[N];
        for (int i = 0; i < N; i++) sz[i] = 1;
    }

    public int count() {
        return count;
    }

    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    public int find(int p) {
        while (p != id[p]) p = id[p];
        return p;
    }

    public void union(int p, int q) {
        int i = find(p);
        int j = find(q);

        if (i == j) return;

        // 작은 tree의 root가 큰 tree에 root 밑으로 연결됨
        if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
        else { id[j] = i; sz[i] += sz[j]; }
        count--;
    }
}
