package sort;

// 힙 우선순위 큐
public class MaxPQ<Key extends Comparable<Key>> {
    private Key[] pq;  // 힙 정렬된 완전 이진 트리 1..N을 사용한다.(0은 자식갈 때 2 곱해도 0이므로 편의를 위해 사용안함)
    private int N = 0; // 힙의 사이즈

    public MaxPQ(int maxN) {
        pq = (Key[]) new Comparable[maxN + 1];
    }

    public boolean isEmpty(){
        return N == 0;
    }

    public int size(){
        return N;
    }

    public void insert(Key v){
        pq[++N] = v;
        swim(N);
    }

    public Key delMax() {
        Key max = pq[1];
        exch(1, N--);
        pq[N+1] = null;
        sink(1);
        return max;
    }

    private boolean less(int i, int j) {
        return pq[i].compareTo(pq[j]) < 0;
    }

    private void exch(int i, int j) {
        Key t = pq[i]; pq[i] = pq[j]; pq[j] = t;
    }

    // 아래에서 위로 자기 자리 찾아 올라가기
    private void swim(int k) {
        // 인덱스가 1 이상이고 부모가 더 작다면 올라간다.
        while(k > 1 && less(k/2, k)) {
            exch(k/2, k);
            k = k/2;
        }
    }

    // 위에서 아래로 자기 자리 찾아 내려가기
    private void sink(int k) {
        while(2*k <= N) {
            int j = 2*k;
            // 왼자식 오른자식 중 큰 애를 잡고
            if (j < N && less(j, j+1)) j++;
            // 자식 중 큰 애랑 비교해 크거나 같으면 그만하고
            if (!less(k, j)) break;
            // 아니면 바꾸고 다시 sink
            exch(k, j);
            k = j;
        }
    }
}
