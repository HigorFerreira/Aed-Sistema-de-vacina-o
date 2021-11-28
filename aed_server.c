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

#include <unistd.h>
#include <errno.h>
#include <stdbool.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


//inicio declara��o das variaveis 

long long int qtdDoses = 496936 * 2; //quantidade inicial de doses � igual a popula��o de Roraima * 2 (considerando vacinas de duas doses)
									//quando outro estado contatar nosso servidor e for achado fazer 'qtdDoses--' (remanejamento de vacinas)
									//quando entrarmos em contato com outro servidor e for achado fazer 'qtdDoses++' (remanejamento de vacinas)
									
//Cada cidade possui um base de 1000 contatos para teste, o formato de cada linha da matriz � (cartaoSus, cpf, dose)
//Roraima possui 15 cidades

long long int baseCidade1[1000][3];
long long int baseCidade2[1000][3];
long long int baseCidade3[1000][3];
long long int baseCidade4[1000][3];
long long int baseCidade5[1000][3];
long long int baseCidade6[1000][3];
long long int baseCidade7[1000][3];
long long int baseCidade8[1000][3];
long long int baseCidade9[1000][3];
long long int baseCidade10[1000][3];
long long int baseCidade11[1000][3];
long long int baseCidade12[1000][3];
long long int baseCidade13[1000][3];
long long int baseCidade14[1000][3];
long long int baseCidade15[1000][3];

int numClientes=0;

estado obj;

//fim declara��o das variaveis 

