import math
import random

def generate_random_arrays(num_arrays=5, min_size=5, max_size=15, min_value=-100, max_value=100):
    return tuple(
        [random.randint(min_value, max_value) for _ in range(random.randint(min_size, max_size))]
        for _ in range(num_arrays))


def radix_sortLSD(arr):
    if not arr: return

    min_val = min(arr)
    max_val = max(arr)

    offset = -min_val if min_val < 0 else 0
    arr = [x + offset for x in arr]  

    # Determina o número de dígitos do maior valor tratando o caso em que max_val == 0
    max_expo = math.ceil(math.log10(max_val + offset + 1)) if max_val + offset > 0 else 1

    for exp in range(max_expo):
        aux_arr = [[] for _ in range(10)]

        # Distribuir os elementos conforme o digito 
        for num in arr:
            digit = (num // (10 ** exp)) % 10
            aux_arr[digit].append(num)

        # Reescrever arr com os números ordenados pelo dígito atual
        arr = [num for bucket in aux_arr for num in bucket]

    # Remover o deslocamento 
    arr = [x - offset for x in arr]

    return arr


arrays = generate_random_arrays(num_arrays=20)
for array in arrays:
    sorted_array = sorted(array)
    my_sorted_array = radix_sortLSD(array)
    print(f"Original: \t {array}")
    print(f"Expected: \t {sorted_array}")
    print(f"Ordenado: \t {my_sorted_array}")
    print(sorted_array == my_sorted_array)
    print()


