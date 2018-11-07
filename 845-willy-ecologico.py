def search(h, n, arr):
	sum_h = 0
	cont = len(arr) - 2
	while True:
		sum_h = 0
		for i in range(0, n):
			if(arr[cont] <= arr[i]):
				sum_h += arr[i] - arr[cont]
		if(sum_h >= h):
			print(arr[cont])
			return
		cont -= 1
def main():
	n, h = input().split(' ')
	n = int(n)
	h = int(h)
	arr = input().split(' ')
	for i in range(0, n):
		arr[i] = int(arr[i])
	arr.sort()
	search(h, n, arr)

main()
