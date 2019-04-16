

public class HelloWorld {

    public static int[] alphabetToNumber(String a) {
        int[] result = new int[a.length()];
        for(int i = 0; i < a.length(); i++){
            result[i] = a.charAt(i) - 'a';
        }
        return result;
    }
    public static void main(String[] args) {
        int[] test = alphabetToNumber("rbwwrwbrrwbr");
        for(int i = 0; i < test.length; i++){
            System.out.print(test[i] + " ");
        }
        System.out.println();
    }
}
