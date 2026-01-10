/**
 * Lt337
 * 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。
 * 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
 * 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
 *
 * 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/house-robber-iii
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

public class Lt337 {

    public int rob(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int[] res = dfs(root);
        return Math.max(res[0],res[1]);
    }

    public int[] dfs(TreeNode root) {
        if (root == null) {
            return new int[]{0,0};
        }
        int[] l = dfs(root.left);
        int[] r = dfs(root.right);
        // rob root, not rob subs
        int selectedRoot = root.val + l[1] + r[1];
        // not rob root, subs choose max solution
        int notSelected = Math.max(l[0],l[1]) + Math.max(r[0],r[1]);
        return new int[]{selectedRoot, notSelected};
    }
}

