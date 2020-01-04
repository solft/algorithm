public class Test {
    public static void main(String[] args) {
        String test = "LOVE";
        for (char c : test.toCharArray()) {
            System.out.println(c);
            if (c == 'O') {
                System.out.println("this is o");
            }
        }
    }
}
