n = int(input())
arr = []
for i in range(0, n):
	arr.append(int(input()))

arr_right = [0] * n
arr_left = []

arr_left.append(arr[0])
arr_right[ n - 1 ] = arr[ n - 1 ]

j = n - 2

for i in range(1, n):
	arr_left.append(max(arr_left[i - 1], arr[i]))
	arr_right[j] = max(arr_right[j + 1], arr[j])
	j -= 1

sumDays = 0
for i in range(0, n):
	if(arr_left[i] > arr[i] and arr_right[i] > arr[i]):
		sumDays += 1

print(sumDays)