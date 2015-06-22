/*Locadora de Carros*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main (void) {

	setlocale(LC_ALL, "Portuguese");

	/*VARIÁVEIS DO MENU*/
	int selectmenu;
	int selectmenuDois;
	int nVezes=0;
	int i=0;
	int impressao;
	int count1=0, count2=0, count3=0;
	int cmpaux;
	int validacao=0;
    char comp[3]="f";
    int id=0;


	struct cadastro
	{
        char  placa[10];
        char  modelo[20];
        int   ano;
        char  disponibilidade[3]; //Verificar se precisa colocar vetores aqui
        float valorAluguel;
	};
	struct cadastro carros[100];

	struct clientes
	{
		char  cpf[15]; //Verificar se dar ara colocar como Char
		char  nome[50];
		char  endereco[50];

	};
	struct clientes cadastroClientes[100];

	struct aluguel
	{
		int   identificador;
		char  cpf[15]; //variavel duplicada, testar
		char  placa[10]; //variavel duplicada, testar
		int   dia, mes, ano;
		char  status[3];
	};

	struct aluguel cadastroAluguel[100];

while(selectmenu) {


	/*INTRODUÇÃO DO PROGRAMA*/
	printf("\n\n");
	printf("\t\t\t\tLOCARSOFT 1.0\n");
	printf("\t\t\t----------------------------\n");
	printf("\t\tThiago Cunha - Leandro Araujo\n");
	printf("\t-------------------------------------------------------------\n");
	printf("\t\t\t\tSEJA BEM VINDO\n");
	printf("\n\n\n\n");



	/*MENU PRINCIPAL DO PROGRAMA*/
	printf("----------------------------\n");
	printf("OPÇÕES DO SISTEMA\n");
	printf("----------------------------\n");

	printf("(1)Cadastrar carros\n");
	printf("(2)Cadastrar clientes\n");
	printf("(3)Aluguel\n");
	printf("(4)Imprimir dados\n");
	printf("(5)Sair\n\n\n");

    printf("Digite uma opção: ");
	scanf("%d", &selectmenu);

	switch(selectmenu) {

		/*Área de cadastramento de carros*/
		case 1:
		printf("\n\n\n\n");
		    printf("Quantos carros deseja cadastrar?");
		    scanf("%d", &nVezes);

		    for (i = 0; i < nVezes; i++)
		    {
		    	printf("Digite a placa do carro:: ");
		    	fflush(stdin);
		    	gets(carros[count1].placa);

		    	printf("Digite o modelo do carro:: ");
		    	fflush(stdin);
		    	gets(carros[count1].modelo);

		    	printf("Digite o ano do carro:: ");
		    	scanf("%d", &carros[count1].ano);

		    	printf("Digite ( S ) se está disponível, ou ( N ) para indisponível.:: ");
                fflush(stdin);
		    	gets(carros[count1].disponibilidade);

		    	printf("Digite o valor do aluguel:: ");
		    	scanf("%f", &carros[count1].valorAluguel);

                count1++;
		    	printf("\n\n\n\n");
		    }
		break;

		/*Área de cadastramento de clientes*/
		case 2:
			printf("\n\n\n\n");
			printf("Quantos clientes deseja cadastrar: ");
			scanf("%d", &nVezes);

			for (i = 0; i < nVezes; i++)
			{
				printf("Digite o CPF do cliente: ");
				fflush(stdin);
				gets(cadastroClientes[count2].cpf);

				printf("Digite o nome do cliente: ");
				fflush(stdin);
				gets(cadastroClientes[count2].nome);

				printf("Digite o endereço do cliente: ");
				fflush(stdin);
				gets(cadastroClientes[count2].endereco);

				printf("\n\n\n\n");

				count2++;
			}
		break;

		/*Área de aluguel de carros*/
		case 3:


			printf("----------------------------\n");
			printf("MENU DE ALUGUEL\n");
			printf("----------------------------\n");
			printf("(1)Cadastrar Aluguel\n");
			printf("(2)Dar Baixa em Aluguel\n");
			printf("(3)Sair\n");

			printf("Digite uma opção: ");
			scanf("%d", &selectmenuDois);

			switch(selectmenuDois){
				case 1:
				for (i = 0; i < 1; i++)
				{
					printf("Digite o ID do aluguel: ");
                    scanf("%d", &cadastroAluguel[count3].identificador);

                    printf("Digite o CPF do cliente: ");
                    fflush(stdin);
                    gets(cadastroAluguel[count3].cpf);
                    //Varrer todo o vetor de cadastro de clientes pra comparar o CPF
                    for(cmpaux = 0; cmpaux < count2; cmpaux++) {
                    if(strcmp(cadastroAluguel[count3].cpf, cadastroClientes[cmpaux].cpf)==0) {
                        validacao=1;

                }
                }
                    if (validacao==1){
                        printf("CPF valido");
                        validacao=0;

                    }else {
                        printf("CPF invalido");
                    break;
                    }

                    printf("Digite a placa do carro: ");
                    fflush(stdin);
                    gets(cadastroAluguel[count3].placa);
                    for(cmpaux = 0; cmpaux < count1; cmpaux++) {
                    if(strcmp(cadastroAluguel[count3].placa, carros[cmpaux].placa)==0) {
                        validacao=1;

                }
                }
                    if (validacao==1){
                        printf("Placa valida");
                    validacao=0;
                    }else {
                        printf("Placa invalida");
                    break;
                    }

                    printf("Digite a data do aluguel:\n");
                    printf("Dia: ");
                    scanf("%d", &cadastroAluguel[count3].dia);
                    printf("Mes: ");
                    scanf("%d", &cadastroAluguel[count3].mes);
                    printf("Ano: ");
                    scanf("%d", &cadastroAluguel[count3].ano);

                    printf("Digite o status, ( A ) para aberto e ( F ) para fechado:\n");
                    fflush(stdin);
                    gets(cadastroAluguel[count3].status);

                    count3++;
				}

				break;

				case 2:
				printf("Digite o ID:\n");
				scanf("%d", &id);
				for (i=0; i<count3; i++){
                    if (id==cadastroAluguel[i].identificador){
                        strcpy (cadastroAluguel[i].status, comp);
                    }
				}

				break;

				case 3:
				exit(0);


				default:
				printf("Opção invalida. Tente novamente.\n");
				break;

			}



		break;

		/*Área Impressão de dados*/
		case 4:
		    printf("----------------------------\n");
			printf("MENU DE IMPRESSAO\n");
			printf("----------------------------\n");
			printf("(1)Carros\n");
			printf("(2)Clientes\n");
			printf("(3)Alugueis\n");
			printf("(4)Sair\n\n\n");

			printf("Digite sua opção: ");
			scanf("%d", &impressao);

			switch(impressao) {
				case 1:
				for (i = 0; i < count1; i++)
				{
					printf("Placa: %s", carros[i].placa);
					printf("Modelo: %s", carros[i].modelo);
					printf("Ano: %d", carros[i].ano);
					printf("Disponibilidade: %s", carros[i].disponibilidade);
					printf("Valor do Aluguel: R$ %.2f", carros[i].valorAluguel);
				}
				break;

				case 2:
				for (i = 0; i < count2; i++)
				{
					printf("CPF: %s", cadastroClientes[i].cpf);
					printf("Nome: %s", cadastroClientes[i].nome);
					printf("Endereço: %s", cadastroClientes[i].endereco);
				}
				break;

				case 3:
				for (i = 0; i < count3; i++)
				{
					printf("ID: %d", cadastroAluguel[i].identificador);
					printf("CPF: %s", cadastroAluguel[i].cpf);
					printf("Placa: %s", cadastroAluguel[i].placa);
					printf("Data: %d / %d / %d", cadastroAluguel[i].dia, cadastroAluguel[i].mes, cadastroAluguel[i].ano);
					printf("Status: %s", cadastroAluguel[i].status);
				}
				break;

				case 4:
				exit(0);

				default:
				printf("Opção inválida. Tente novamente.\n");
		   		break;

			}
		break;

		/*Sair do programa*/
		case 5:
		exit(0);


		default:
		printf("Opção inválida. Tente novamente.\n");
		    break;


	}

}

	printf("\n\n");
	system("pause");
	return 0;
}
