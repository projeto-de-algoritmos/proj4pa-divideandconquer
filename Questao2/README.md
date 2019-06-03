## Questão 2, página 246

2. Recall the problem of finding the number of inversions. As in the text, we are given a sequence of **n** numbers a 1 , . . . , a n , which we assume are all distinct, and we define an inversion to be a pair ```i < j``` such that ```a(i) > a(j)```.
	We motivated the problem of counting inversions as a good measure
of how different two orderings are. However, one might feel that this
measure is too sensitive. Let’s call a pair a significant inversion if ```i < j``` and ```a(i) > 2a(j)``` . Give an ```O(n log n)``` algorithm to count the number of significant inversions between two orderings.

#### Contextualização
Como a questão sugere, os algorítmo para resolução desse problema tem por base a contagem de inversões, vista dentre os algorítmos de dividir para conquistar, porém com uma mudança na hora de considerar se a inversão foi válida ou não.
A princípio, parece ser uma alteração simples de se fazer, basta alterar a condição do ```if``` para ```(a[i] > 2*a[j])``` e estaria resolvido, porém existe um _corner case_ que quebra essa alteração. A contagem falha quando um valor é invertido com uma posição que guarda um valor maior que seu dobro, porém que é seguida de um valor que encaixa nessa condição, isso faz com que a quantidade de inversões fique maior que a esperada.
Após a análise das entradas, foi percebido que uma forma de validar se ocorreria esse aumento de inversões era contar quantos valores da lista estavam numa possição maior que seu dobro, ou seja, ```a[i] == 2*a[j]```, para ```i < j```. A quantidade de valores que se encaixarem nesse critério será igual a quantidade de inversões que o algorítmo retornará a mais, sendo necessário apenas uma subtração para resolver o problema.

#### Algoritmo
O algoritmo desenvolvido pode ser encontrado no arquivo ```exercicio2.cpp```, ele foi feito especificamente para esse problema e foi testado a partir dos casos de teste guardados na pasta ```input```, o resultado dos mesmos podem ser vistos na pasta ```output```.

Para compilar o código foram usadas as seguintes tags:
```-std=c++11 -O2 -Wall```

O código também foi desenvolvido para que um usuário pudesse testá-lo sem muitas dificuldades, porém não foi feita nenhuma validação de entrada.

Por fim, para utilizá-lo basta seguir os passos:
```$g++ -std=c++11 -O2 -Wall exercicio13.cpp```
```$./a.out```

Caso queira utilizar um dos casos de testes já prontos basta utilizar o comando:
```$./a.out < input/in*```, onde * deve ser substituído pelo valor 1, 2 ou 3.

Lembrando que o terminal deve estar no diretório onde se encontra o arquivo .cpp.

Todos os debugs foram deixados comentados no projeto. Para vê-los, basta descomentá-los.