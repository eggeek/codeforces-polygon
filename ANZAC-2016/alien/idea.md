## Description
    There are some aliens from 3 different planets: 2-eyes planet, 3-eyes planet, 4-eyes planet.
    And we know:
    1. Aliens with same eyes can feel each other;
    2. Aliens can feel the guys whose the difference of the number of their eyes is 1, but not always;
    3. If the difference of their eyes greater than 1, they can't feel each other;

    Now we have a report from N aliens:

        a12, a13, a14
        a22, a23, a24
        ...
        an2, an3, an4

    Which means how many 2-eyes aliens, 3-eyes aliens, 4-eyes aliens, they can feel.

## Problem (easy version)
    Find the max possible of the number of 2-eyes alien ( assume the report is always valid ).

### hint & solution
    ai2 <= the number of 2-eyes alien, so as ai4 and ai5. Thus the answer is max({ai2 | i in [1, n]})
    Tag: greedy

## Problem (harder version)
    Find the max possible of the number of 2-eyes alien, or make the judgement that the report
    is invalid.
    Tag: implementation

## Problem (new version)
    Aliens can not distinguish the planets others from, so the report becomes:
    a12 + a13 + a14
    a22 + a23 + a24
    ...
    an2 + an3 + an4

### hint & solution
    I can not figure out a high-efficiency solution.

- hint:
    Assume there are A 2-eyes, B 3-eyes, C 4-eyes. Enumerate the A and B, so C = n - (A+B), and check
    whether it is possible, which becomes a new problem:
        Given 3 intervals and n integers, check whether can assign those integers to 3 intervals
        and let them have exactly A, B and C integers respectively.
    The subproblem can be solved by using O(n^3) dp, so the global complexity is O(n^5)
    Tag: dp, brute force
