import java.util.Scanner;

// 18247번 겨울왕국 티켓 예매
// 분류: 수학
// 문제:
//      N * M 크기의 좌석이 주어지고
//      좌상단부터 오른쪽 그리고 아래 방향으로
//      번호가 매겨질 때
//      L4 좌석은 몇 번인지 구하는 문제
// 풀이:
//      L이 12번째 알파벳이므로
//      column * 11에 4 더한 번호가 답이다.
//      그런데 col이 4 미만인 경우
//      구한 값이 전체 좌석 보다 큰 경우는
//      L4 좌석이 존재 할 수 없다.
public class Main {
    public static void main(String[] args) {
        // L4 자리 찾기
        // L은 12번째 알파벳
        Scanner scanner = new Scanner(System.in);
        int testCase = scanner.nextInt();

        for (int i = 0; i < testCase; i++) {
            int row = scanner.nextInt();
            int col = scanner.nextInt();

            if (col < 4) {
                System.out.println(-1);
                continue;
            }

            int ans = 11 * col + 4;

            if (ans > row * col)
                System.out.println(-1);
            else
                System.out.println(ans);
        }
    }
}
