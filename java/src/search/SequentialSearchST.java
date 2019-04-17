package search;

// 순차 탐색 심볼 테이블
public class SequentialSearchST<Key, Value> {
    private Node first;

    private class Node {
        Key key;
        Value val;
        Node next;
        public Node(Key key, Value val, Node next) {
            this.key = key;
            this.val = val;
            this.next = next;
        }
    }

    public Value get(Key key) {
        for (Node x = first; x != null; x = x.next)
            if (key.equals(x.key))
                return x.val; // 탐색 성공
        return null; // 탐색 실패
    }

    public void put(Key key, Value val) {
        for (Node x = first; x != null; x = x.next)
            if(key.equals(x.key))
            { x.val = val; return; } // 탐색 성공: 값 바꾸기
        first = new Node(key, val, first); // 탐색 실패: 새로운 노드 추가
    }

    public static void main(String[] args) {
        SequentialSearchST<String, Integer> st = new SequentialSearchST<>();
        st.put("java", 1);
        st.put("c++", 2);
        st.put("kotlin", 3);
        st.put("javascript", 4);

        System.out.println(st.get("kotlin"));
    }
}
