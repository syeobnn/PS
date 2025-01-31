import sys


input = sys.stdin.readline


dp = [0] * 1011
dp[:3] = [0, 0, 1]

for i in range(2, 1001):
    if i % 2 == 0:
        dp[i + 1] = dp[i] * 2 - 1
    else:
        dp[i + 1] = dp[i] * 2 + 1
    
while True:
    if (i := input()) != '':
        n = int(i)
        print(dp[n])
    
    else:
        break