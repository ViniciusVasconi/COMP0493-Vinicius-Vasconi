import math 

def bucket_sort(arr):
    n = len(arr)
    if n == 0:
        return arr

    min_val, max_val = min(arr), max(arr)
    range_val = max_val - min_val + 1

    num_bucket = math.ceil(math.sqrt(n) if n < 35 else 1 + 3.3 * math.log10(n))
    buckets = [[] for _ in range(num_bucket)]

    for num in arr:
        index = int(((num - min_val) / range_val) * (num_bucket - 1))
        buckets[index].append(num)

    for i, buc in enumerate(buckets):
        print(f"{i} \t {buc}")

    sorted_arr = []
    for bucket in buckets:
        sorted_arr.extend(sorted(bucket))  

    return sorted_arr

# Observe que a implementação com teoria de divisão de intervalos se aplica melhor
#   aos intervalos inteiros. O código precisa ser adaptado para lidar com valores decimais.
arrays = ([0.78, 0.17, 0.39, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68],
          [2, 79, 3, 15, 76, 30, 69, 19, 52, 54, 12, 2, 3, 5, 76, 65, 45, 35,75, 35, 39, 49])
for arr in arrays:
    sorted_array = bucket_sort(arr)
    print()
    print("Array original:", arr)
    print("Array ordenado:", sorted_array)
    print()