char *
func1_1_svc(estado *argp, struct svc_req *rqstp) //funcao para inicializar valores. Chamada s� uma vez.
{
	static char  result;

	//for para, percorrer as linhas da matriz e  preencher a base de dados com valores genericos [cartao sus = 15 digitos; cpf = 11 digitos; 
//dose = 1 digito (onde 0 = nenhuma dose tomada, 1 = primeira dose tomada, 2 = segunda dose tomada, 3 = primeira dose agendada, 
//4 = segunda dose agendada)]

//declarando contador i
int i = 0;

obj.aux3 = qtdDoses; //setando quantidade de doses disponiveis

for(i=0; i<1000; i++){
	//preenchendo cartao sus [15 digitos, iniciado pelo numero 7. Vamos usar o padrao de inicio 795, para facilitar a implementa��o
	//e entendimento do funcionamento de nosso modelo. 95 ser� usado por ser o DDD de Boa Vista - RR]
	
	//preenchendo CPF [11 digitos, iniciado pelo numero 955. Vamos usar o padrao de inicio 955, para facilitar a implementa��o
	//e entendimento do funcionamento de nosso modelo. 95 ser� usado por ser o DDD de Boa Vista - RR]
	
	//Observacao: tanto o numero do CPF quanto o numero do cartao SUS sao numeros ficticios e nao possuem nenhum sistema de verificacao 
	//quanto a padroes reais, o unico padrao que utilizamos foi a quantidade de digitos, pois o intuito deste trabalho � simular o comportamento
	//de uma aplicacao para agendamento de vacinas.
	
	long long int baseCartaoSus = 795000000000000; //numero utilizado para calcular os numeros do cartao SUS
	long long int baseCPF = 95500000000; //numero utilizado para calcular os CPFs
	
	baseCidade1[i][0]=baseCartaoSus+i; //preenchendo cartao SUS (de 795 0000 0000 0000 a 795 0000 0000 0999)
	baseCidade1[i][1]=baseCPF+i; //preenchendo CPF (de 955 000 000 00 a 955 000 009 99)
	baseCidade1[i][2]=0; //dose inicia zerada para simular que nenhuma dose foi tomada
	
	baseCidade2[i][0]=baseCartaoSus+1000+i; //preenchendo cartao SUS (de 795 0000 0000 1000 a 795 0000 0000 1999)
	baseCidade2[i][1]=baseCPF+i; //preenchendo CPF (de 955 000 010 00 a 955 000 019 99)
	baseCidade2[i][2]=0; //dose inicia zerada para simular que nenhuma dose foi tomada
	
	baseCidade3[i][0]=baseCartaoSus+2000+i; //preenchendo cartao SUS (de 795 0000 0000 2000 a 795 0000 0000 2999)
	baseCidade3[i][1]=baseCPF+2000+i; //preenchendo CPF (de 955 000 020 00 a 955 000 029 99)
	baseCidade3[i][2]=0; //dose inicia zerada para simular que nenhuma dose foi tomada
	
	baseCidade4[i][0]=baseCartaoSus+3000+i; //preenchendo cartao SUS (de 795 0000 0000 3000 a 795 0000 0000 3999)
	baseCidade4[i][1]=baseCPF+3000+i; //preenchendo CPF (de 955 000 030 00 a 955 000 039 99)
	baseCidade4[i][2]=1; //dose inicia com 1 para simular que primeira dose foi tomada
	
	baseCidade5[i][0]=baseCartaoSus+4000+i; //preenchendo cartao SUS (de 795 0000 0000 4000 a 795 0000 0000 4999)
	baseCidade5[i][1]=baseCPF+4000+i; //preenchendo CPF (de 955 000 040 00 a 955 000 049 99)
	baseCidade5[i][2]=1; //dose inicia com 1 para simular que primeira dose foi tomada
	
	baseCidade6[i][0]=baseCartaoSus+5000+i; //preenchendo cartao SUS (de 795 0000 0000 5000 a 795 0000 0000 5999)
	baseCidade6[i][1]=baseCPF+5000+i; //preenchendo CPF (de 955 000 050 00 a 955 000 059 99)
	baseCidade6[i][2]=1; //dose inicia com 1 para simular que primeira dose foi tomada
	
	baseCidade7[i][0]=baseCartaoSus+6000+i; //preenchendo cartao SUS (de 795 0000 0000 6000 a 795 0000 0000 6999)
	baseCidade7[i][1]=baseCPF+6000+i; //preenchendo CPF (de 955 000 060 00 a 955 000 069 99)
	baseCidade7[i][2]=2; //dose inicia com 2 para simular que as duas doses foram tomadas
	
	baseCidade8[i][0]=baseCartaoSus+7000+i; //preenchendo cartao SUS (de 795 0000 0000 7000 a 795 0000 0000 7999)
	baseCidade8[i][1]=baseCPF+7000+i; //preenchendo CPF (de 955 000 070 00 a 955 000 079 99)
	baseCidade8[i][2]=2; //dose inicia com 2 para simular que as duas doses foram tomadas
	
	baseCidade9[i][0]=baseCartaoSus+8000+i; //preenchendo cartao SUS (de 795 0000 0000 8000 a 795 0000 0000 8999)
	baseCidade9[i][1]=baseCPF+8000+i; //preenchendo CPF (de 955 000 080 00 a 955 000 089 99)
	baseCidade9[i][2]=2; //dose inicia com 2 para simular que as duas doses foram tomadas
	
	baseCidade10[i][0]=baseCartaoSus+9000+i; //preenchendo cartao SUS (de 795 0000 0000 9000 a 795 0000 0000 9999)
	baseCidade10[i][1]=baseCPF+9000+i; //preenchendo CPF (de 955 000 090 00 a 955 000 099 99)
	baseCidade10[i][2]=3; //dose inicia com 3 para simular que a primeira dose foi agendada
	
	baseCidade11[i][0]=baseCartaoSus+10000+i; //preenchendo cartao SUS (de 795 0000 0001 0000 a 795 0000 0001 0999)
	baseCidade11[i][1]=baseCPF+10000+i; //preenchendo CPF (de 955 000 100 00 a 955 000 109 99)
	baseCidade11[i][2]=3; //dose inicia com 3 para simular que a primeira dose foi agendada
	
	baseCidade12[i][0]=baseCartaoSus+11000+i; //preenchendo cartao SUS (de 795 0000 0001 1000 a 795 0000 0001 1999)
	baseCidade12[i][1]=baseCPF+11000+i; //preenchendo CPF (de 955 000 110 00 a 955 000 119 99)
	baseCidade12[i][2]=3; //dose inicia com 3 para simular que a primeira dose foi agendada
	
	baseCidade13[i][0]=baseCartaoSus+12000+i; //preenchendo cartao SUS (de 795 0000 0001 2000 a 795 0000 0001 2999)
	baseCidade13[i][1]=baseCPF+12000+i; //preenchendo CPF (de 955 000 120 00 a 955 000 129 99)
	baseCidade13[i][2]=4; //dose inicia com 4 para simular que a segunda dose foi agendada
	
	baseCidade14[i][0]=baseCartaoSus+13000+i; //preenchendo cartao SUS (de 795 0000 0001 3000 a 795 0000 0001 3999)
	baseCidade14[i][1]=baseCPF+13000+i; //preenchendo CPF (de 955 000 130 00 a 955 000 139 99)
	baseCidade14[i][2]=4; //dose inicia com 4 para simular que a segunda dose foi agendada	
}

	return &result;
}

