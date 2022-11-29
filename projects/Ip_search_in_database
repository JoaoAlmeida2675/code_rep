# ----------------------------------------------------------# START - Puxar import da urllib para trabalhar com sites

from urllib.request import urlopen

# ----------------------------------------------------------# Tratamento do ficheiro log.txt

ficheiro = open("YOUR_LOG", "r")
linhas = ficheiro.readlines()
ficheiro.close()

# ----------------------------------------------------------# Tratamento de listas onde a lista 1 recebe os ips do log e a lista 2 apresenta os ips sem estarem repetidos + index para cada ip

lista_1 = []
lista_2 = []

for i in range(0, len(linhas)):
    linha = linhas[i].split(" ")
    lista_1.append(linha[0])

for i in lista_1:
    if i not in lista_2:
        lista_2.append(i)

for index, ip in enumerate(lista_2, 1):

# ----------------------------------------------------------# Associar pagina com ip + transformar resultado em utf-8 + procurar keyword "was found" para comparar ips

    site = "https://abuseipdb.com/check/" + ip
    resultado = urlopen(site)

    html_in_bytes = resultado.read()
    pagina_html = html_in_bytes.decode("utf-8")

    posicao = pagina_html.find("was found")

# ----------------------------------------------------------# Ver ip a ip no abuse e apresentar index + ip + resultado abuse

    if posicao >= 0:
        print(index, " - ", ip, " - ", "Ip Referenciado!")
    else:
        print(index, " - ", ip, " - ", "Ip Ok!")

# ----------------------------------------------------------# END - To be continue
