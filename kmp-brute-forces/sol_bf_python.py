#!/usr/bin/env python3

def main():
    s = input()
    m = len(s)
    pre = [0] * m
    for i in range(1, m):
        for l in range(i,0,-1):
            if s[0:l] == s[i-l+1:i+1]:
                pre[i] = l
                break
    print (' '.join([str(i) for i in pre]))

if __name__ == "__main__":
    main()
