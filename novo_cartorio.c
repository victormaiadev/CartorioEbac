#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{	
    //inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,"CPF: "); 
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,"\nNOME: ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,nome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nSOBRENOME: ");
	fclose(file); 
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,"\nCARGO: ");
	fclose(file); 
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fprintf(file,"\n\n");
	fclose(file);
	
	system("pause");
	
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//inicio da cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); 
	
	FILE *file; 
	file = fopen(cpf,"r"); 
	
	
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir op arquivo, n�o localizado! \n");
	}
	
	printf("\nEssas s�o as informa��es do usu�rio: \n\n");
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("%s",conteudo);
	}
	
	system("pause");
	
	fclose(file);
}

int deletar()
{
    char cpf[40];
    
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); 
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if (file == NULL)
	{
		printf("\nCPF n�o encontrado!\n\n");
		system("pause");
	}
	
	
	remove(cpf);
	
	if(file != NULL)
	{
		printf("\nUsu�rio deletado com sucesso!\n\n");
		system("pause");
	}
	
}


int main ()
{
	int opcao=0; //declarando as vari�veis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
	
		system("cls");
		
    	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
    	printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
    	printf("Escolha a op��o desejada no menu:\n\n");
    	printf("\t1- Registrar nomes\n");
    	printf("\t2- Consultar nomes\n");
    	printf("\t3- Deletar nomes\n"); 
    	printf("\t4- Sair do sistema\n\n");
    	printf("Op��o: "); //final do menu

        scanf("%d", &opcao); //armazenando a escolha do usu�rio
    
        system("cls"); //comando para limpar tela ap�s a escolha do usu�rio
    
        switch (opcao)
		{
			case 1:
			registro(); //chamada de fun��es
        	break;
        	        	
        	case 2:
        	consulta();
        	break;
        	
        	case 3:
        	deletar();
        	break;
        	
        	case 4:
        	printf("Obrigado por utilizar o sistema!\n");
        	return 0;
        	break;
        	
        	default:
        	printf("Essa op��o n�o est� dispon�vel!\n");
    		system("pause");
    		break;
		}
		
    }

}
