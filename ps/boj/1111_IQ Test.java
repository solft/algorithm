import java.util.Scanner;

// 1111번 IQ Test
// 분류: 수학
// 문제:
//      ㅁ*a + b 꼴의 수열이 주어지고
//      a, b를 적절히 구해서 마지막 다음 수를 구하는 문제
//      답이 여러개면 "A", 없으면 "B" 출력
// 풀이:
//      수열의 수가 1일 때 무조건 답이 여러 개
//      수열의 수가 2일 때
//          두 수가 같으면 무조건 뒤는 같은수
//          두 수가 다르면 답은 여러개
//      우선 3개 항만 있으면 규칙을 구할 수 있다.
//          그런데 분모나 분자가 0일 때 답 구하는 것과 validation에 주의
//      풀긴 했는데 뭔가 수학적으로 빠져먹은게 많은 것 같다.
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] num = new int[n];

        for (int i = 0; i < n; i++) {
            num[i] = scanner.nextInt();
        }

        if (n == 1) {
            System.out.println("A");
        }
        else if (n <= 2) {
            if (num[0] == num[1]) {
                System.out.println(num[0]);
            } else {
                System.out.println("A");
            }
        } else {
            int bottom = num[1] - num[0];
            int top = num[2] - num[1];

            int a = 0;
            int b = 0;
            boolean isPossible = true;
            if (bottom == 0) {
                a = 1;
                b = 0;
            }
            else if (top % bottom == 0) {
                a = top / bottom;
                b = num[2] - num[1] * a;
            } else {
                isPossible = false;
            }

            // validation
            for (int i = 2; i < n; i++) {
                if (num[i - 1] * a + b != num[i] || !isPossible) {
                    isPossible = false;
                    break;
                }
            }

            if (isPossible) {
                System.out.println(num[n-1] * a + b);
            } else {
                System.out.println("B");
            }
        }
    }
}

