#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca de strings


int registro()
{
	char arquivo [40]; //Criando variaveis
	char cpf [40]; //Criando variaveis
	char nome [40]; //Criando variaveis
	char sobrenome [40]; //Criando variaveis
	char cargo [40]; //Criando variaveis
	
	printf ("Digite o CPF a ser cadastrado: "); //Perguntando ao cliente
	scanf ("%s", cpf); //Salvando resposta na variavel
	
	strcpy (arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //Criando o arquivo
	file = fopen (arquivo, "w"); //Definindo o nome do arquivo
	fprintf (file, "CPF: "); //Organinando a resposta
	fprintf (file, cpf); //Salvando o valor da variavel
	fclose (file); //Fechando o arquivo
	
	printf ("Digite o nome a ser cadastrado: "); //Perguntando ao cliente
	scanf ("%s", nome); //Salvando resposta na variavel
	
	file = fopen (arquivo, "a");//Atualizando o arquivo
	fprintf (file, "\nNome e sobrenome: " ); //Organinando a resposta
	fprintf (file, nome); //Salvando o valor da variavel
	fclose (file); //Fechando o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Perguntando ao cliente
	scanf ("%s", sobrenome); //Salvando resposta na variavel
	
	file = fopen (arquivo, "a"); //Atualizando o arquivo
	fprintf (file, " "); //Organinando a resposta
	fprintf (file, sobrenome); //Salvando o valor da variavel
	fclose (file); //Fechando o arquivo
	 
	printf("Digite o cargo a ser cadastrado: "); //Perguntando ao cliente
	scanf ("%s", cargo); //Salvando resposta na variavel
	
	file = fopen (arquivo, "a"); //Atualizando o arquivo
	fprintf (file, "\nCargo: "); //Organinando a resposta
	fprintf (file, cargo); //Salvando o valor da variavel
	fprintf (file, "\n\n"); //Pulando linha
	fclose (file); //Fechando o arquivo
	
	printf ("\nO usu�rio foi cadastrado com sucesso!\n\n"); //Respondendo o cliente
	system ("pause"); //Pausando o sistema para leitura
	
}
	
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguaguem 
	
	char cpf [40]; //Criando variavel
	char conteudo [200]; //Criando variavel
	
	printf ("Digite o CPF a ser consultado: "); //Perguntando ao cliente
	scanf ("%s" ,cpf); //Salvando variavel
	
	FILE *file; //Acessando o fun��o
	file = fopen(cpf, "r"); //Abrindo o arquivo e consultando

	
	if (file == NULL) //Se retornar nulo
	{ 
		printf ("\nN�o foi possivel localizar esse CPF.  \n\n"); //Respondendo o cliente
	}
	
	else
	{
		printf ("\nEssas s�o as informa��es do usu�rio:\n"); //Respondendo o cliente
	}

	
	while(fgets(conteudo, 200, file) != NULL) //Arnazenando em conteudo
	
	{
		printf ("%s", conteudo); //Respondendo o cliente
	}

	fclose (file); //Fechando o arquivo
	
	system ("pause"); //Pausando o sistema para a leitura
	

}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguaguem
	
	char cpf[40]; //Criando a variavel
	
	printf ("Digite o CPF do usu�rio que deseja deletar: "); //Perguntando ao cliente
	scanf ("%s" ,cpf); //Armazenando resposta na variavel
	

	
	FILE *file; //Acessando a fun��o
	file = fopen (cpf, "r"); //Lendo o arquivo
	remove (cpf); //Removendo o arquivo
	fclose (file);
	
	 ;
	if (file == NULL) //Se n�o encontrar o arquivo
	{
		printf ("\nEsse CPF n�o foi encontrado no sistema! \n\n"); //Respondendo o cliente
	}
	
	else
	{
		printf ("\nO usu�rio foi deletado com sucesso! \n\n "); //Respondendo o cliente
    }
    
	remove (cpf); //Removendo o arquivo
    system ("pause"); //Pausando o sistema para a leitura]
    fclose (file); //Fechando o arquivo
}   

int main ()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguaguem
	
	int opcao=0; //Definindo variavel
	int laco=1; //Definindo o la�o
	char usuariodigitado [10]= "a";
	char senhadigitada [10]= "b";
	int comparacaousuario;
	int comparacaosenha;
	
	printf ("### Cart�rio da EBAC ### \n\n");
	printf ("\tLogin\n\n");
	printf ("Usu�rio:");
	scanf("%s", usuariodigitado);
	
	comparacaousuario = strcmp(usuariodigitado, "user");
	
	if (comparacaousuario == 0)
	{
		printf ("Senha:");
		scanf("%s", senhadigitada);
		comparacaosenha = strcmp(senhadigitada, "admin");

	}
	
	else
	{
		printf ("\nUsu�rio incorreto!");
		return 0;
	}
	

	
	if (comparacaosenha == 0)
	{	

	
		for (laco=1;laco=1;) // Inicio do la�o
		{
	
		system("cls"); //Limpando a tela
	
	

		printf ("\t** Cart�rio da EBAC **\n\n "); //Inicio do menu
		printf ("Selecione a op��o desejada no menu: \n\n ");
		printf ("\t1 - Registrar nomes \n ");
		printf ("\t2 - Consultar nomes \n ");
		printf ("\t3 - Excluir nomes \n");
		printf ("\t4 - Sair do sistema \n\n\n");
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
			
			case 4:
				printf ("Obrigado por utilizar o sistema! \n\n");
				return 0;
			break;
				
			default:
				printf ("Essa op��o � invalida \n\n");	
				system ("pause");
			break; //Fim da sele��o
		
			}
		}
	}
	
	else
		printf ("\n\nSenha incorreta! \n\n");
		
}

