import sys

def split(fname, pref):
  rows = []
  with open(fname, 'r') as f:
    rows = f.readlines()
  n = int(rows[0].strip())
  idx = 1
  for i in range(1, n+1):
    casename = "tests/%s-%d.in" % (pref, i)
    casedata = rows[idx: idx+4]
    with open(casename, 'w') as f:
      f.write(''.join(casedata))
    idx+=5


if __name__ == "__main__":
  split(sys.argv[1], sys.argv[2])
