package graph;

import java.util.TreeMap;

// 심볼 그래프 => DFS와 활용하여 분리 차수(Degrees of separation)을 구할 수 있다.
public class SymbolGraph {
    private TreeMap<String, Integer> st;  // 문자열 -> 인덱스
    private String[] keys;  // 인덱스 -> 문자열
    private Graph G;

    // 심볼 크기만큼 그래프와 keys 사이즈를 정한다.
    public SymbolGraph(int V) {
        st = new TreeMap<>();
        keys = new String[V];
        G = new Graph(V);
    }

    // symbol a와 symbol b를 연결
    public void connect(String a, String b) {
        if(!st.containsKey(a))
            st.put(a, st.size());
        if(!st.containsKey(b))
            st.put(b, st.size());
        for (String name : st.keySet())
            keys[st.get(name)] = name;
        G.addEdge(st.get(a), st.get(b));
    }

    public boolean contains(String s) { return st.containsKey(s); }
    public int index(String s) { return st.get(s); }
    public String name(int v) { return keys[v]; }
    public Graph G() { return G; }
}
