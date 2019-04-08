package sort;

public class InsertionSort extends BaseSort {
    private static void sort(Comparable[] a) {
        int N = a.length;
        for (int i = 1; i < N; i++) {
            for (int j = i; j > 0 && less(a[j], a[j-1]); j--) {
                exch(a, j, j-1);
            }
        }
    }

    public static void main(String[] args) {
        String[] a = "INSERTIONSORT".split("");
        show(a);
        sort(a);
        show(a);
    }
}
