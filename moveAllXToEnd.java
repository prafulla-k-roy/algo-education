public class moveAllXToEnd {

    public static void moveX(String str, int idx, String newStr, int count) {
        if (idx == str.length()-1) {
            newStr += str.charAt(idx);
            for (int i=0; i<count; i++) {
                newStr += "x";
            }
            System.out.println(newStr);
            return;
        }
        char currentChar = str.charAt(idx);
        if (currentChar == 'x') {
            count++;
        } else {
            newStr += currentChar;
        }
        moveX(str, idx+1, newStr, count);
    }
    public static void main(String[] args) {
        String str = "axbcxxdxde";

        moveX(str, 0, "", 0);
    }
}
