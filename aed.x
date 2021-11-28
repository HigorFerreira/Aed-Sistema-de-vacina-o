struct estado{
	char auxPalavra[100];	
	char auxLetra;
	char cidadeChar[50];
	int aux1;
	int aux2;
	int aux3;
	int cidadeInt;
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
	}=1;
}=0x23451111;