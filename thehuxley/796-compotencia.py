dp = []

def power(base, exp):
	ans = 1
	while(exp):
		if(exp & 1):
			ans *= base
		exp >>= 1
		base *= base
	return ans

def main():
	for i in range(0, 1001):
		dp.append(0)
	while True:
		try:
			n1, n2 = input().split()
			n1 = int(n1)
			n2 = int(n2)
			if(dp[n1] == 0):
				dp[n1] = power(n1, n1) % 100
			if(dp[n2] == 0):
				dp[n2] = power(n2, n2) % 100
			if(dp[n1] > dp[n2]):
				print(n1)
			elif(dp[n1] == dp[n2]):
				print(0)
			else:
				print(n2)
		except EOFError:
			break			

main()
