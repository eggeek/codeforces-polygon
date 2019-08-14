#!/usr/bin/env python3
n = int(input())
# odious number: http://oeis.org/A000069
seq = [0, 1, 2, 4, 7, 8, 11, 13, 14, 16, 19]
print (sum(seq[:n+1]))
