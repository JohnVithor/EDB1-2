# Universidade Federal do Rio Grande do Norte
### Instituto Metrópole Digital - IMD
### Bacharelado em Tecnologia da Informação – BTI

### Implementando o Vector do C++

- Aluno: João Vítor Venceslau Coelho
- Professor: Selan Rodrigues dos Santos

### Resumo

Este programa tem como objetivo compreender o funcionamento do vector do C++
Implementando alguns métodos surportados pelo vector e testando sua corretude por meio do assert()

### Como Compilar
Utilize o comando 'make' no terminal do Linux.

### Como Executar
Após compilar o programa, digitar: ./bin/Vector no terminal

### Modo de usar
O programa não necessita de nenhum argumento via linha de comando ou durante sua execução.

### Resultados
Após ter iniciado o programa, serão mostradas na tela algumas mensagens sobre os testes realizados, para maiores detalhes de cada teste é necessário verificar o código-fonte no diretório src.

### Erros e outras informações
Ocorre o vazamento de memória (memory leak) durante a execução do programa.

Caso o método swap seja o último testado, ocorre uma falha de segmentação.

O Programa possivelmente contém mais problemas, porém ainda não foram encontrados.

Não foram utilizados smart pointers na implementação das classe sc::MyIterator e sc::vector.
