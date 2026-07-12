import re


def reverse_words(text):
    words = re.split(r"(\s+)", text)
    return ''.join([w if re.match(r"^(s*)$", w) else w[::-1] for w in words])


def test():
    print(reverse_words("This is an example!"))
    print(reverse_words("double  spaces"))


if __name__ == '__main__':
    test()
