import matplotlib.pyplot as plt

# Suponha que estes são os seus resultados
tempos = [1956, 2864, 3771, 3353, 1956, 1955, 2305, 3423, 3282, 1955]
tamanhos = [1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000]

plt.figure(figsize=(10, 6))

# Cria um gráfico de linha
plt.plot(tamanhos, tempos, marker='o')

plt.title('Gráfico dos Resultados')
plt.xlabel('Número de Instantes')
plt.ylabel('Tempo de Execução Update (nano segundos)')

# Mostra o gráfico
plt.show()
