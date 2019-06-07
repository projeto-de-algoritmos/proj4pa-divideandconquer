## Questão 1, página 247

1. You are interested in analyzing some hard-to-obtain data from two sepa-
rate databases. Each database contains n numerical values—so there are
2n values total—and you may assume that no two values are the same.
You’d like to determine the median of this set of 2n values, which we will
define here to be the n th smallest value.
However, the only way you can access these values is through queries
to the databases. In a single query, you can specify a value k to one of the
two databases, and the chosen database will return the k th smallest value
that it contains. Since queries are expensive, you would like to compute
the median using as few queries as possible.
Give an algorithm that finds the median value using at most O(log n)
queries.

#### Contextualização
A ideia do algoritmo se baseia em dois bancos de dados organizados. E segue os seguintes passos:

**1º:** Encontrar um valor k onde k é igual a n, o tamanho de cada um dos bancos de forma individual.

**2º:** Comparar o k/2 requisitado de cada um dos dois bancos e a partir daí delimitar as possíveis posições da mediana.

**3º:** Após comparar, o banco que retornar o menor valor precisa de um novo palpite, este palpite deve ser maior que o anterior assim como o do banco com palpite superior deve ser menor. Sendo assim, em cada um dos bancos são eliminados os valores que não são mais de interesse.

**4º:** Após no máximo log(n) comparações já que em cada recursão as possibilidades de mediana dos bancos reduzem à metade, o palpite k chega a ser igual a 1, ao chegar, retorna-se o menor valor entre as requisições da posição zero dos bancos.

O algoritmo desenvolvido pode ser encontrado no arquivo ```exercicio1.py```, ele foi feito especificamente para esse problema e foi testado a partir dos casos de teste guardados na pasta ```input```.

Para executar o código é necessário o python e pode ser executado com o seguinte comando:
```$python exercicio1.py```

O código também foi desenvolvido para que um usuário pudesse testá-lo sem muitas dificuldades, porém não foi feita nenhuma validação de entrada.



Caso queira utilizar um dos casos de testes já prontos basta utilizar o comando:
```$python exercicio1.py < input/in*```, onde * deve ser substituído pelo valor 1, 2 ou 3.

Lembrando que o terminal deve estar no diretório onde se encontra o arquivo .py.