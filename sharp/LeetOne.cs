using System.Globalization;

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

  // remove element
  public static int RemoveElement(int[] nums, int val)
  {
    int[] copy = new int[nums.Length];
    int notValCount = 0;
    for (int i = 0; i < nums.Length; i++)
    {
      if (nums[i] != val)
      {
        copy[notValCount] = nums[i];
        notValCount++;
      }
    }
    for (int i = 0; i < notValCount; i++)
    {
      nums[i] = copy[i];
    }

    return notValCount;
  }

  // plus one
  public static int[] PlusOne(int[] digits)
  {
    List<int> acc = new(digits.Length);
    int quot = 1;
    for (int i = digits.Length - 1; i >= 0; --i)
    {
      int curr = digits[i] + quot;
      quot = curr / 10;
      acc.Add(curr % 10);
    }
    if (quot == 1) acc.Add(quot);

    acc.Reverse();
    return acc.ToArray();
  }

  public static void RunPlusOne()
  {
    // var values = new int[] { 1, 4, 5, 9 };
    // PrintArray(PlusOne(values));
    var values = new int[] { 9 };
    PrintArray(PlusOne(values));
  }

  public static void PrintArray(int[] values)
  {
    Console.Write("Arr [");
    for (int i = 0; i < values.Length; i++)
    {
      Console.Write($"{values[i]}, ");
    }
    Console.WriteLine("]");
  }
}