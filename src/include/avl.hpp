#ifndef AVL_HPP
#define AVL_HPP

#include "record.hpp"

// struct Record2{
// 	int key;
// 	int value;
// };

struct TreeAVL{
	Record reg;
	TreeAVL *left, *right;
	int weight;
};

TreeAVL* CreateTreeAVL();
void insertTree2(TreeAVL **t, Record r2);
void pesquisaAVL(TreeAVL **t, TreeAVL **auxAVL, Record r2);
int isInTree(TreeAVL *t, Record r2);

//muda o remove devido a necessidade de ponteiro para sub-árvore desbalanceada
void removeTree2(TreeAVL **t, TreeAVL **f, Record r2);
void antecessor(TreeAVL **t, TreeAVL *aux);
void rebalanceTree(TreeAVL **t);

void treeSizeAvl(TreeAVL *t, int *cont);
void central(TreeAVL *t);
void posordem(TreeAVL *t);


int getWeight(TreeAVL **t);
int getMaxWeight(int left, int right);


void rotacaoSimplesDireita(TreeAVL **t);
void rotacaoSimplesEsquerda(TreeAVL **t);
void rotacaoDuplaDireita(TreeAVL **t);
void rotacaoDuplaEsquerda(TreeAVL **t);


#endif