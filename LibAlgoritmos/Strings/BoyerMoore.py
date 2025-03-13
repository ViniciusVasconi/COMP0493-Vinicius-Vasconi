def bad_character_table(pattern):
    """Cria a tabela de deslocamento para a heurística do mau caractere."""
    table = {}
    m = len(pattern)
    
    for i in range(m - 1):  # Percorre o padrão, exceto o último caractere
        table[pattern[i]] = m - 1 - i  # Calcula o deslocamento

    return table

def boyer_moore(text, pattern):
    """Implementação do algoritmo Boyer-Moore usando a heurística do mau caractere."""
    m = len(pattern)
    n = len(text)
    
    if m > n:
        return []  # O padrão é maior que o texto, impossível encontrar

    # Construção da tabela de mau caractere
    bad_char_table = bad_character_table(pattern)
    
    occurrences = []  # Lista de índices onde o padrão ocorre
    shift = 0  # Posição do padrão no texto
    
    while shift <= n - m:
        j = m - 1  # Começa a comparar do final do padrão
        
        while j >= 0 and pattern[j] == text[shift + j]:
            j -= 1  # Move para trás enquanto houver correspondência
        
        if j < 0:
            occurrences.append(shift)  # Encontramos uma ocorrência
            shift += m  # Avança o padrão inteiro
        else:
            # Aplica a heurística do mau caractere
            bad_char_shift = bad_char_table.get(text[shift + j], m)
            shift += max(1, bad_char_shift - (m - 1 - j))  

    return occurrences

# Exemplo de uso:
text = "abacaabadcabacabaabb"
pattern = "abacab"
result = boyer_moore(text, pattern)
print("Padrão encontrado nas posições:", result)
