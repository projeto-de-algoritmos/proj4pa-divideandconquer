## Questão 3, página 246/247

3. Suppose you’re consulting for a bank that’s concerned about fraud detection, and they come to you with the following problem. They have a collection of _n_ bank cards that they’ve confiscated, suspecting them of being used in fraud. Each bank card is a small plastic object, containing a magnetic stripe with some encrypted data, and it corresponds to a unique account in the bank. Each account can have many bank cards corresponding to it, and we’ll say that two bank cards are equivalent if they correspond to the same account. 
It’s very difficult to read the account number off a bank card directly, but the bank has a high-tech “equivalence tester” that takes two bank cards and, after performing some computations, determines whether they are equivalent. 
Their question is the following: among the collection of _n_ cards, is there a set of more than _n/2_ of them that are all equivalent to one another? Assume that the only feasible operations you can do with the cards are to pick two of them and plug them in to the equivalence tester. Show how to decide the answer to their question with only ```O(n log n)``` invocations of the equivalence tester.

#### Contextualização
A ideia para o algorítmo veio a partir do algorítmo que encontra a mediana das medianas. Seguindo a mesma ideia de dividir o conjunto em pedaços menores, com tamanho 5, foi realizado o seguinte processo:
**1º:** Colocar todos cartões em uma fila;
**2º:** A partir do tamanho atual da fila, ir retirando 5 ou menos cartões por vez;
**3º:** Comparar os cartões entre si e, caso haja igualdade entre eles, "uní-los" como um objeto só;
**4º:** Voltar o cartões para fila, considerando que cartões iguais ocupam a mesma posição;
**5º:** Repetir o processo até que o tamanho da fila não se altere.

#### Algoritmo
O algoritmo desenvolvido pode ser encontrado no arquivo ```exercicio3.cpp```, ele foi feito especificamente para esse problema e foi testado a partir dos casos de teste guardados na pasta ```input```, o resultado dos mesmos podem ser vistos na pasta ```output```.

Para compilar o código foram usadas as seguintes tags:
```-std=c++11 -O2 -Wall```

O código também foi desenvolvido para que um usuário pudesse testá-lo sem muitas dificuldades, porém não foi feita nenhuma validação de entrada.

Por fim, para utilizá-lo basta seguir os passos:
```$g++ -std=c++11 -O2 -Wall exercicio13.cpp```
```$./a.out```

Caso queira utilizar um dos casos de testes já prontos basta utilizar o comando:
```$./a.out < input/in*```, onde * deve ser substituído pelo valor 1 ou 2.

Lembrando que o terminal deve estar no diretório onde se encontra o arquivo .cpp.

Todos os debugs foram deixados comentados no projeto. Para vê-los, basta descomentá-los.