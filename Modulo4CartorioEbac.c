#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca de strings


int registro()
{
	char arquivo [40]; //Criando variaveis
	char cpf [40]; 
	char nome [40]; 
	char sobrenome [40]; 
	char cargo [40]; //Criando variaveis
	
	printf ("Digite o CPF a ser cadastrado: ");
	scanf ("%s", cpf); //Salvando resposta na variavel
	
	strcpy (arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //Criando o arquivo
	file = fopen (arquivo, "w"); //Definindo o nome do arquivo
	fprintf (file, cpf); //Salvando o valor da variavel
	fprintf (file, ", \n"); //Organizando com a ,
	fclose (file); //Fechando o arquivo
	
	printf ("Digite o nome a ser cadastrado: ");
	scanf ("%s", nome); //Salvando resposta na variavel
	
	file = fopen (arquivo, "a");//Atualizando o arquivo
	fprintf (file, nome); //Salvando o valor da variavel
	fclose (file); //Fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf ("%s", sobrenome); //Salvando resposta na variavel
	
	file = fopen (arquivo, "a"); //Atualizando o arquivo
	fprintf (file, sobrenome); //Salvando o valor da variavel
	fprintf (file, "\n"); //Organizando com a ,
	fclose (file); //Fechando o arquivo
	 
	printf("Digite o cargo a ser cadastrado: ");
	scanf ("%s", cargo); //Salvando resposta na variavel
	
	file = fopen (arquivo, "a"); //Atualizando o arquivo
	fprintf (file, cargo); //Salvando o valor da variavel
	fprintf (file, "\n"); //Organizando com a ,
	fclose (file); //Fechando o arquivo
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguaguem 
	
	char cpf [40]; //Criando variavel
	char conteudo [200]; //Criando variavel
	
	printf ("Digite o CPF a ser consultado: ");
	scanf ("%s" ,cpf); //Salvando variavel
	
	FILE *file; 
	file = fopen(cpf, "r"); //Abrindo o arquivo e consultando

	
	if (file == NULL) //Se retornar nulo
	
	{
		printf ("N�o foi possivel localizar esse CPF.  \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Arnazenando em conteudo
	
	{
		printf ("\nEssas s�o as informa��es do usu�rio: \n");
		printf ("%s", conteudo);
		printf ("\n\n");
	}
	
	system ("pause");
}

int deletar()
{
	printf ("Voc� selecionou para deletar nomes \n\n");
	system ("pause");
}

int main ()
{
	int opcao=0; //Definindo variavel
	int laco=1; //Definindo o la�o
	
	for (laco=1;laco=1;) // Inicio do la�o
	{
	
		system("cls"); //Limpando a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguaguem 

		printf ("\t** Cart�rio da EBAC **\n\n "); //Inicio do menu
		printf ("Selecione a op��o desejada no menu: \n\n ");
		printf ("\t1 - Registrar nomes \n ");
		printf ("\t2 - Consultar nomes \n ");
		printf ("\t3 - Excluir nomes \n\n\n");
		printf ("Esse software � de livre uso dos alunos \n\n"); //Fim do menu
 
	
		scanf ("%d", &opcao); //Armazenando resposta do cliente
	
		system ("cls"); //Limpando o sistema
	
		switch(opcao) //Inicio da sele��o
		{
			case 1:
				registro();
			break;
			
			case 2:
				consulta();
			break;
			
			case 3:
				deletar();
			break;
				
			default:
				printf ("Essa op��o � invalida \n\n");
				system ("pause");	
			break; //Fim da sele��o
		}
	}
}

