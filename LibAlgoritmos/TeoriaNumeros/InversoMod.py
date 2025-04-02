def euclides(a, b):
    while b != 0: 
        a, b = b, a % b
    return a 
    
def inverso_mod_bruto(a, m):

    if (euclides(a, m) != 1):
        return None
    a = a % m                 # Evita calculos desnecessários se a for da forma a = p*m + k
    for x in range(1, m):     # Só testamos até m -1, pois no caso de m, teríamos "mod" == 0
        if (a * x) % m == 1:
            return x
    return None  

def euclides_estendido(a, b):
    if a == 0:
        return b, 0, 1
    gcd, x1, y1 = euclides_estendido(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return gcd, x, y

def inverso_mod(a, m):
    gcd, x, _ = euclides_estendido(a, m)
    if gcd != 1:
        return None 
    return x % m 

print(inverso_mod(3, 7))   # 5
print(inverso_mod(11, 18)) # 5
print(inverso_mod(39, 16)) # 7
print(inverso_mod(27, 3))  # None
