def gen(s, l):
    res = ['0'] * l
    for i in range(len(s)):
        res[i] = s[i]
    for i in range(len(s), l):
        res[i] = '0' if res[l-1-i] == '1' else '1'
    return ''.join(res)


def check(s):
    s2 = list(s)
    s2.reverse()
    s2 = ['0' if i == '1' else '1' for i in s2]
    return ''.join(s2) == s


def main():
    s = input()
    l = len(s)
    while True:
        if l % 2 == 1:
            l += 1
        res = gen(s, l)
        if check(res):
            return res
        else:
            l += 1

if __name__ == "__main__":
    res = main()
    print (res)
