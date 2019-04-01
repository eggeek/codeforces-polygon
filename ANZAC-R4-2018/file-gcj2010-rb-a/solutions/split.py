import sys

def split(fname, pref):
  rows = []
  with open(fname, 'r') as f:
    rows = f.readlines()
  cases = int(rows[0].strip())
  idx = 1
  for i in range(cases):
    casename = "tests/%s-%d.in" % (pref, i)
    n, m = map(int, rows[idx].strip().split())
    casedata = rows[idx: idx+n+m+1]
    with open(casename, 'w') as f:
      data = '\n'.join([i.strip() for i in casedata])
      f.write("%s\n" % data)
    idx += n + m + 1
  
if __name__ == "__main__":
  split(sys.argv[1], sys.argv[2])
