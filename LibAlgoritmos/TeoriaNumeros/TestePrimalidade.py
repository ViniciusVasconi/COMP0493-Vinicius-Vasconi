import time

def isPrime_brute(n):
    if n < 2:
        return False
    for i in range(2, n):  # Verifica até a raiz quadrada de n
        if n % i == 0:
            return False
    return True

def isPrime_optimized(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):  # Verifica até a raiz quadrada de n
        if n % i == 0:
            return False
    return True

start1 = time.time()
for i in range(1, 10000):
    print(isPrime_brute(i))
end1 = time.time()

start2 = time.time()
for i in range(1, 10000):
    print(isPrime_optimized(i))
end2 = time.time()

execution_time1 = end1 - start1
execution_time2 = end2 - start2
print(f"Tempo de execução: {execution_time1:.6f} segundos")
print(f"Tempo de execução: {execution_time2:.6f} segundos")
