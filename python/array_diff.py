def array_diff(a, b):
    s = set(b)
    return [i for i in a if i not in s]


print(array_diff([1, 2], [1]))
print(array_diff([1, 2, 2, 2, 3], [2]))
