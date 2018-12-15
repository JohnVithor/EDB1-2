# Universidade Federal do Rio Grande do Norte
### Instituto Metrópole Digital - IMD
### Bacharelado em Tecnologia da Informação – BTI

## Análise Empírica de Algoritmos de Ordenação

- Aluno: João Vítor Venceslau Coelho
- Professor: Selan Rodrigues dos Santos

### Resumo

Este programa tem como objetivo determinar qual algoritmo de ordenação, dos algoritmos analisados, é o ideal para ordenar um arranjo de inteiros positivos, e em qual situação cada algoritmo é recomendado.

## Como Compilar
Utilize o comando 'make' no terminal do Linux.

## Como Executar

##### Modo de usar

- '-a' - indica o modo de Análise Empírica
- '-t' - indica o modo de Teste
- '-v' - indica a utilização das funções com Vector por referência
- '-i' - indica a utilização das funções com Iteradores
- '-r (quantidade)' - indica o tamanho do range a ser utilizado (quantidade de elementos)
- '-q (quantidade)' - indica a quantidade de testes realizados em cada análise (exclusivo do modo de Análise Empírica)
- '-f (número da função)' - indica qual função deve ser testada (exclusivo do modo de teste)

##### Números de cada função
- 0 Insertion sort
- 1 Selection sort
- 2 Bubble sort
- 3 Merge sort
- 4 Quick sort
- 5 Shell sort
- 6 Radix sort

##### Exemplos de execução:

- (Modo teste)

        ./bin/Sorter -t -i -r5000 -f1      
        
- (Modo Análise)

        ./bin/Sorter -a -v -r5000 -q50
        
### Introdução

O problema da ordenação é basicamente encontrar uma permutação para um arranjo de forma que os seus elementos nessa permutação respeitem uma determinada ordem. Portanto a ideia de ordenar é:

        “Organizar itens em uma sequencia, com base em algum critério de ordem.”
        
Para ordenar, tanto uma ‘ordem fraca’, (não deve vir depois), pode ser especificada, ou uma ‘ordem fraca estrita’, (deve vir antes). Para a ordenação ser única, essas duas devem ser restritas a uma ordem total e a uma ordem total estrita, respectivamente.

A ordenação pode ser realizada baseando-se em um, ou mais, dos componentes do arranjo a ser ordenado. De forma mais geral, objetos podem ser ordenados baseados em uma de suas propriedades. Tal componente ou propriedade é chamada chave de ordenação.

Neste programa são utilizados os seguintes algoritmos de ordenação:

- Insertion sort
- Selection sort
- Bubble sort
- Shell sort
- Quick sort
- Merge sort
- Radix sort
 
Sendo que o apenas Radix sort utiliza um método de ordenação que não se baseia no valor representado pelo número como um todo, e sim no valor de cada um de seus dígitos.

### Descrição de Atividades (Método Utilizado)

Foi utilizada uma abordagem empírica para analise dos algoritmos, isto é, em vez de realizar uma abordagem teórica de cada algoritmo, verificando por meio de fórmulas matemáticas a complexidade temporal de cada algoritmo, foi cronometrado o tempo de execução de cada algoritmo em três cenários diferentes:

- Um arranjo com números inteiros em ordem não decrescente
- Um arranjo com números inteiros em ordem não crescente
- Um arranjo com números inteiros aleatórios, sem ordem aparente.

Para obter dados mais consistentes do tempo que cada algoritmo leva para realizar a ordenação, foi feita a media progressiva dos tempos encontrados em 10, 25 ou 50 execuções de cada algoritmo, em cada um dos cenários.

Cada algoritmo foi analisados com 25, 30 ou 50 arranjos de tamanhos diferentes, em cada um dos cenários, e o tempo médio  obtido foi utilizado para criar gráficos que representam o crescimento do tempo gasto. A quantidade de memória utilizada por cada algoritmo não foi analisada durante os testes.

### Material utilizado para a análise

- Processador: Intel® Pentium(R) CPU G2130 @ 3.20GHz × 2
- Memória: 3935848 kB (~4,0 GB) (DIMM DDR3 Síncrono 1333 MHz (0,8 ns) × 2)
- Placa-mãe: H61M-S2PH Gigabyte
- Sistema Operacional: Linux Ubuntu 16,04 x86_64
- Linguagem de Programação: C++
- Bibliotecas de importantes do C++: std::vector, std::chrono, std::random
- Compilador: g++ (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609
- Link para o repositório com o  código: github.com/JohnVithor/Sorter
- Gerar os gráficos:  Foram utilizadas os seguintes módulos de Python:
  - pandas 
  - numpy 
  - matplotlib.pyplot 
  - %matplotlib inline

### Bibliografia

- pt.wikipedia.org/wiki/Insertion_sort
- pt.wikipedia.org/wiki/Selection_sort
- pt.wikipedia.org/wiki/Bubble_sort
- pt.wikipedia.org/wiki/Shell_sort
- pt.wikipedia.org/wiki/Merge_sort
- pt.wikipedia.org/wiki/Quicksort
- pt.wikipedia.org/wiki/Radix_sort
- en.wikipedia.org/wiki/Insertion_sort
- en.wikipedia.org/wiki/Selection_sort
- en.wikipedia.org/wiki/Bubble_sort 
- en.wikipedia.org/wiki/Shellsort
- en.wikipedia.org/wiki/Merge_sort
- en.wikipedia.org/wiki/Quicksort
- en.wikipedia.org/wiki/Radix_sort
- geeksforgeeks.org/insertion-sort/
- geeksforgeeks.org/selection-sort/
- geeksforgeeks.org/bubble-sort/
- geeksforgeeks.org/shellsort/
- geeksforgeeks.org/merge-sort/
- geeksforgeeks.org/quick-sort/
- geeksforgeeks.org/radix-sort/
- pt.wikipedia.org/wiki/Algoritmo_de_ordenação
- pt.wikipedia.org/wiki/Ordenação_(computação)
- en.wikipedia.org/wiki/Sorting_algorithm
- en.wikipedia.org/wiki/Sorting
