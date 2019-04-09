package sort;

public class MergeSort extends BaseSort {

    private static Comparable[] aux;

    private static void merge(Comparable[] a, int lo, int mid, int hi) {
        int i = lo, j = mid + 1;

        for(int k = lo; k <= hi; k++)   // a[lo...hi]를 aux[lo...hi]에 복제
            aux[k] = a[k];

        for(int k = lo; k <= hi; k++)   // 다시 a[lo...hi]로 병합
            if (i > mid) a[k] = aux[j++];
            else if (j > hi) a[k] = aux[i++];
            else if (less(aux[j], aux[i])) a[k] = aux[j++];
            else a[k] = aux[i++];
    }

    private static void sort(Comparable[] a) {
        aux = new Comparable[a.length];
        sort(a, 0, a.length - 1);
    }

    // Top-down Merge Sort
    private static void sort(Comparable[] a, int lo, int hi) {
        if (hi <= lo) return;
        int mid = lo + (hi - lo) / 2;
        sort(a, lo, mid);   // 왼쪽 정렬
        sort(a, mid + 1, hi);   // 오른쪽 정렬
        merge(a, lo, mid, hi);  // 병합(Merge)
    }

    // Bottom-up Merge Sort
    private static void sortBU(Comparable[] a) {
        int N = a.length;
        aux = new Comparable[N];
        for (int sz = 1; sz < N; sz = sz+sz)
            for (int lo = 0; lo < N-sz; lo += sz+sz)
                merge(a, lo, lo + sz - 1, Math.min(lo + sz + sz - 1, N - 1));
    }

    public static void main(String[] args) {
        String[] a = "MERGESORT".split("");
        show(a);
        sort(a);
        show(a);
    }
}