char *
func2_1_svc(estado *argp, struct svc_req *rqstp) //funcao usada para agendar a vacinacao
{
	 char  *result;

	/*
	 * insert server code here
	 */
	 
	//printf("numero: %s\n",argp->auxPalavra);
	int encontrou = -1; //variavel usada para saber se o cartao SUS existe na base
	long long int auxSus;
	auxSus = atoll(argp->auxPalavra); //converter vetor char para long int (converter numero do cartao sus para int)
	//printf("Cartao SUS ou CPF: %lld\n", auxSus);
	
	int tamanho; //variavel para verificar o tamanho do numero digitado
	
	//verificar o tamanho do numero digitado se possuir 15 digitos = cartao sus, se possuir 11 digitos = cpf	
	tamanho = strlen(argp->auxPalavra);
	int i = 0; 
	for(i=0; i<1000; i++){ //for para verificar se cartao sus ou cpf se encontram na base de dados do estado
		
		if(tamanho==11)//cartao digitado � um cpf
		{
			 if(baseCidade1[i][1]==auxSus){//verificar se cartao existe na base
			 	
			 	if(baseCidade1[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade1[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade1[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade1[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade1[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade1[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else //se agendou segunda dose, n�o agendar nada
							 {							 	
							 	encontrou = 4;							
							 }
						 }
					 }
				 }
	 			
	 			break;
		  	 }
			 if(baseCidade2[i][1]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade2[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade2[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade2[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade2[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade2[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade2[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else //se agendou segunda dose, n�o agendar nada
							 {							 	
							 	encontrou = 4;							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade3[i][1]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade3[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade3[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade3[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade3[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade3[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade3[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada						
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade4[i][1]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade4[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade4[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade4[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade4[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade4[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade4[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade5[i][1]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade5[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade5[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade5[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade5[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade5[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade5[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade6[i][1]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade6[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade6[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade6[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade6[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade6[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade6[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade7[i][1]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade7[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade7[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade7[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade7[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade7[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade7[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade8[i][1]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade8[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade8[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade8[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade8[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade8[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade8[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade9[i][1]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade9[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade9[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade9[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade9[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade9[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade9[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade10[i][1]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade10[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade10[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade10[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade10[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade10[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade10[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade11[i][1]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade11[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade11[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade11[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade11[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade11[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade11[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade12[i][1]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade12[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade12[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade12[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade12[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade12[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade12[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade13[i][1]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade13[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade13[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade13[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade13[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade13[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade13[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade14[i][1]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade14[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade14[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade14[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade14[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade14[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade14[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }		 	
		}
		else
		{//cartao digitado � um cartao SUS
			if(baseCidade1[i][0]==auxSus){//verificar se cartao existe na base
			 	
			 	if(baseCidade1[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade1[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade1[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade1[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade1[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade1[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else //se agendou segunda dose, n�o agendar nada
							 {							 	
							 	encontrou = 4;							
							 }
						 }
					 }
				 }
	 			
	 			break;
		  	 }
			 if(baseCidade2[i][0]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade2[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade2[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade2[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade2[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade2[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade2[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else //se agendou segunda dose, n�o agendar nada
							 {							 	
							 	encontrou = 4;							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade3[i][0]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade3[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade3[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade3[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade3[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade3[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade3[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada						
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade4[i][0]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade4[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade4[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade4[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade4[i][2]=4; //segunda dose
			 			encontrou = 1;
			 			printf("aqui1");
					 }
					 else
					 {
					 	if(baseCidade4[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade4[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade5[i][0]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade5[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade5[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade5[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade5[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade5[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade5[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade6[i][0]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade6[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade6[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade6[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade6[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade6[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade6[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade7[i][0]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade7[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade7[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade7[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade7[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade7[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade7[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade8[i][0]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade8[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade8[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade8[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade8[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade8[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade8[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade9[i][0]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade9[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade9[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade9[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade9[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade9[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade9[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade10[i][0]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade10[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade10[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade10[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade10[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade10[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade10[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade11[i][0]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade11[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade11[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade11[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade11[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade11[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade11[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade12[i][0]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade12[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade12[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade12[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade12[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade12[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade12[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade13[i][0]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade13[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade13[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade13[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade13[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade13[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade13[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }
			 if(baseCidade14[i][0]==auxSus){//verificar se cartao existe na base
		 		if(baseCidade14[i][2]==0){//verificar se pessoa tomou a primeira dose da vacina
			 		baseCidade14[i][2]=3; //agendar primeira dose
			 		encontrou = 0;
				 }
				 else
				 {
				 	if(baseCidade14[i][2]==1){//se tomou primeira dose, agendar segunda dose
				 		baseCidade14[i][2]=4; //segunda dose
			 			encontrou = 1;
					 }
					 else
					 {
					 	if(baseCidade14[i][2]==2){//se tomou segunda dose, n�o agendar nada
					 		encontrou = 2;
						 }
						 else{
						 	if(baseCidade14[i][2]==3){//se agendou primeira dose, n�o agendar nada
						 		encontrou = 3;
							 }
							 else
							 {							 	
							 	encontrou = 4;	//se agendou segunda dose, n�o agendar nada							
							 }
						 }
					 }
				 }
	 			
	 			break;
			 }		 	
		}
	 	
	}
	
	char converter[2]; //variavel usada para converter a variavel 'encontrou' de int para char
	
	//converter a variavel 'encontrou' de int para char
	if(encontrou == 0)//nao tomou nenhuma dose da vacina
	{
		sprintf(converter, "%s", "0"); //copiar a variavel da direita para dentro da variavel da esquerda
	} 
	else
	{
		if(encontrou == 1)//tomou uma dose da vacina
		{
			sprintf(converter, "%s", "1"); //copiar a variavel da direita para dentro da variavel da esquerda
		}
		else{
			if(encontrou == 2)//tomou duas doses da vacina
			{
				sprintf(converter, "%s", "2"); //copiar a variavel da direita para dentro da variavel da esquerda
			}
			else{
				if(encontrou == 3) //primeira dose da vacina agendada
				{
					sprintf(converter, "%s", "3"); //copiar a variavel da direita para dentro da variavel da esquerda
				}
				else{
					if(encontrou == 4)//segunda dose da vacina agendada
					{
						sprintf(converter, "%s", "4"); //copiar a variavel da direita para dentro da variavel da esquerda
					}
					else{
						encontrou=9;//nao encontrou cartao sus ou cpf
						sprintf(converter, "%s", "9"); //copiar a variavel da direita para dentro da variavel da esquerda
					}
				}
			}
		}
	}
			//printf("encontrou: %d\n", encontrou);
	if(encontrou >= 0 && encontrou <5)
	{
		sprintf(argp->cidadeChar, "%s", converter); //copiar a variavel da direita para dentro da variavel da esquerda (copiar para variavel da struct)	
		qtdDoses--;//se foi agendado, dimiduir quantidade de doses dispon�veis	
	}
	else{//Comunicacao com servidores de outros estados
		//se nao encontrou o cartao na base do estado, chamar servidor de outro estado e enviar cpf ou cartao SUS
		
		//if() se foi encontrado o cartao em outro servidor;	5 = encontrado em outro servidor	  	
		//sprintf(argp->cidadeChar, "%s", "5"); //copiar a variavel da direita para dentro da variavel da esquerda (copiar para variavel da struct)
		qtdDoses++; //se cartao for de outro estado � necessario fazer o remanejo de doses para o estado que a pessoa ira vacinar			
		//else se nao foi encontrado o cartao em outro servidor
		sprintf(argp->cidadeChar, "%s", "9"); //copiar a variavel da direita para dentro da variavel da esquerda (copiar para variavel da struct)
											 //	9 = n�o encontrado em outro servidor
	}

	result = argp->cidadeChar;//retornando a quantidade de doses tomadas
	//printf("encontrou: %s\n", result);
	obj.aux3 = qtdDoses;//atualizando quantidade de doses disponiveis
	
	return result; //quando retornar numeros de 0 a 4, o cartao foi encontrado no banco de dados.
				  //se retornar 's' foi encontrado o cartao em outro servidor.
				  //se for retornado 'n', o cartao nao foi encontrado em nenhum servidor.
}

int *
vezagendar_1_svc(estado *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code heree
	 */
	 
	//argp->cidadeInt;

	return &result;
}

int *
qtdclienteson_1_svc(estado *argp, struct svc_req *rqstp) //verifica a quantidade de clientes conectados
{
	static int  result;
	if(numClientes>=15){//se numero de clientes for maior ou igual numero de cidades, voltar pro 1 (primeira cidade)
		numClientes = 0;
	}
	numClientes++;
	printf("CIDADE %d ENTROU\n", numClientes);
	obj.aux2 = numClientes;
	
	return &result;
}

int *
func4_1_svc(estado *argp, struct svc_req *rqstp) 
{
	static int  result;

	/*
	 * insert server code heree
	 */
	 
	//argp->cidadeInt;

	return &result;
}

int *
func5_1_svc(estado *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

int *
func6_1_svc(estado *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}

bool_t *
funcbool_1_svc(estado *argp, struct svc_req *rqstp)
{
	static bool_t  result;

	/*
	 * insert server code here
	 */

	return &result;
}

estado *
objeto_1_svc(estado *argp, struct svc_req *rqstp)//funcao usada para retornar um objeto
{
	static estado  result;

	/*
	 * insert server code here
	 */

	return &obj;
}
