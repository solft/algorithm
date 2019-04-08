package sort;

public class ShellSort extends BaseSort {
    private static void sort(Comparable[] a) {
        int N = a.length;
        int h = 1;
        while (h < N/3) h = 3 * h + 1; // 1, 4, 13, 40, 121, 364, 1093, ...
        while (h >= 1) {
            for (int i = h; i < N; i++) {
                for (int j = i; j >= h && less(a[j], a[j - h]); j -= h)
                    exch(a, j, j - h);
            }
            h = h / 3;
        }
    }

    public static void main(String[] args) {
        String[] a = "SHELLSORT".split("");
        show(a);
        sort(a);
        show(a);
    }
}
