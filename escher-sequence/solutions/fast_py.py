#!/usr/bin/env python3

def init_pre(s):
    m = len(s)
    pre = [0] * m
    for i in range(1, m):
        j = pre[i-1]
        while (j > 0 and s[i] != s[j]): j = pre[j-1]
        if (s[i] == s[j]): pre[i] = j+1
    return pre

def main():
    s = input()
    s2 = ''.join(reversed(['1' if i == '0' else '0' for i in s])) + s
    pre = init_pre(s2)
    L = len(s) * 2 - min(pre[-1], len(s))
    res = [''] * L
    for i in range(len(s)): res[i] = s[i]
    for i in range(len(s), L): res[i] = '1' if s[L-1-i] == '0' else '0'
    print (''.join(res))

if __name__ == "__main__":
    main()
