#include <iostream>
#include <cstdlib>//para comandos do CMD (terminal)
#include <clocale> //colocar caracteres do portugu�s
#include <conio.h>//para usar o _getch() , por que falaram q system("pause") � considerado m� pr�tica :/

extern int iReserva;//indice para correr no registro na reserva

//estao com modificador short pra reduzir o consumo de mem�ria, cada retorno � 2 bytes :)
short int registroReserva();
short int consultaAviao();
short int consultaPassageiro();

class aviao {
public:
	std::string nomeAv;
	void setAssentos(int cadeiras);
	int getAssentos();
private:
	int assentos = 0;
protected:
};

class reserva :public aviao {
public:
	std::string nomePassageiro;
protected:
private:
};

extern aviao regAviao[];
extern reserva regReserva[];
