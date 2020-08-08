/**
 * Lt1071 字符串的最大公因子
 * 对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。
 *
 * 返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。
 *
 *  
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/greatest-common-divisor-of-strings
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Lt1071 {

    public String gcdOfStrings(String str1, String str2) {
        if (str1 == null || str2 == null) {
            return null;
        }
        if (str1.isEmpty() || str2.isEmpty()) {
            return "";
        }
        int sl1 = str1.length();
        int sl2 = str2.length();
        // len of gcd string is less than gcd of len(str1),len(str2)
        int gcdLen = gcd(sl1,sl2);
        for (int i = gcdLen;i>0;i--) {
            String prefix = str1.substring(0, i);
            if (check(prefix,str1) && check(prefix,str2)) {
                return prefix;
            }
        }
        return "";
    }

    public int gcd(int a,int b) {
        if (a<b) {
            return gcd(b,a);
        }
        if (a%b==0) {
            return b;
        }
        return gcd(b, a%b);
    }

    // check if the string is combine with the prefix
    public boolean check(String prefix, String origin) {
        if ("".equals(prefix)) {
            return true;
        }
        if (origin.length() < prefix.length()) {
            return false;
        }
        int prefixLen = prefix.length();
        int i = 0;
        for (;i+prefixLen<=origin.length();) {
            String t = origin.substring(i, i+prefixLen);
            if (!t.equals(prefix)) {
                return false;
            }
            i+=prefixLen;
        }
        return true;
    }
}