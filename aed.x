struct estado{
	char auxPalavra[100];	
	char auxLetra;
	char cidadeChar[50];
	int aux1;
	int aux2;
	int aux3;
	int cidadeInt;
};

struct request_vac {
	char estado[100];
	char id[100];
	char id_type;
	int qtt_vacinas;
	char status;
	int dose;
};

program ADD_PROG{
		version ADD_VERS{
		char func1(estado)=1;
		char func2(estado)=2;
		int vezAgendar(estado)=3;
		int qtdClientesOn(estado)=4;
		int func4(estado)=5;
		int func5(estado)=6;
		int func6(estado)=7;
		bool funcBool(estado)=8;
		estado objeto(estado)=9;

		request_vac requisitar_vacina(request_vac)=10;
		void sumQttVac(int)=20;
	}=1;
}=0x23451111;