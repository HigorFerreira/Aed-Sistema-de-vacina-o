/*
 Integrantes do grupo: 
 	Higor Ferreira Alves Santos
 	Jo�o Vitor Arantes Viana
	Isa�as
	Pedro
	Ruan Carlos					
 */

#include "aed.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
void
add_prog_1(char *host)
{
	CLIENT *clnt;
	char  *result_1;
	estado  func1_1_arg;
	char  *result_2;
	estado  func2_1_arg;
	int  *result_3;
	estado  vezagendar_1_arg;
	int  *result_4;
	estado  qtdclienteson_1_arg;
	int  *result_5;
	estado  func4_1_arg;
	int  *result_6;
	estado  func5_1_arg;
	int  *result_7;
	estado  func6_1_arg;
	bool_t  *result_8;
	estado  funcbool_1_arg;
	estado  *result_9;
	estado  objeto_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, ADD_PROG, ADD_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
/*
	result_1 = func1_1(&func1_1_arg, clnt);
	if (result_1 == (char *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = func2_1(&func2_1_arg, clnt);
	if (result_2 == (char *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_3 = vezagendar_1(&vezagendar_1_arg, clnt);
	if (result_3 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_4 = qtdclienteson_1(&qtdclienteson_1_arg, clnt);
	if (result_4 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_5 = func4_1(&func4_1_arg, clnt);
	if (result_5 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_6 = func5_1(&func5_1_arg, clnt);
	if (result_6 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_7 = func6_1(&func6_1_arg, clnt);
	if (result_7 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_8 = funcbool_1(&funcbool_1_arg, clnt);
	if (result_8 == (bool_t *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_9 = objeto_1(&objeto_1_arg, clnt);
	if (result_9 == (estado *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 
}
*/

int main (int argc, char *argv[])
{
	char *host;
	host="localhost";
	
	//Inicializando cliente
    CLIENT *clnt;
    
	#ifndef	DEBUG
		clnt = clnt_create (host, ADD_PROG, ADD_VERS, "udp");
		if (clnt == NULL) {
			clnt_pcreateerror (host);
			exit (1);
		}
	#endif	/* DEBUG */

	//inicio declaracao de variaveis necessarias
	
	int  *result_3;
	estado  vezagendar_1_arg;
	
	
	char  *result_2;
	estado  func2_1_arg;
	
	
	char  *result_1;
	estado  func1_1_arg;
	
	int  * result_4;
	estado  qtdclienteson_1_arg;
	
	estado  *result_9;
	estado  objeto_1_arg;
	
	int auxQtdClientes = 0;	
	int auxQtdDoses = 0;	
	//fim declaracao de variaveis necessarias
	
	//adicionar clientes/cidades ao servidor	
	result_4 = qtdclienteson_1(&qtdclienteson_1_arg, clnt);
	if (result_4 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	
	//chamando objeto de 'estado'
	result_9 = objeto_1(&objeto_1_arg, clnt);
	if (result_9 == (estado *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	auxQtdClientes = result_9->aux2; //verificando quantos clientes conectados
	
	//Inicializacao das listas de dados. CHAMAR SOMENTE QUANDO O PRIMEIRO CLIENTE ENTRAR.
	if(auxQtdClientes==1){
		result_1 = func1_1(&func1_1_arg, clnt);
		if (result_1 == (char *) NULL) {
			clnt_perror (clnt, "call failed");
		}
	}	
	
	result_9 = objeto_1(&objeto_1_arg, clnt);
	if (result_9 == (estado *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	auxQtdDoses = result_9->aux3;//verificando quantidade de doses dispon�veis no estado	

	switch(auxQtdClientes){//exibir a cidade que est� agendando a vacina
		
		case 1:
		printf("*****BEM VINDO AO AGENDAMENTO DE VACINAS DA CIDADE DE BOA VISTA*****\n");		
		printf("Doses disponiveis no estado: %d\n",auxQtdDoses);		
		break;
		
		case 2:
		printf("*****BEM VINDO AO AGENDAMENTO DE VACINAS DA CIDADE DE RORAINOPOLIS*****\n");
		printf("Doses disponiveis no estado: %d\n",auxQtdDoses);
		break;
		
		case 3:
		printf("*****BEM VINDO AO AGENDAMENTO DE VACINAS DA CIDADE DE CARACARAI*****\n");
		printf("Doses disponiveis no estado: %d\n",auxQtdDoses);
		break;
		
		case 4:
		printf("*****BEM VINDO AO AGENDAMENTO DE VACINAS DA CIDADE DE PACARAIMA*****\n");
		printf("Doses disponiveis no estado: %d\n",auxQtdDoses);
		break;
		
		case 5:
		printf("*****BEM VINDO AO AGENDAMENTO DE VACINAS DA CIDADE DE CANTA*****\n");
		printf("Doses disponiveis no estado: %d\n",auxQtdDoses);
		break;
		
		case 6:
		printf("*****BEM VINDO AO AGENDAMENTO DE VACINAS DA CIDADE DE MUCAJAI*****\n");
		printf("Doses disponiveis no estado: %d\n",auxQtdDoses);
		break;
		
		case 7:
		printf("*****BEM VINDO AO AGENDAMENTO DE VACINAS DA CIDADE DE ALTO ALEGRE*****\n");
		printf("Doses disponiveis no estado: %d\n",auxQtdDoses);
		break;
		
		case 8:
		printf("*****BEM VINDO AO AGENDAMENTO DE VACINAS DA CIDADE DE AMAJARI*****\n");
		printf("Doses disponiveis no estado: %d\n",auxQtdDoses);
		break;
		
		case 9:
		printf("*****BEM VINDO AO AGENDAMENTO DE VACINAS DA CIDADE DE BONFIM*****\n");
		printf("Doses disponiveis no estado: %d\n",auxQtdDoses);
		break;
		
		case 10:
		printf("*****BEM VINDO AO AGENDAMENTO DE VACINAS DA CIDADE DE IRACEMA*****\n");
		printf("Doses disponiveis no estado: %d\n",auxQtdDoses);
		break;
		
		case 11:
		printf("*****BEM VINDO AO AGENDAMENTO DE VACINAS DA CIDADE DE NORMANDIA*****\n");
		printf("Doses disponiveis no estado: %d\n",auxQtdDoses);
		break;
		
		case 12:
		printf("*****BEM VINDO AO AGENDAMENTO DE VACINAS DA CIDADE DE UIRAMUTA*****\n");
		printf("Doses disponiveis no estado: %d\n",auxQtdDoses);
		break;
		
		case 13:
		printf("*****BEM VINDO AO AGENDAMENTO DE VACINAS DA CIDADE DE CAROEBE*****\n");
		printf("Doses disponiveis no estado: %d\n",auxQtdDoses);
		break;
		
		case 14:
		printf("*****BEM VINDO AO AGENDAMENTO DE VACINAS DA CIDADE DE SAO JOAO DA BALIZA*****\n");
		printf("Doses disponiveis no estado: %d\n",auxQtdDoses);
		break;
		
		case 15:
		printf("*****BEM VINDO AO AGENDAMENTO DE VACINAS DA CIDADE DE SAO LUIZ*****\n");
		printf("Doses disponiveis no estado: %d\n",auxQtdDoses);
		break;
		
	}
		
	int controle = 1; //variavel utilizada para controlar quando sair do while, ou seja, se deseja agendar outra vacina��o
	while(controle == 1){
		char numCartao[15];
		printf("Insira o cartao sus ou o cpf (SOMENTE NUMEROS): ");
		scanf("%s%*c", numCartao); //%*c para nao ler caracter vazio	
		
		int tamanhoNum; //variavel para verificar o tamanho do numero digitado
	
		//verificar o tamanho do numero digitado se possuir 15 digitos = cartao sus, se possuir 11 digitos = cpf	
		tamanhoNum = strlen(numCartao);	
			
		while(tamanhoNum!=11 && tamanhoNum!=15){//enquanto numero nao for do tamanho do cpf ou do cartao SUS, ficar pedindo para inserir um cartao
			printf("ENTRADA INVALIDA. Insira o cartao sus ou o cpf (SOMENTE NUMEROS): ");
			scanf("%s%*c", numCartao); //%*c para nao ler caracter vazio
			
			//verificar o tamanho do numero digitado se possuir 15 digitos = cartao sus, se possuir 11 digitos = cpf	
			tamanhoNum = strlen(numCartao);	
		}
		
    	sprintf(func2_1_arg.auxPalavra, "%s", numCartao); //copiar a variavel da direita para dentro da variavel da esquerda (copiar para variavel da struct)
		result_2 = func2_1(&func2_1_arg, clnt);
		if (result_2 == (char *) NULL) {
		clnt_perror (clnt, "call failed");
		}
		else{
			//printf("numero: %s\n",func2_1_arg.cidadeChar);
			//printf("resultado: %s\n",result_2);
			
			long long int auxResultado;
			auxResultado = atoll(result_2); //converter vetor char para long int (converter numero do cartao sus para int)
			//printf("Result: %s.\n", result_2);
			//verificar se ja foi vacinado
			if(auxResultado==5){//se cartao pertence a outro estado
				printf("Vacinacao agendada com sucesso!!! Compareca ao local de vacinacao no dia 10/01/2022.\n");	
			}
			else{
				if(auxResultado==1){//se tomou uma dose da vacina
					printf("Segunda dose agendada com sucesso!!! Compareca ao local de vacinacao no dia 10/01/2022.\n");
				}
				else{
					if(auxResultado==2){//se j� tomou as duas doses da vacina
						printf("ERRO NO AGENDAMENTO!!! As duas doses da vacina ja foram tomadas.\n");
					}
					else{
						if(auxResultado==3){//se j� est� agendado
							printf("ERRO NO AGENDAMENTO!!! Voce ja agendou sua primeira dose.\n");
						}
						else{
							if(auxResultado==4){//se j� est� agendado
								printf("ERRO NO AGENDAMENTO!!! Voce ja agendou sua segunda dose.\n");
							}
							else{
								if(auxResultado==9){//se nao tomou nenhuma dose
									printf("ERRO NO AGENDAMENTO!!! Nao foi encontrado seu cartao no banco de dados.\n");	
								}
								else{
									if(auxResultado==0){//se nao tomou nenhuma dose
										printf("Primeira dose agendada com sucesso!!! Compareca ao local de vacinacao no dia 10/01/2022.\n");	
									}
									else{
										printf("ERRO NO AGENDAMENTO!!! Nao foi encontrado seu cartao no banco de dados.\n");
									}
									
								}
									
							}
						}
					}
				}
			}
		}
		
		
		printf("Deseja fazer outro agendamento? (Digite 1 se sim ou 0 se nao)");
		scanf("%d%*c", &controle); //%*c para nao ler caracter vazio
		
		while(controle!=0 && controle!=1){
			printf("OPCAO INVALIDA. Deseja fazer outro agendamento? (Digite 1 se sim ou 0 se nao)");
			scanf("%d%*c", &controle); //%*c para nao ler caracter vazio
		}		
	}
	
	printf("AGENDAMENTO ENCERRADO.\n");
exit (0);
}
