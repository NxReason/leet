class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def delete_duplicates(head: ListNode | None) -> ListNode | None:
    if head is None:
        return None

    clean_head = ListNode(head.val, None)
    clean_current = clean_head
    head = head.next
    while head is not None:

        if head.val != clean_current.val:
            clean_current.next = ListNode(head.val)
            clean_current = clean_current.next
        head = head.next

    return clean_head


def delete_duplicates2(head: ListNode | None) -> ListNode | None:
    if head is None:
        return None

    unique = set()
    while head is not None:
        unique.add(head.val)
        head = head.next

    unique_sorted = sorted(unique)
    out = ListNode(unique_sorted[0], None)
    current = out
    for val in unique_sorted[1:]:
        current.next = ListNode(val, None)
        current = current.next
    return out


def print_list(head: ListNode | None):
    while head is not None:
        print(head.val, end=' ')
        head = head.next
    print()


def run():
    l = ListNode(1, ListNode(1, ListNode(2, ListNode(3, ListNode(3, None)))))
    clean = delete_duplicates2(l)
    print_list(clean)


if __name__ == '__main__':
    run()
