package search;


import java.util.LinkedList;
import java.util.Queue;

// 이진 탐색 트리 기반 심볼 테이블
public class BST<Key extends Comparable<Key>, Value> {
    private Node root;

    private class Node {
        private Key key; // 키
        private Value val; // 값
        private Node left, right; // 왼자식, 오른자식
        private int N; // 이 노드를 root로 하는 부분 트리의 노드 개수

        public Node(Key key, Value val, int N){
            this.key = key; this.val = val; this.N = N;
        }
    }

    public int size() {
        return size(root);
    }

    private int size(Node x) {
        if (x == null) return 0;
        else return x.N;
    }

    public Value get(Key key) {
        return get(root, key);
    }

    private Value get(Node x, Key key) {
        // x를 root로 가지는 부분 트리에서 key를 찾아 그 key와 연결된 value를 return
        // 부분 트리에 해당 key가 없으면 null을 return
        if (x== null) return null;
        int cmp = key.compareTo(x.key);
        if (cmp < 0) return get(x.left, key);
        else if (cmp > 0) return get(x.right, key);
        else return x.val;
    }

    public void put(Key key, Value val) {
        root = put(root, key, val);
    }

    private Node put(Node x, Key key, Value val) {
        if (x == null) return new Node(key, val, 1);
        int cmp = key.compareTo(x.key);
        if (cmp < 0) x.left = put(x.left, key, val);
        else if (cmp > 0) x.right = put(x.right, key, val);
        else x.val = val;
        x.N = size(x.left) + size(x.right) + 1; // 크기 업데이트: 왼자식 수 + 오른자식 수 + 자기자신
        return x;
    }

    public Key min() {
        return min(root).key;
    }

    private Node min(Node x) {
        if (x.left == null) return x;
        return min(x.left);
    }

    public Key max() {
        return max(root).key;
    }

    private Node max(Node x) {
        if (x.right == null) return x;
        return max(x.right);
    }

    public Key floor(Key key) {
        Node x = floor(root, key);
        if (x == null) return null;
        return x.key;
    }

    private Node floor(Node x, Key key) {
        if (x == null) return null;
        int cmp = key.compareTo(x.key);
        if (cmp == 0) return x;
        if (cmp < 0) return floor(x.left, key);
        Node t = floor(x.right, key);
        if (t != null) return t;
        else return x;
    }

    public Key ceiling(Key key) {
        Node x = ceiling(root, key);
        if (x == null) return null;
        return x.key;
    }

    private Node ceiling(Node x, Key key) {
        if (x == null) return null;
        int cmp = key.compareTo(x.key);
        if (cmp == 0) return x;
        if (cmp > 0)  return ceiling(x.right, key);
        Node t = ceiling(x.left, key);
        if (t != null) return t;
        else return x;
    }

    // k번째 key 값 찾기
    public Key select(int k) {
        return select(root, k).key;
    }

    private Node select(Node x, int k) {
        if (x == null) return null;
        int t = size(x.left);
        if (t > k) return select(x.left, k);
        else if (t < k) return select(x.right, k - t - 1);
        else return x;
    }

    // key 값의 순위 return
    public int rank(Key key) {
        return rank(root, key);
    }

    private int rank(Node x, Key key) {
        if (x == null) return 0;
        int cmp = key.compareTo(x.key);
        if (cmp < 0) return rank(x.left, key);
        else if (cmp > 0) return 1 + size(x.left) + rank(x.right, key);
        else return size(x.left);
    }

    public void deleteMin() {
        root = deleteMin(root);
    }

    private Node deleteMin(Node x) {
        if (x.left == null) return x.right;
        x.left = deleteMin(x.left);
        x.N = size(x.left) + size(x.right) + 1;
        return x;
    }

    public void delete(Key key) {
        root = delete(root, key);
    }

    private Node delete(Node x, Key key) {
        if (x == null) return null;
        int cmp = key.compareTo(x.key);
        // 현재 key가 왼쪽 서브트리에 있을 거 같아 왼쪽 서브트리에서 삭제
        if (cmp < 0) x.left = delete(x.left, key);
        // 현재 key가 오른쪽 서브트리에 있을 거 같아 오른쪽 서브트리에서 삭제
        else if (cmp > 0) x.right = delete(x.right, key);
        // key를 발견
        else {
            // 해당 key의 node의 오른쪽 서브트리가 없으면 왼쪽 서브트리를 연결
            if (x.right == null) return x.left;
            // 해당 key의 node의 왼쪽 서브트리가 없으면 오른쪽 서브트리를 연결
            if (x.left == null) return x.right;
            // 양쪽 서브트리가 다 있으면
            // 자신보다 작지만 가장 가까운 node(근후행 노드)가 delete될 node의 자리 차지
            // delete될 node의 left 서브트리는 근후행 노드의 left로
            // delete될 node의 right 서브트리는 근후행 노드를 delete한 후의 서브트리로 만들고 근후행 노드의 right로
            Node t = x;
            x = min(t.right);
            x.right = deleteMin(t.right); // delete되 node의 right 서브트리에서 제일 작은 값이 근후행 노드이므로 deleteMin 연산을 사용한다.
            x.left = t.left;
        }
        x.N = size(x.left) + size(x.right) + 1;
        return x;
    }

    private void print(Node x) {
        if (x == null) return;
        print(x.left);
        System.out.println(x.key);
        print(x.right);
    }

    // BST의 범위 기반 탐색
    public Iterable<Key> keys() {
        return keys(min(), max());
    }

    public Iterable<Key> keys(Key lo, Key hi) {
        Queue<Key> queue = new LinkedList<>();
        keys(root, queue, lo, hi);
        return queue;
    }

    private void keys(Node x, Queue<Key> queue, Key lo, Key hi) {
        if (x == null) return;
        int cmplo = lo.compareTo(x.key);
        int cmphi = hi.compareTo(x.key);
        if (cmplo < 0) keys(x.left, queue, lo, hi);
        if (cmplo <= 0 && cmphi >= 0) queue.add(x.key);
        if (cmphi > 0) keys(x.right, queue, lo, hi);
    }
}
