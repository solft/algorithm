package String;

import java.util.Scanner;

public class KMP {
    private final int R; // the radix
    private int[][] dfa; // the KMP automoton

    private char[] pattern; // either the character array for the pattern
    private String pat; // or the pattern string

    public KMP(String pat){
        this.R = 256;
        this.pat = pat;

        // build DFA from pattern
        int m = pat.length();
        dfa = new int[R][m];
        dfa[pat.charAt(0)][0] = 1;
        for(int x = 0, j=1; j < m; j++){
            for(int c = 0; c < R; c++)
                dfa[c][j] = dfa[c][x]; // Copy mismatch cases.
            dfa[pat.charAt(j)][j] = j + 1; // Set match case.
            x = dfa[pat.charAt(j)][x]; // Update restart state.
        }
    }

    public KMP(char[] pattern, int R){
        this.R = R;
        this.pattern = new char[pattern.length];
        for(int j = 0; j < pattern.length; j++)
            this.pattern[j] = pattern[j];

        // build DFA from pattern
        int m = pattern.length;
        dfa = new int[R][m];
        dfa[pattern[0]][0] = 1;
        for(int x = 0, j = 1; j < m; j++){
            for(int c = 0; c < R; c++)
                dfa[c][j] = dfa[c][x];
            dfa[pattern[j]][j] = j + 1;
            x = dfa[pattern[j]][x];
        }
    }

    public int search(String txt) {
        int m = pat.length();
        int n = txt.length();
        int i, j; // i는 text의 인덱스, j는 pattern의 인덱스
        for(i = 0, j = 0; i < n && j < m; i++)
            j = dfa[txt.charAt(i)][j];
        if (j==m) return i - m; // found
        return n;
    }

    public int search(char[] text){
        int m = pattern.length;
        int n = text.length;
        int i,j;
        for(i = 0, j = 0; i < n && j < m; i++)
            j = dfa[text[i]][j];
        if (j == m) return i - m;
        return n;
    }

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        String pat = scan.nextLine();
        String txt = scan.nextLine();

        KMP kmp1 = new KMP(pat);
        int offset1 = kmp1.search(txt);

        System.out.println("text:    " + txt);
        System.out.print("pattern: ");
        for(int i=0; i<offset1; i++)
            System.out.print(" ");
        System.out.println(pat);
    }
}
