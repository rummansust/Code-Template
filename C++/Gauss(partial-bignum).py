# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4104
import math

MAXN = 15
mat = [[0 for i in range(MAXN)] for j in range(MAXN)]

def swap(a,b):
  temp = b
  b = a
  a = temp
  return a, b

def resetMat(n):
  for i in range(0,n):
    for j in range(0,n+1):
      mat[i][j] = 0

def printMat(n):
  print(":::::::::::::::::::::::::::::::::::")
  for i in range(0,n):
    for j in range(0,n+1):
      print('%s' % str(mat[i][j]).rjust(4), end=' ')
    print("")
  print(":::::::::::::::::::::::::::::::::::")

def gauss(n):
  pivot = 0
  for i in range(0,n):
    pivot = i
    for j in range(i+1, n):
      if abs(mat[j][i]) > abs(mat[pivot][i]):
        pivot = j
    if mat[pivot][i] == 0:
      continue
    if pivot != i:
      mat[i], mat[pivot] = swap(mat[i], mat[pivot])
    for x in range(i+1, n):
      if abs(mat[x][i]) == 0:
        continue
      L = math.lcm(mat[x][i], mat[i][i])
      f1 = L // mat[x][i]
      f2 = L // mat[i][i]
      for y in range(i+1, n+1):
        mat[x][y] = f1 * mat[x][y] - f2 * mat[i][y]
      mat[x][i] = 0

  sum = 0
  for i in range(n-1,-1,-1):
    sum = 0
    for j in range(i+1, n):
      sum += mat[i][j] * mat[j][n]
      mat[i][j] = 0
    mat[i][n] = (mat[i][n]-sum)//mat[i][i]
    mat[i][i] = 1
  return mat[0][n]

def LPS(s0, s1):
  l = min(len(s0), len(s1))
  for i in range(l,0,-1):
    if s0[l-i:] == s1[:i]:
      return i
  return 0

def solve(n, text):
  N = len(text)+1
  resetMat(N)
  mat[N-1][N-1] = 1
  mat[N-1][N] = 0
  for i in range(0, N-1):
    mat[i][i] = n
    mat[i][N] = n
    for k in range(0, n):
      prefix = text[:i]
      cur = prefix + chr(k + ord('A'))
      m = LPS(cur, text)
      mat[i][m] -= 1
  return gauss(N)

def readNextLine():
  while True:
    inp = input().split()
    if len(inp)>0:
      return inp

t = 0
inp = readNextLine()
t = int(inp[0])

n = 0
text = ""
for cas in range(1,t+1,1):
  inp = readNextLine()
  n = int(inp[0])
  text = str(inp[1])
  if cas > 1:
    print("")
  print("Case {0}:".format(cas))
  print(solve(n, text))
