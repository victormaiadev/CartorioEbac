#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsável por cadastrar os usuários no sistema
{	
    //inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,"CPF: "); 
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,"\nNOME: ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,nome); //salva o valor da variável
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
	
	//inicio da criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuário
	scanf("%s",cpf); 
	
	FILE *file; 
	file = fopen(cpf,"r"); 
	
	
	
	if(file == NULL)
	{
		printf("Não foi possível abrir op arquivo, não localizado! \n");
	}
	
	printf("\nEssas são as informações do usuário: \n\n");
	
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
    
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); 
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if (file == NULL)
	{
		printf("\nCPF não encontrado!\n\n");
		system("pause");
	}
	
	
	remove(cpf);
	
	if(file != NULL)
	{
		printf("\nUsuário deletado com sucesso!\n\n");
		system("pause");
	}
	
}


int main ()
{
	int opcao=0; //declarando as variáveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
	
		system("cls");
		
    	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
    	printf("### Cartório da EBAC ###\n\n"); //inicio do menu
    	printf("Escolha a opção desejada no menu:\n\n");
    	printf("\t1- Registrar nomes\n");
    	printf("\t2- Consultar nomes\n");
    	printf("\t3- Deletar nomes\n"); 
    	printf("\t4- Sair do sistema\n\n");
    	printf("Opção: "); //final do menu

        scanf("%d", &opcao); //armazenando a escolha do usuário
    
        system("cls"); //comando para limpar tela após a escolha do usuário
    
        switch (opcao)
		{
			case 1:
			registro(); //chamada de funções
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
        	printf("Essa opção não está disponível!\n");
    		system("pause");
    		break;
		}
		
    }

}
