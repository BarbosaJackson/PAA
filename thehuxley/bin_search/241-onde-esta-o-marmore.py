arr = []

def search_first(pos):
	if(pos == 0 or arr[pos-1] != arr[pos]):
		return pos + 1
	else:
		return search_first(pos - 1)

def bin_search(start, end, element):
	if(start > end):
		return -1
	mid = int((start + end) / 2)
	if(arr[mid] == element):
		return search_first(mid)
	elif(arr[mid] < element):
		return bin_search(mid + 1, end, element)
	else:
		return bin_search(start, mid - 1, element)

def main(case):
	arr.clear()
	n, q = input().split(" ")
	n = int(n)
	q = int(q)
	if(n == 0 and q == 0):
		return
	for i in range(0, n):
		x = int(input())
		arr.append(x)
	arr.sort()
	print("CASE# {}:".format(case))
	for i in range(0, q):
		element = int(input())
		pos = bin_search(0, len(arr) - 1, element)
		if(pos == -1):
			print(element, "not found")
		else:
			print(element, "found at", pos)
	main(case + 1)
main(1)
