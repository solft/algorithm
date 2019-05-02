package graph;

import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Stack;

// 방향 그래프에서 정점 순서를 만들기 위한 DFS
public class DepthFirstOrder {
    private boolean[] marked;

    private Queue<Integer> pre; // 선행 순서 정점 목록
    private Queue<Integer> post; // 후행 순서 정점 목록
    private Stack<Integer> reversePost; // 반전된 후행 순서 정점 목록

    public DepthFirstOrder(Digraph G) {
        pre = new ArrayDeque<>();
        post = new ArrayDeque<>();
        reversePost = new Stack<>();
        marked = new boolean[G.V()];

        for (int v = 0; v < G.V(); v++)
            if(!marked[v])
                dfs(G, v);
    }

    private void dfs(Digraph G, int v) {
        pre.add(v); // 선행은 먼저 넣는다.

        marked[v] = true;
        for (int w : G.adj(v))
            if(!marked[w])
                dfs(G, w);

        post.add(v); // 후행은 뒤에서 넣는다.
        reversePost.push(v); // 반전 후행은 스택에 넣는다.
    }

    public Iterable<Integer> preorder() {
        return pre;
    }
    public Iterable<Integer> postorder() {
        return post;
    }
    public Iterable<Integer> reversePostorder() {
        return reversePost;
    }
}
