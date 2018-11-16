def search(houses, start, end, element):
	mid = int((start + end) / 2)
	if(houses[mid] == element):
		return mid 
	elif(houses[mid] > element):
		return search(houses, start, mid, element)
	else:
		return search(houses, mid + 1, end, element)
def main():
	n, m = input().split()
	n = int(n)
	m = int(m)
	houses = input().split()
	deliveries = input().split()
	for i in range(n):
		houses[i] = int(houses[i])
	for i in range(m):
		deliveries[i] = int(deliveries[i])
	actual_house = 0
	sum_time = 0
	for i in range(m):
		next_house = search(houses, 0, n, deliveries[i])
		sum_time += abs(actual_house - next_house)		
		actual_house = next_house
	print(sum_time)
main()