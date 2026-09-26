TreeNode tn = new(
  1,
  null,
  new TreeNode(2, new TreeNode(3), null)
);

var res = Solution.InorderTraversal(tn);
foreach (int val in res)
{
  Console.WriteLine(val);
}

public class Solution
{
  public static IList<int> InorderTraversal(TreeNode root)
  {
    List<int> result = new();

    TraversalRec(root, result);

    return result;
  }

  public static void TraversalRec(TreeNode node, IList<int> acc)
  {
    if (node == null) return;

    if (node.left != null) TraversalRec(node.left, acc);
    acc.Add(node.val);
    if (node.right != null) TraversalRec(node.right, acc);
  }
}

public class TreeNode
{
  public int val;
  public TreeNode? left;
  public TreeNode? right;
  public TreeNode(int val = 0, TreeNode? left = null, TreeNode? right = null)
  {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}

