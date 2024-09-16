def decompor_em_primos(n):
    if n in [0, 1]:
        return []

    fatores = []
    i = 2
    while n > 1:
        if n % i == 0:
            fatores.append(i)
            n //= i
        else:
            i += 1
    if fatores:
        return fatores
    else:
        return [n]
    
# ---------------------------------------------- exemplo de uso ----------------------------------------------

dict = {}
for i in range(0, 21):
    dict[i] = decompor_em_primos(i)

# imprime o dicionário, ordenando pela quantidade de divisores
for i in sorted(dict.items(), key=lambda x: len(x[1])):
    print(i[0],"\t", i[1])
