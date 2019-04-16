import java.util.HashMap;

import static java.lang.Integer.max;

public class Tree {
    public int x;
    public Tree l;
    public Tree r;

    public int findDistinct(Tree node, HashMap<Integer, Integer> d) {
        if(node == null)
            return d.size();

        d.putIfAbsent(node.x, 0);
        d.put(node.x, d.get(node.x) + 1);

        int distinctValue = max(findDistinct(node.l, d), findDistinct(node.r, d));

        d.put(node.x, d.get(node.x) - 1);
        if(d.get(node.x) == 0)
            d.remove(node.x);

        return distinctValue;
    }

    public int solution(Tree T) {
        if(T == null)
            return 0;

        HashMap<Integer, Integer> distinctHash = new HashMap<>();

        return findDistinct(T, distinctHash);
    }

    public static void main() {

    }
}
