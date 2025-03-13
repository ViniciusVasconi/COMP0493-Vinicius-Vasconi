def rabin_karp(text, pattern, prime=101):
    """Implementação do algoritmo Rabin-Karp para busca de padrões em uma string."""
    d = 256  # Número de caracteres no alfabeto ASCII
    n = len(text)
    m = len(pattern)
    h = 1  # Valor da base elevada a (m-1), usado para remoção eficiente de caracteres
    pattern_hash = 0  # Hash do padrão
    text_hash = 0  # Hash da janela do texto
    matches = []
    
    # Calcula h = d^(m-1) % prime
    for i in range(m - 1):
        h = (h * d) % prime
    
    # Calcula o hash inicial do padrão e da primeira janela do texto
    for i in range(m):
        pattern_hash = (d * pattern_hash + ord(pattern[i])) % prime
        text_hash = (d * text_hash + ord(text[i])) % prime
    
    # Desliza a janela pelo texto
    for i in range(n - m + 1):
        # Se os hashes são iguais, verifica os caracteres manualmente
        if pattern_hash == text_hash:
            if text[i:i + m] == pattern:
                matches.append(i)
        
        # Calcula o hash da próxima janela do texto
        if i < n - m:
            text_hash = (d * (text_hash - ord(text[i]) * h) + ord(text[i + m])) % prime
            # Para evitar valores negativos
            if text_hash < 0:
                text_hash += prime
    
    return matches

# Exemplo de uso
text = "ababcabcabababd"
pattern = "ababd"
result = rabin_karp(text, pattern)
print("Padrão encontrado nos índices:", result)
