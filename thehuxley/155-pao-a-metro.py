def check_slice(arr, len_slice, qtd_per, qtd_bre):
	sum_b = 0
	for i in range(0, qtd_bre):
		sum_b += int(arr[i]/len_slice)
		if(sum_b >= qtd_per):
			return True
	return False

def main():
	qtd_per = int(input())
	qtd_bre = int(input())
	arr = input().split(' ')
	tam = 0
	for i in range(0, qtd_bre):
		arr[i] = int(arr[i])
	arr.sort()
	start = 0
	end = int(sum(arr)/qtd_per)
	while(start <= end):
		mid = int((start + end) / 2)
		if(check_slice(arr, mid, qtd_per, qtd_bre)):
			start = mid + 1
		else:
			end = mid - 1
	print(end)
main()
