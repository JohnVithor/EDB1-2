# Dicionário - DAL / DSAL
## Dictionary with Array List ( DAL ) e Dictionary with Sorted Array List ( DSAL )

- Aluno: João Vítor Venceslau Coelho
- Professor: Selan Rodrigues dos Santos 

## Objetivo
A atividade tem como objetivo implementar dois tipos de dicionário com suporte às operações primárias e
secundárias abaixo:
	
	- Insert		: Permite inserir um par <Chave,Elemento> ao Dicionário
	- Remove		: Permite remover o par <Chave,Elemento> buscando pela Chave dele
	- Search		: Permite buscar o elemento do par <Chave,Elemento> buscando a Chave associada a ele
	- Max			: Permite recuperar o elemento associado à maior Chave armazenada no Dicionário
	- Min			: Permite recuperar o elemento associado à menor Chave armazenada no Dicionário
	- Predecessor	: Permite recuperar a Chave que precede a chave indicada ( imediatamente menor )
	- Sucessor		: Permite recuperar a Chave que sucede a chave indicada ( imediatamente maior )

### Descrição
Dois simples Dicionários com suporte aos métodos solicitados e testados no arquivo que foi fornecido.
Também foram adicionados os seguintes métodos:
	
	- capacity	: Indica qual a capacidade do Dicionário
	- empty		: Verifica se o Dicionário está vazio

Além da sobrecarga do operador << indicada no PDF com a descrição detalhada da atividade.

## Compilação
Para a compilação utilize o comando 'make' no terminal do Linux ( Certifique-se que os devidos diretórios foram criados anteriormente, ou digite make dir )
Para gerar a documentação digite 'make doxy' no terminal.

## Executar o programa
Para executar os testes digite:

	./bin/Dictionary
