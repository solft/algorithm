import java.util.Scanner;

// 1296번 데이트
// 분류: 카운팅
// 문제:
//      주어진 알파벳 수를 세고
//      주어진 식으로 값을 구하고
//      최대를 가지는 이름을 출력하기
//      (여러개면 알파벳 빠른 순)
// 풀이:
//      각 이름별로 카운팅해서 풀면 된다.
//      중복 계산을 줄이기 위해 오민식이 이름은 따로 구해두는게
//      좋을 것 같다. (근데 그냥 함)
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String ohminsik = scanner.next();
        int girlsNumber = scanner.nextInt();

        int highScore = -1;
        String ans = "";
        for (int i = 0; i < girlsNumber; i++) {
            String girlName = scanner.next();
            int tempScore = getScore(ohminsik, girlName);
            if (highScore < tempScore) {
                highScore = tempScore;
                ans = girlName;
            } else if (highScore == tempScore) {
                if (ans.compareTo(girlName) > 0) {
                    ans = girlName;
                }
            }
        }

        System.out.println(ans);
    }

    public static int getScore(String boy, String girl) {
        int lNum = countAlphabet(boy, 'L') + countAlphabet(girl, 'L');
        int oNum = countAlphabet(boy, 'O') + countAlphabet(girl, 'O');
        int vNum = countAlphabet(boy, 'V') + countAlphabet(girl, 'V');
        int eNum = countAlphabet(boy, 'E') + countAlphabet(girl, 'E');

        return calculateScore(lNum, oNum, vNum, eNum);
    }

    public static int countAlphabet(String name, char target) {
        int counter = 0;
        for (char c : name.toCharArray()) {
            if (c == target)
                counter++;
        }
        return counter;
    }

    public static int calculateScore(int l, int o, int v, int e) {
        return ((l+o)*(l+v)*(l+e)*(o+v)*(o+e)*(v+e)) % 100;
    }
}

