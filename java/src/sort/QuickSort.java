package sort;

import java.util.Collections;

public class QuickSort extends BaseSort {
    private static void sort(Comparable[] a) {
        StdRandom.shuffle(a);
        sort(a, 0, a.length - 1);
    }

    private static void sort(Comparable[] a, int lo, int hi) {
        if (hi <= lo) return;
        int j = partition(a, lo, hi);
        // 자기 자리를 찾은 인덱스 j의 왼쪽 부분과, 오른쪽 부분을 각각 sort 시켜준다.
        sort(a, lo, j-1);
        sort(a, j+1, hi);
    }

    private static int partition(Comparable[] a, int lo, int hi) {
        int i = lo, j = hi + 1;
        Comparable v = a[lo];
        while(true) {
            // 피벗보다 크거나 같은데 앞쪽에 있는 요소의 인덱스 찾기
            while(less(a[++i], v)) if (i == hi) break;
            // 피벗보다 작거나 같은데 뒤쪽에 있는 요소의 인덱스 찾기
            while(less(v, a[--j])) if (j == lo) break;
            // 모든 요소 다 검사하면 i 가 j 이상이되고 이러면 피벗 기준 왼쪽에는 작은 애들, 오른쪽에는 큰 애들로 정리된다.
            if (i >= j) break;
            // 찾은 작은 요소랑 큰 요소를 바꾼다.
            exch(a, i, j);
        }
        // 피벗 역할을 한 요소를 가운데에 위치시킨다.
        exch(a, lo, j);
        // 이제 인덱스 j의 요소는 자기 자리를 찾았다.
        return j;
    }

    public static void main(String[] args) {

    }
}
