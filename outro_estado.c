/*
 Integrantes do grupo: 
 	Higor Ferreira Alves Santos
 	Jo�o Vitor Arantes Viana
	Isa�as
	Pedro
	Ruan Carlos					
 */

#include "aed.h"
#include "helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv){

	char *host = argv[0];

	if(argc < 2){
		fprintf(stderr, "Error: you have to pass host parameter\n");
		exit(1);
	}
	
	//Inicializando cliente
    CLIENT *clnt;
    
	#ifndef	DEBUG
		clnt = clnt_create (host, ADD_PROG, ADD_VERS, "udp");
		if (clnt == NULL) {
			clnt_pcreateerror (host);
			exit (1);
		}
	#endif	/* DEBUG */

	request_vac requisicao;

	sprintf(requisicao.estado, "GOIAS");
	sprintf(requisicao.id, "795000000000000");
	requisicao.id_type = ID_TYPE_CARTAO_SUS;
	requisicao.qtt_vacinas = 2;

	request_vac *resposta = requisitar_vacina_1(&requisicao, clnt);

	if(resposta->status == STATUS_OK){
		printf("ESTADO: %s\n", resposta->estado);
		resposta->id_type == ID_TYPE_CARTAO_SUS ?
			printf("CARTAO SUS: %s\n", resposta->id) :
			printf("CPF: %s\n", resposta->id);
		
		printf("VACINAS: %d\n", resposta->qtt_vacinas);
		printf("STATUS: TUDO OK");
	}
	else{
		switch(resposta->status){
			case STATUS_BAD_REQUEST:
				printf("Informacoes nao preenchidas corretamente\n");
				break;
			case STATUS_ID_NAO_ENCONTRADO:
				resposta->id_type == ID_TYPE_CARTAO_SUS ?
					printf("Cartao SUS nao encontrado") :
					printf("CPF nao encontrado");
				break;
			case STATUS_NAO_HA_VACINAS:
				printf("Nao ha vacinas disponiveis\n");
				break;
			
			default:
				printf("Erro desconhecido e aleatorio");
		}
	}
}

