#include "SFHead.hpp"

int iReserva = 0;
aviao regAviao[4];
reserva regReserva[20];

int main() {
	setlocale(LC_ALL, "portuguese");//do clocale
	bool rep = true;
	int opt = 0,assento;
	while (rep == true) {
		system("cls");
		std::cout << "SWEET FLIGHT RESERVAS\n";
		std::cout << "-------------------------\n";
		std::cout << "[1]-REGISTRAR AVIÃO\n";
		std::cout << "[2]-REGISTRAR ASSENTOS\n";
		std::cout << "[3]-RESERVAR ASSENTO\n";
		std::cout << "[4]-CONSULTAR AVIÃO\n";
		std::cout << "[5]-CONSULTAR PASSAGEIRO\n";
		std::cout << "[6]-FECHAR PROGRAMA\n";
		std::cout << ">>>";
		std::cin >> opt;
		switch (opt)
		{
		case 1:
			for (int i = 0; i <= 3; i++) {
				system("cls");
				std::cout << "DIGITE O NOME DO " << i + 1 << " AVIÃO\n>>>";
				std::cin >> regAviao[i].nomeAv;
			}
			break;
		case 2:
			for (int i = 0; i <= 3; i++) {
				system("cls");
				std::cout << "DIGITE A QUANTIDADE DE ASSENTOS DO " << i + 1 << " AVIÃO\n>>>";
				std::cin >> assento;
				regAviao[i].setAssentos(assento);
			}
			break;
		case 3:
			if (iReserva != 20) {
				registroReserva();
			}
			else{
				system("cls");
				std::cout << "RESERVAS ESGOTADAS!!!\n";
				(void)_getch();
			}
			break;
		case 4:
			consultaAviao();
			break;
		case 5:
			consultaPassageiro();
			break;
		case 6:
			rep = false;
			break;
		default:
			system("cls");
			std::cout << "OPÇÃO INVÁLIDA,TENTE NOVAMENTE\n";
			(void)_getch();
			break;
		}
	}
}

