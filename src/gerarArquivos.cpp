#include "include/gerarArquivos.hpp"

void entrada500() {

    unordered_map <string, int> mapa;

    FILE *file;
	char array[100];
	double n = 0;

    file = fopen("arquivos/entrada500.txt", "w");

    srand(time(NULL));

    double aux;

    for (int i = 0; i < 500; i++) {
        n = 1 + (double)rand() / (double)RAND_MAX *1000;
		sprintf(array, "%.6lf", n);
		strcat(array, "\n");
        // mapa.insert({array, 0});
		fputs(array, file);
    }

    unordered_map <string, int>::iterator i;

    for(i = mapa.begin(); i != mapa.end(); ++i) {
		//MyFile << i->first << endl;
    }

    fclose(file);

}



void entrada5000() {

    unordered_map <double, int> mapa;

    FILE *file;
	char array[100];
	double n = 0;

    file = fopen("arquivos/entrada5000.txt", "w");

    srand(time(NULL));

    double aux;

    for(int j = 0; j < 5000; j++) {
        n = 1 + (double)rand() / (double)RAND_MAX *1000;
		sprintf(array, "%.6lf", n);
		strcat(array, "\n");
		fputs(array, file);
    }

    unordered_map <double, int>::iterator i;

    for(i = mapa.begin(); i != mapa.end(); ++i) {
		//MyFile << i->first << endl;
    }

    fclose(file);


}

void entrada50000() {

    unordered_map <double, int> mapa;

    FILE *file;
	char array[100];
	double n = 0;

    file = fopen("arquivos/entrada50000.txt", "w");

    srand(time(NULL));

    double aux;

    for(int j = 0; j < 50000; j++) {
        n = 1 + (double)rand() / (double)RAND_MAX *1000;
		sprintf(array, "%.6lf", n);
		strcat(array, "\n");
		fputs(array, file);
    }

    unordered_map <double, int>::iterator i;

    for(i = mapa.begin(); i != mapa.end(); ++i) {
		//MyFile << i->first << endl;
    }

    fclose(file);


}

void entrada500000() {

    unordered_map <double, int> mapa;

    FILE *file;
	char array[100];
	double n = 0;

    file = fopen("arquivos/entrada500000.txt", "w");

    srand(time(NULL));

    double aux;

    for(int j = 0; j < 500000; j++) {
        n = 1 + (double)rand() / (double)RAND_MAX *1000;
		sprintf(array, "%.6lf", n);
		strcat(array, "\n");
		fputs(array, file);
    }

    unordered_map <double, int>::iterator i;

    for(i = mapa.begin(); i != mapa.end(); ++i) {
		//MyFile << i->first << endl;
    }

    fclose(file);


}

void gerar10000() {

    FILE *file;
	char array[100];
	double n = 0;

    file = fopen("arquivos/gerar10000.txt", "w");

    srand(time(NULL));

    double aux;

    // for(int j = 0; j < 10000; j++) {
    //     n = 1 + (double)rand() / (double)RAND_MAX *1000;
	// 	sprintf(array, "%.6lf", n);
	// 	strcat(array, "\n");
	// 	fputs(array, file);
    // }


    // return;

    unordered_map <double, int> mapa;

    string linha;
    int cont = 0;

    ofstream Arquivo("arquivos/gerar10000.txt");

    //----------------------------------------------

    ifstream Leitura1;
    Leitura1.open("arquivos/entrada500.txt");

    if(Leitura1.is_open()) {
        while(getline(Leitura1, linha)) {
            if(cont == 250) {
                break;
            } else {
                mapa.insert({stof(linha), 0});
                //Arquivo << linha << endl;
                cont++;
            }
        }
    }

    Leitura1.close();

    //----------------------------------------------

    cont = 0;

    ifstream Leitura2;
    Leitura2.open("arquivos/entrada5000.txt");

    if(Leitura2.is_open()) {
        while(getline(Leitura2, linha)) {
            if(cont == 1250) {
                break;
            } else {
                mapa.insert({stof(linha), 0});
                //Arquivo << linha << endl;
                cont++;
            }
        }
    }

    Leitura2.close();

    //----------------------------------------------

    cont = 0;

    ifstream Leitura3;
    Leitura3.open("arquivos/entrada50000.txt");

    if(Leitura3.is_open()) {
        while(getline(Leitura3, linha)) {
            if(cont == 2500) {
                break;
            } else {
                mapa.insert({stof(linha), 0});
                //Arquivo << linha << endl;
                cont++;
            }
        }
    }

    Leitura3.close();

    //----------------------------------------------

    cont = 0;

    ifstream Leitura4;
    Leitura4.open("arquivos/entrada500000.txt");

    if(Leitura4.is_open()) {
        while(getline(Leitura4, linha)) {
            if(cont == 5000) {
                break;
            } else {
                mapa.insert({stof(linha), 0});
                //Arquivo << linha << endl;
                cont++;
            }
        }
    }

    Leitura4.close();

    //----------------------------------------------

    // srand((unsigned int)time(NULL));

    // double a = 100.0f;
    // double aux = 0;

    // while(mapa.size() < 10000) {
    //     aux = ((double)rand()/(double)(RAND_MAX)) * a;
    //     mapa.insert({aux, 0});
    // }

    unordered_map <double, int>::iterator i;

    for(i = mapa.begin(); i != mapa.end(); ++i) {
	 	sprintf(array, "%.6lf", i->first);
	 	strcat(array, "\n");
	 	fputs(array, file);
    }

    Arquivo.close();

}

// void deixarAleatorio() {

//     vector <string> vet;

//     string linha;

//     ifstream Leitura;
//     Leitura.open("arquivos/gerar10000.txt");

//     if(Leitura.is_open()) {
//         while(getline(Leitura, linha)) {
//             vet.push_back(linha);
//         }
//     }

//     Leitura.close();

//     unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

//     shuffle (vet.begin(), vet.end(), std::default_random_engine(seed));

//     vector <string>::iterator i;

//     for(i = vet.begin(); i != vet.end(); ++i) {
//         cout << "valor: " << *i << endl;
//     }

//     // for(auto x:vet2) {
//     //     cout << x << endl;
//     // }

// }