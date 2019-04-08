package sort;

public class SelectionSort extends BaseSort {

    private static void sort(Comparable[] a) {
        int N = a.length;
        for (int i = 0; i < N; i++) {
            int min = i; // 이번 for문에서 가장 작은 값을 가진 index
            for (int j = i + 1; j < N; j++)
                if (less(a[j], a[min]))
                    min = j;
            exch(a, i, min);
        }
    }

    public static void main(String[] args) {
        String[] a = "SELECTIONSORT".split("");
        show(a);
        sort(a);
        show(a);
    }
}
