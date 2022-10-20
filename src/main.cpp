#include "include/gerarArquivos.hpp"

#include "include/basicTree.hpp"
#include "include/avl.hpp"
#include "include/rb.hpp"

#include "include/calcular500entradas.hpp"
#include "include/calcular5000entradas.hpp"
#include "include/calcular50000entradas.hpp"
#include "include/calcular500000entradas.hpp"

void novosValores() {
	entrada500();
	entrada5000();
	entrada50000();
	entrada500000(); 

	gerar10000();
}

int main() {

	int opcao = -1;
	
	novosValores();

	while(opcao != 0) {
		
		system("clear");

		printf("\n---Informe a opcão que deseja---\n\n");
		printf("0 - Sair do programa\n");
		printf("1 - Calcular tempo com arquivo de 500 entradas\n");
		printf("2 - Calcular tempo com arquivo de 5000 entradas\n");
		printf("3 - Calcular tempo com arquivo de 50000 entradas\n");
		printf("4 - Calcular tempo com arquivo de 500000 entradas\n");
		printf("100 - Gerar novos valores nos arquivos\n");

		cin >> opcao;
		cout << endl;

		if (opcao == 0) {
			cout << "Você saiu do programa" << endl;
			return 0;
		}

		else if (opcao == 1) {
			cout << "Calculando..." << endl;
			calcular500entradas();
		}

		else if (opcao == 2) {
			cout << "Calculando..." << endl;
			calcular5000entradas();
		}

		else if (opcao == 3) {
			cout << "Calculando..." << endl;
			calcular50000entradas();
		}

		else if (opcao == 4) {
			cout << "Calculando..." << endl;
			calcular500000entradas();
		}

		else if (opcao == 100) {
			cout << "Gerando valores..." << endl;
			novosValores();
			cout << "\nValores gerados com sucesso" << endl;
		}

		else {
			cout << "Opção inválida" << endl;
		}

		system("read -p \"\nPressione enter para continuar...\" continue");

	}

}
