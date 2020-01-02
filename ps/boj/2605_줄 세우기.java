import java.util.Scanner;

// 2605번 줄 세우기
// 분류: 규칙 찾기
// 문제:
//      줄 선 상태에서
//      순서대로 자신이 뽑은 수만큼
//      앞으로 이동할 때
//      최종 순서를 구하는 문제
// 풀이:
//      거꾸로 맨 마지막 사람부터 시작해
//      자신이 뽑은 숫자 만큼 앞으로 가서
//      빈자리에 들어가면 된다.
//      (빈자리가 아니면 빈자리 나올 때 까지 전진)
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] drawNum = new int[n];

        for(int i=0; i<n; i++) {
            drawNum[i] = scanner.nextInt();
        }

        int[] ans = new int[n];

        for(int i=n-1; i>=0; i--) {

            int count = 0;
            int insertPosition = n - 1;

            while(insertPosition >= 0) {
                if (count == drawNum[i] && ans[insertPosition] == 0) {
                    ans[insertPosition] = i+1;
                    break;
                }
                if(ans[insertPosition] == 0)
                    count++;
                insertPosition--;
            }
        }

        for(int i=0; i<n; i++)
            System.out.print(ans[i] + " ");
        System.out.println();
    }
}

