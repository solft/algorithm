import java.util.Scanner;

// 17949번 Drop The Byte!
// 분류: 진수 변환
// 문제:
//      16진수로된 2, 8, 16자리 숫자들을
//      10진수로 변환해서 출력하는 문제
// 풀이:
//      그냥 10진수로 바꿔주면 된다.
//      결과가 int 범위 넘어가니 이것만 주의해주면 된다.
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String code = scanner.nextLine();
        int codeNumber = scanner.nextInt();
        String[] form = new String[codeNumber];
        for(int i = 0; i < codeNumber; i++) {
            form[i] = scanner.next();
        }

        int codeIndex = 0;
        long[] ans = new long[codeNumber];
        for (int i = 0; i < codeNumber; i++) {
            if ("int".equals(form[i])) {
                ans[i] = stringToNumber(code.substring(codeIndex, codeIndex + 8));
                codeIndex += 8;
            } else if ("char".equals(form[i])) {
                ans[i] = stringToNumber(code.substring(codeIndex, codeIndex + 2));
                codeIndex += 2;
            } else if ("long_long".equals(form[i])) {
                ans[i] = stringToNumber(code.substring(codeIndex, codeIndex + 16));
                codeIndex += 16;
            }
        }

        for (int i = 0; i < codeNumber; i++) {
            System.out.print(ans[i]);
            if (i == codeNumber - 1)
                System.out.println();
            else
                System.out.print(" ");
        }
    }

    public static long stringToNumber(String numberString) {
        long ret = 0;
        long multiplier = 1;

        for (int i = 0; i < numberString.length(); i++) {
            ret += multiplier * charToNumber(numberString.charAt(numberString.length() - i - 1));
            multiplier *= 16;
        }

        return ret;
    }

    public static long charToNumber(char character) {
        if (character >= '0' && character <= '9')
            return character - '0';
        else
            return character - 'a' + 10;
    }
}

