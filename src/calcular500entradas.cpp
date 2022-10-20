#include "include/calcular500entradas.hpp"
#include "include/gerarArquivos.hpp"

#include "include/basicTree.hpp"
#include "include/avl.hpp"
#include "include/rb.hpp"

void calcular500entradas() {

	string linha;
	double aux;

	TreeBin *raizBin = CreateTreeBin();
	TreeAVL *raizAVL = CreateTreeAVL();
	TreeRB *raizRB;

	inicializaTreeRB(&raizRB);

	TreeBin *auxBin = CreateTreeBin();
	TreeAVL *auxAVL = CreateTreeAVL();
	TreeRB *auxRB = CreateTreeRB();

	map<double, int> mapa;
	unordered_map<double, int> mapaNO;
	vector<double> vetor;

	Record r;

	cout << "\n---500 ENTRADAS---" << endl;
	cout << "\nTempos de Inserção nas estruturas: " << endl;

	chrono::steady_clock::time_point comecoBin = chrono::steady_clock::now();

	ifstream arquivo500um(PATH "entrada500.txt");

	if (arquivo500um.is_open()) {
		while (getline(arquivo500um, linha)) {
			aux = stof(linha);
			r.key = aux;
			r.value = 1;
			insertTree(&raizBin, r);
		}
	}

	arquivo500um.close();

	chrono::steady_clock::time_point fimBin = chrono::steady_clock::now();
	printf("\nÁrvore Binária: %ld µs\n", chrono::duration_cast<chrono::microseconds>(fimBin - comecoBin).count());

	chrono::steady_clock::time_point comecoAVL = chrono::steady_clock::now();

	ifstream arquivo500dois(PATH "entrada500.txt");

	if (arquivo500dois.is_open()) {
		while (getline(arquivo500dois, linha)) {
			aux = stof(linha);
			r.key = aux;
			r.value = 1;
			insertTree2(&raizAVL, r);
		}
	}

	arquivo500dois.close();

	chrono::steady_clock::time_point fimAVL = chrono::steady_clock::now();
	printf("Árvore AVL: %ld µs\n", chrono::duration_cast<chrono::microseconds>(fimAVL - comecoAVL).count());

	chrono::steady_clock::time_point comecoRB = chrono::steady_clock::now();

	ifstream arquivo500tres(PATH "entrada500.txt");

	if (arquivo500tres.is_open()) {
		while (getline(arquivo500tres, linha)) {
			aux = stof(linha);
			r.key = aux;
			r.value = 1;
			insertTree3(&raizRB, &raizRB, &raizRB, r);
		}
	}

	arquivo500tres.close();

	chrono::steady_clock::time_point fimRB = chrono::steady_clock::now();
	printf("Árvore RB: %ld µs\n", chrono::duration_cast<chrono::microseconds>(fimRB - comecoRB).count());

	chrono::steady_clock::time_point comecoVetor = chrono::steady_clock::now();

	ifstream arquivo500seis(PATH "entrada500.txt");

	if (arquivo500seis.is_open()) {
		while (getline(arquivo500seis, linha)) {
			aux = stof(linha);
			r.key = aux;
			r.value = 1;
			vetor.push_back(aux);
		}
	}

	arquivo500seis.close();

	chrono::steady_clock::time_point fimVetor = chrono::steady_clock::now();
	printf("Vector: %ld µs\n", chrono::duration_cast<chrono::microseconds>(fimVetor - comecoVetor).count());

	chrono::steady_clock::time_point comecoMapa = chrono::steady_clock::now();

	ifstream arquivo500quatro(PATH "entrada500.txt");

	if (arquivo500quatro.is_open()) {
		while (getline(arquivo500quatro, linha)) {
			aux = stof(linha);
			r.key = aux;
			r.value = 1;
			mapa.insert({aux, 0});
		}
	}

	arquivo500quatro.close();

	chrono::steady_clock::time_point fimMapa = chrono::steady_clock::now();
	printf("Map: %ld µs\n", chrono::duration_cast<chrono::microseconds>(fimMapa - comecoMapa).count());



	chrono::steady_clock::time_point comecoMapaNO = chrono::steady_clock::now();

	ifstream arquivo500cinco(PATH "entrada500.txt");

	if (arquivo500cinco.is_open()) {
		while (getline(arquivo500cinco, linha)) {
			aux = stof(linha);
			r.key = aux;
			r.value = 1;
			mapaNO.insert({aux, 0});
		}
	}

	arquivo500cinco.close();

	chrono::steady_clock::time_point fimMapaNO = chrono::steady_clock::now();
	printf("Unordered Map: %ld µs\n", chrono::duration_cast<chrono::microseconds>(fimMapaNO - comecoMapaNO).count());

	// ifstream arquivo500cinco1(PATH "entrada500.txt");

	// unordered_map <double, int>::iterator k;

	// if (arquivo500cinco1.is_open()) {
	// 	while (getline(arquivo500cinco1, linha)) {
	// 		aux = stof(linha);
	// 		cout << aux << endl;
	// 	}
	// }

	// cout << "------------------\n";

	// for(k = mapaNO.begin(); k != mapaNO.end(); ++k) {
	// 	cout << k->first << endl;
	// }

	// arquivo500cinco1.close();



	double aux2 = 0;
	int i;

	map<double, int>::iterator t;
	unordered_map<double, int>::iterator tNO;

	int contBin = 0, contAVL = 0, contRB = 0;

	treeSizeBin(raizBin, &contBin);
	treeSizeAvl(raizAVL, &contAVL);
	treeSizeRB(raizRB, &contRB);

	cout << "\nTamanho da estrutura após Inserção: " << endl;

	cout << "\nÁrvore Binária: " << contBin << " palavras" << endl;
	cout << "Árvore AVL: " << contAVL << " palavras" << endl;
	cout << "Árvore RB: " << contRB << " palavras" << endl;
	cout << "Vector: " << vetor.size() << " palavras" << endl;
	cout << "Map: " << mapa.size() << " palavras" << endl;
	cout << "Unordered Map: " << mapaNO.size() << " palavras" << endl;

	cout << "\nTempos de Buscas: " << endl;

	chrono::steady_clock::time_point comecoABProcura = chrono::steady_clock::now();

	ifstream arquivo10000ABProcura(PATH "gerar10000.txt");

	if (arquivo10000ABProcura.is_open()) {
		while (getline(arquivo10000ABProcura, linha)) {
			aux2 = stof(linha);
			r.key = aux2;
			pesquisaBin(&raizBin, &auxBin, r);
		}
	}

	arquivo10000ABProcura.close();

	chrono::steady_clock::time_point fimABProcura = chrono::steady_clock::now();
	printf("\nÁrvore Binária: %ld ms\n", chrono::duration_cast<chrono::milliseconds>(fimABProcura - comecoABProcura).count());

	chrono::steady_clock::time_point comecoAVLProcura = chrono::steady_clock::now();

	ifstream arquivo10000AVLProcura(PATH "gerar10000.txt");

	if (arquivo10000AVLProcura.is_open()) {
		while (getline(arquivo10000AVLProcura, linha)) {
			aux2 = stof(linha);
			r.key = aux2;
			pesquisaAVL(&raizAVL, &auxAVL, r);
		}
	}

	arquivo10000AVLProcura.close();

	chrono::steady_clock::time_point fimAVLProcura = chrono::steady_clock::now();
	printf("Árvore AVL: %ld ms\n", chrono::duration_cast<chrono::milliseconds>(fimAVLProcura - comecoAVLProcura).count());

	chrono::steady_clock::time_point comecoRBProcura = chrono::steady_clock::now();

	ifstream arquivo10000RBProcura(PATH "gerar10000.txt");

	if (arquivo10000RBProcura.is_open()) {
		while (getline(arquivo10000RBProcura, linha)) {
			aux2 = stof(linha);
			r.key = aux2;
			pesquisaRB(&raizRB, &auxRB, r);
		}
	}

	arquivo10000RBProcura.close();

	chrono::steady_clock::time_point fimRBProcura = chrono::steady_clock::now();
	printf("Árvore RB: %ld ms\n", chrono::duration_cast<chrono::milliseconds>(fimRBProcura - comecoRBProcura).count());



	chrono::steady_clock::time_point comecoVetorProcura = chrono::steady_clock::now();

	ifstream arquivo10000vectorProcura(PATH "gerar10000.txt");
	sort(vetor.begin(), vetor.end());


	if (arquivo10000vectorProcura.is_open()) {
		while (getline(arquivo10000vectorProcura, linha)) {
			aux2 = stof(linha);
			//for (auto k = vetor.begin(); k != vetor.end(); ++k) {
			//	if (aux2 == *k) {}
			//}
			if (binary_search(vetor.begin(), vetor.end(), aux2)) {

			}
		}
	}

	arquivo10000vectorProcura.close();

	chrono::steady_clock::time_point fimVetorProcura = chrono::steady_clock::now();
	printf("Vector: %ld ms\n", chrono::duration_cast<chrono::milliseconds>(fimVetorProcura - comecoVetorProcura).count());



	chrono::steady_clock::time_point comecoMapaProcura = chrono::steady_clock::now();

	ifstream arquivo10000mapaProcura(PATH "gerar10000.txt");

	if (arquivo10000mapaProcura.is_open()) {
		map<double, int>::iterator i;
		while (getline(arquivo10000mapaProcura, linha)) {
			aux2 = stof(linha);
			i = mapa.find(aux2);
			if (i != mapa.end()){}
		}
	}

	arquivo10000mapaProcura.close();

	chrono::steady_clock::time_point fimMapaProcura = chrono::steady_clock::now();
	printf("Map: %ld ms\n", chrono::duration_cast<chrono::milliseconds>(fimMapaProcura - comecoMapaProcura).count());




	chrono::steady_clock::time_point comecoMapaNOProcura = chrono::steady_clock::now();

	ifstream arquivo10000mapaNOProcura(PATH "gerar10000.txt");

	if (arquivo10000mapaNOProcura.is_open()) {
		unordered_map<double, int>::iterator j;
		while (getline(arquivo10000mapaNOProcura, linha)) {
			aux2 = stof(linha);
			j = mapaNO.find(aux2);
		}
	}

	arquivo10000mapaNOProcura.close();

	chrono::steady_clock::time_point fimMapaNOProcura = chrono::steady_clock::now();
	printf("Unordered Map: %ld ms\n", chrono::duration_cast<chrono::milliseconds>(fimMapaNOProcura - comecoMapaNOProcura).count());




	cout << "\nTempos de Remoção nas estruturas: " << endl;

	chrono::steady_clock::time_point comecoBinRemocao = chrono::steady_clock::now();

	ifstream arquivo10000bin(PATH "gerar10000.txt");

	if (arquivo10000bin.is_open()) {
		while (getline(arquivo10000bin, linha)) {
			aux2 = stof(linha);
			i = 0;
			r.key = aux2;
			removeTree(&raizBin, r);
		}
	}

	arquivo10000bin.close();

	chrono::steady_clock::time_point fimBinRemocao = chrono::steady_clock::now();
	printf("\nÁrvore Binária: %ld ms\n", chrono::duration_cast<chrono::milliseconds>(fimBinRemocao - comecoBinRemocao).count());

	chrono::steady_clock::time_point comecoAVLRemocao = chrono::steady_clock::now();

	ifstream arquivo10000avl(PATH "gerar10000.txt");

	if (arquivo10000avl.is_open()) {
		while (getline(arquivo10000avl, linha)) {
			aux2 = stof(linha);
			i = 0;
			r.key = aux2;
			removeTree2(&raizAVL, &raizAVL, r);
		}
	}

	arquivo10000avl.close();

	chrono::steady_clock::time_point fimAVLRemocao = chrono::steady_clock::now();
	printf("Árvore AVL: %ld ms\n", chrono::duration_cast<chrono::milliseconds>(fimAVLRemocao - comecoAVLRemocao).count());

	chrono::steady_clock::time_point comecoRBRemocao = chrono::steady_clock::now();

	ifstream arquivo10000rb(PATH "gerar10000.txt");

	if (arquivo10000rb.is_open()) {
		while (getline(arquivo10000rb, linha)) {
			aux2 = stof(linha);
			i = 0;
			r.key = aux2;
			search_delete(&raizRB, raizRB, r);
		}
	}

	arquivo10000rb.close();

	chrono::steady_clock::time_point fimRBRemocao = chrono::steady_clock::now();
	printf("Árvore RB: %ld ms\n", chrono::duration_cast<chrono::milliseconds>(fimRBRemocao - comecoRBRemocao).count());
	
	chrono::steady_clock::time_point comecoVetorRemocao = chrono::steady_clock::now();

	ifstream arquivo10000vector(PATH "gerar10000.txt");

	if (arquivo10000vector.is_open()) {
		while (getline(arquivo10000vector, linha)) {
			aux2 = stof(linha);
			if (binary_search(vetor.begin(), vetor.end(), aux2)) {
				for (unsigned k = 0; k < vetor.size(); ++k) {
					if (aux2 == vetor[k]) {
						vetor.erase(vetor.begin() + k, vetor.begin() + k + 1);
					}
				}
			}
		}
	}

	arquivo10000vector.close();

	chrono::steady_clock::time_point fimVetorRemocao = chrono::steady_clock::now();
	printf("Vector: %ld ms\n", chrono::duration_cast<chrono::milliseconds>(fimVetorRemocao - comecoVetorRemocao).count());

	chrono::steady_clock::time_point comecoMapaRemocao = chrono::steady_clock::now();

	ifstream arquivo10000mapa(PATH "gerar10000.txt");

	if (arquivo10000mapa.is_open()) {
		while (getline(arquivo10000mapa, linha)) {
			aux2 = stof(linha);
			i = 0;
			// for(auto k = vetor.begin(); k != vetor.end(); ++k) {
			t = mapa.find(aux2);
			if (t != mapa.end()) {
				mapa.erase(t);
			}
			//}
		}
	}

	arquivo10000mapa.close();

	chrono::steady_clock::time_point fimMapaRemocao = chrono::steady_clock::now();
	printf("Map: %ld ms\n", chrono::duration_cast<chrono::milliseconds>(fimMapaRemocao - comecoMapaRemocao).count());

	chrono::steady_clock::time_point comecoMapaNORemocao = chrono::steady_clock::now();

	ifstream arquivo10000mapaNO(PATH "gerar10000.txt");

	if (arquivo10000mapaNO.is_open()) {
		while (getline(arquivo10000mapaNO, linha)) {
			aux2 = stof(linha);
			i = 0;
			// for(auto k = vetor.begin(); k != vetor.end(); ++k) {
			tNO = mapaNO.find(aux2);
			if (tNO != mapaNO.end()) {
				mapaNO.erase(tNO);
			}
			//}
		}
	}

	arquivo10000mapaNO.close();

	chrono::steady_clock::time_point fimMapaNORemocao = chrono::steady_clock::now();
	printf("Unordered Map: %ld ms\n", chrono::duration_cast<chrono::milliseconds>(fimMapaNORemocao - comecoMapaNORemocao).count());

	contBin = 0, contAVL = 0, contRB = 0;

	treeSizeBin(raizBin, &contBin);
	treeSizeAvl(raizAVL, &contAVL);
	treeSizeRB(raizRB, &contRB);

	cout << "\nTamanho da estrutura após Remoção: " << endl;

	cout << "\nÁrvore Binária: " << contBin << " palavras" << endl;
	cout << "Árvore AVL: " << contAVL << " palavras" << endl;
	cout << "Árvore RB: " << contRB << " palavras" << endl;
	cout << "Vector: " << vetor.size() << " palavras" << endl;
	cout << "Map: " << mapa.size() << " palavras" << endl;
	cout << "Unordered Map: " << mapaNO.size() << " palavras" << endl;
}
