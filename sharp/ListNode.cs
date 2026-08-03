public class ListNode
{
  public int val;
  public ListNode? next;
  public ListNode(int val = 0, ListNode? next = null)
  {
    this.val = val;
    this.next = next;
  }

  public void Print()
  {
    ListNode? cur = this;
    while (cur != null)
    {
      Console.Write($"{cur.val} ");
      cur = cur.next;
    }
  }
}