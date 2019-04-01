import random


def work():
    testset = 100
    cases = []
    l = 1
    r = 10 ** 6
    for i in range(testset):
        a = random.randint(l, r)
        b = random.randint(l, r)
        cases.append("%d %d" % (a, b))

    cnt = 0
    for cas in cases:
        with open('test/test%d.in' % cnt, 'w') as f:
            f.write(cas)
            cnt += 1

if __name__ == "__main__":
    work()
