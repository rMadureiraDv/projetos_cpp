#include "SFHead.hpp"


short int registroReserva() {
	std::string chkAv;
	system("cls");
	int i;
	std::cout << "DIGITE O NOME DO AVI�O\n>>>";
	std::cin >> chkAv;
	// for para busca
	for (i = 0; i <= 3; i++) {
		if ((chkAv == regAviao[i].nomeAv) && (regAviao[i].getAssentos() != 0)) {
			system("cls");
			std::cout << "DIGITE O NOME DO PASSAGEIRO\n>>>";
			std::cin >> regReserva[iReserva].nomePassageiro;
			regReserva[iReserva].nomeAv = regAviao[i].nomeAv;
			iReserva++;
			regAviao[i].setAssentos(regAviao[i].getAssentos() - 1);
			return 0;
		}
		else if ((chkAv == regAviao[i].nomeAv) && (regAviao[i].getAssentos() == 0)) {
			system("cls");
			std::cout << "AVI�O COM ASSENTOS LOTADOS!!!\n";
			(void)_getch();
			return 1;
		}
	}
	if (chkAv != regAviao[i].nomeAv)
	{
		std::cout << "AVI�O INEXISTENTE\n";
		(void)_getch();
	}
	return 1;
}

short int consultaAviao() {
	system("cls");
	std::string chkAv;
	std::cout << "DIGITE O NOME DO AVI�O\n>>>";
	std::cin >> chkAv;
	for (int i = 0; i <= 3; i++) {
		if ((chkAv != regAviao[i].nomeAv) && (i == 3)) {
			system("cls");
			std::cout << "AVI�O INEXISTENTE!!!\n";
			(void)_getch();
			return 1;
		}
		else if (chkAv == regAviao[i].nomeAv) {
			break;
		}
	}
	for (int i = 0; i <= 19; i++) {
		if (chkAv == regReserva[i].nomeAv) {
			break;
		}
		else if ((chkAv != regReserva[i].nomeAv) && (i == 19))
		{
			system("cls");
			std::cout << "AVI�O SEM RESERVAS!!!";
			(void)_getch();
			return 1;
		}
	}
	system("cls");
	std::cout << "PASSAGEIROS COM A RESERVA PARA O AVI�O: " << chkAv << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	for (int i = 0; i < 19; i++) {
		if (chkAv == regReserva[i].nomeAv) {
			std::cout << i + 1 << "-->";
			std::cout << regReserva[i].nomePassageiro << std::endl;
		}
	}
	(void)_getch();
	return 0;
}

short int consultaPassageiro() {
	std::string chkPas;
	int countRes[4] = {};
	system("cls");
	std::cout << "DIGITE O NOME DO PASSAGEIRO\n>>>";
	std::cin >> chkPas;
	for (int i = 0; i <= 19; i++) {
		if (chkPas != regReserva[i].nomePassageiro && i == 19) {
			system("cls");
			std::cout << "PASSAGEIRO N�O RESERVOU A PASSAGEM\n";
			(void)_getch();
			return 1;
		}
		else if (chkPas == regReserva[i].nomePassageiro) {
			break;
		}
	}
	for (int i = 0; i < 19; i++) {
		if (chkPas == regReserva[i].nomePassageiro) {
			if (regReserva[i].nomeAv == regAviao[0].nomeAv) {
				countRes[0]++;
			}
			else if (regReserva[i].nomeAv == regAviao[1].nomeAv) {
				countRes[1]++;
			}
			else if (regReserva[i].nomeAv == regAviao[2].nomeAv) {
				countRes[2]++;
			}
			else if (regReserva[i].nomeAv == regAviao[3].nomeAv) {
				countRes[3]++;
			}
		}
	}
	std::cout << "RESERVAS FEITAS PELO PASSAGEIRO: " << chkPas << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	for (int i = 0; i <= 3; i++) {
		std::cout << "AVI�O: " << regAviao[i].nomeAv << " RESERVOU: " << countRes[i] << " PASSAGENS" << std::endl;
	}
	(void)_getch();
	return 0;
}
