#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de memoria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca d responsavel por cuidar das strings

int registro() //fun��o responsavel pelo cadastro dos usuarios
{
	//cria��o das variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file,cpf); //salva a variavel
	fclose(file);   //fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
	
	
	
	
	
}
int consulta()
{
	setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
    {
          printf("Cadastro n�o localizado!. \n!");	
	}	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa�oes do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado!: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario n�o est� cadastrado!. \n");
		system("pause");
	}
}


int main ()
{
	int opcao=0; //definindo variaveis
	int x=1;
	for (x=1;x=1;)
	{
	
	
	    system("cls");
	    setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cart�rio EBAC ###\n\n"); //mensagem inicial
	    printf("Escolha a op��o desejada do menu: \n\n");
	    printf("\t1 -Registro de nomes\n");
	    printf("\t2 -Consultar os nomes\n");
	    printf("\t3 -Deletar os nomes\n\n");
	    printf("\t4 -Sair do programa\n\n");
	    printf("opcao: ");
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuario
	
	    system("cls");
	    
	    switch(opcao)
		{
			 case 1:
	    	 registro ();
             break;
             
             case 2:
             consulta ();
       	     break;
       	     
       	     case 3:
       	     deletar ();
     	     break;
     	     
     	     case 4:
     	     printf("Obrigado por ultilizar o sistema! \n");
     	     return 0;
     	     break;
     	     
     	     
     	     default:
     	     printf("N�o est� disponivel\n");
	 	     system("pause");
       	     break;
	    }
	
	    
    }
	    
}
