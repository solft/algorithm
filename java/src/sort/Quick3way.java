package sort;

public class Quick3way extends QuickSort {
    private static void sort(Comparable[] a, int lo, int hi) {
        if (hi <= lo) return;
        int lt = lo, i = lo + 1, gt = hi;
        Comparable v = a[lo];
        // 피벗보다 큰 값, 피벗과 같은 값, 피벗보다 작은 값 3가지 경우로 나눈다.
        while(i <= gt) {
            int cmp = a[i].compareTo(v);
            if (cmp < 0) exch(a, lt++, i++);
            else if (cmp > 0) exch(a, i, gt--);
            else i++;
        }
        sort(a, lo, lt-1);
        sort(a, gt + 1, hi);
    }
}
