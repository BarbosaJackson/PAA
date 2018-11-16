def count_sort(arr):
    arr_sort = [0] * (10**7 + 1)
    biggest = 0
    for i in arr:
        biggest = max(i, biggest)
        arr_sort[int(i)] += 1
    for i in range(biggest + 1):
        while(arr_sort[i] > 0):
            print(i)
            arr_sort[i] -= 1
    
def main():
    numbers = input().split()
    lenght = len(numbers)
    for i in range(lenght):
        numbers[i] = int(numbers[i])
    count_sort(numbers)
main()
