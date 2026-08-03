public class LeetOne
{
  public static ListNode? MergetTwoLists(ListNode? list1, ListNode? list2)
  {
    if (list1 == null) return list2;
    if (list2 == null) return list1;

    ListNode? head = new ListNode();
    if (list1?.val < list2?.val)
    {
      head = list1;
      list1 = list1.next;
    }
    else
    {
      head = list2;
      list2 = list2?.next;
    }
    ListNode? tail = head;

    while (list1 != null || list2 != null)
    {
      if (list1 == null)
      {
        tail!.next = list2;
        break;
      }
      if (list2 == null)
      {
        tail!.next = list1;
        break;
      }

      if (list1.val < list2.val)
      {
        tail!.next = list1;
        tail = list1;
        list1 = list1.next;
      }
      else
      {
        tail!.next = list2;
        tail = list2;
        list2 = list2.next;
      }
    }
    return head;
  }

  public static void RunMergeLists()
  {
    ListNode ln1 = new ListNode(4, null);
    ListNode ln2 = new ListNode(2, ln1);
    ListNode ln3 = new ListNode(1, ln2);

    ListNode an1 = new ListNode(4, null);
    ListNode an2 = new ListNode(3, an1);
    ListNode an3 = new ListNode(1, an2);

    var res = MergetTwoLists(ln3, an3);
    res?.Print();
  }
}