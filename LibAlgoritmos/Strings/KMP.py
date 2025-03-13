def compute_lps(pattern):
    """Calcula o array de prefixo mais longo que também é sufixo (LPS) para o padrão."""
    lps = [0] * len(pattern)
    length = 0  # Comprimento do prefixo mais longo
    i = 1
    
    while i < len(pattern):
        if pattern[i] == pattern[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
    return lps

def kmp_search(text, pattern):
    """Executa a busca do padrão no texto usando o algoritmo KMP."""
    n = len(text)
    m = len(pattern)
    lps = compute_lps(pattern)
    
    i = 0  # Índice para text
    j = 0  # Índice para pattern
    
    matches = []
    
    while i < n:
        if text[i] == pattern[j]:
            i += 1
            j += 1
        
        if j == m:
            matches.append(i - j)
            j = lps[j - 1]
        elif i < n and text[i] != pattern[j]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1
    
    return matches

# Exemplo de uso
text = "ababcabcabababdababd"
pattern = "ababd"
result = kmp_search(text, pattern)
print("Padrão encontrado nos índices:", result)
