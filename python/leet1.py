# --- 1 ---
def two_sum(nums: list[int], target: int) -> list[int]:
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                return [i, j]
    return []


def run_two_sum():
    print(two_sum([2, 7, 11, 15], 9))
    print(two_sum([3, 2, 4], 6))

# --- 2 ---


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def add_two_numbers(l1: ListNode | None, l2: ListNode | None) -> ListNode | None:
    out = None
    it: ListNode = ListNode()
    over = 0
    while l1 is not None or l2 is not None:
        current = 0
        if l1:
            current += l1.val
            l1 = l1.next
        if l2:
            current += l2.val
            l2 = l2.next
        current += over

        if current >= 10:
            current %= 10
            over = 1
        else:
            over = 0

        l = ListNode(current, None)
        if not out:
            out = l
            it = l
        else:
            it.next = l
            it = l

    if over == 1:
        it.next = ListNode(1, None)
        it = it.next

    return out


def arr_to_list(values):
    if len(values) == 0:
        return None

    it = ListNode(values[0], None)
    head = it
    for i in range(1, len(values)):
        l = ListNode(values[i], None)
        it.next = l
        it = l

    return head


def run_add_two_numbers():
    result = add_two_numbers(
        arr_to_list([9, 9, 9, 9, 9, 9, 9]),
        arr_to_list([9, 9, 9, 9])
    )
    while result:
        print(result.val)
        result = result.next

# --- 3 (longest substring) ---


def length_of_longest_substring(s: str):
    sub = s[:1]
    test = ''

    for c in s:
        if c in test:
            dup_idx = test.find(c)
            test = test[dup_idx + 1:]
        test += c

        if len(test) > len(sub):
            sub = test

    return sub


def run_longest_sub():
    print(length_of_longest_substring("abcabcbb"))
    print(length_of_longest_substring("bbbbb"))
    print(length_of_longest_substring("pwwkew"))


# length of last word
def last_word_len(s: str) -> int:
    parts = s.split(' ')
    non_ws = next((w for w in parts[::-1] if w != ''))
    return len(non_ws)


def run_last_word_len():
    print(last_word_len('hello world'))
    print(last_word_len('   fly me  to  the moon '))
    print(last_word_len('luffy is still joyboy'))


# climb stairs
def climb_stairs(n: int) -> int:
    memo = {}

    def rec(n: int) -> int:
        if n in memo:
            return memo[n]

        if n < 0:
            return 0
        if n == 0:
            return 1
        memo[n] = rec(n - 2) + rec(n - 1)
        return memo[n]
    return rec(n)


def run_climb_stairs():
    print(climb_stairs(2))
    print(climb_stairs(3))
    print(climb_stairs(185))


if __name__ == '__main__':
    run_climb_stairs()
