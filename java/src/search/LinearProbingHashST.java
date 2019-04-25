package search;

// linear-probing을 이용한 해싱
// collsion이 발생하면 다음 인덱스로 넘어가면서 빈 공간이 나올때 까지 진행하는 해싱
// search 시에는 키를 비교해 같으면 성공, null이면 탐색 실패, 다르면 다음 인덱스 시도
public class LinearProbingHashST<Key, Value> {
    private int N; // 테이블의 키/값 개수
    private int M = 16; // linear-probing 테이블의 크기
    private Key[] keys; // 키 항목들
    private Value[] vals; // 값 항목들

    public LinearProbingHashST() {
        keys = (Key[]) new Object[M];
        vals = (Value[]) new Object[M];
    }

    public LinearProbingHashST(int cap) {
        keys = (Key[]) new Object[cap];
        vals = (Value[]) new Object[cap];
        M = cap;
    }

    private int hash(Key key) {
        return (key.hashCode() & 0x7fffffff) % M;
    }

    private void resize(int cap) {
        LinearProbingHashST<Key, Value> t;
        t = new LinearProbingHashST<>(cap);
        for(int i = 0; i < M; i++)
            if(keys[i] != null)
                t.put(keys[i], vals[i]);
        keys = t.keys;
        vals = t.vals;
        M = t.M;
    }

    public void put(Key key, Value val) {
        if (N >= M/2) resize(2*M);

        int i;
        for (i = hash(key); keys[i] != null; i = (i + 1) % M)
            if (keys[i].equals(key)) { vals[i] = val; return; }
        keys[i] = key;
        vals[i] = val;
        N++;
    }

    public Value get(Key key) {
        for (int i = hash(key); keys[i] != null; i = (i + 1) % M)
            if (keys[i].equals(key))
                return vals[i];
        return null;
    }
}
