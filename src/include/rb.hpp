#ifndef RB_HPP
#define RB_HPP

#include "record.hpp"

// enum type {black, red};
#define red 1
#define black 0

//typedef struct Record Record;
typedef struct TreeRB TreeRB;

// struct Record {
// 	int key;
// };

struct TreeRB {
	Record reg3;
	TreeRB *esq, *dir;
	TreeRB *pai; //específico para rubro negra
	bool cor;
	// enum type cor;  //específico para rubro negra (FALSE = VERMELHOR, TRUE = PRETO)
};

void inicializaTreeRB(TreeRB **root);

TreeRB *tree_successor(TreeRB *aux_succ);

TreeRB *CreateTreeRB();

void rotacaoSimplesEsquerda(TreeRB **raiz3, TreeRB *child);
void rotacaoSimplesDireita(TreeRB **raiz3, TreeRB *child);

void insertFixUp(TreeRB **raiz3, TreeRB *child);
void insertTree3(TreeRB **t, TreeRB **pai, TreeRB **raiz, Record r3);
void pesquisaRB(TreeRB **t, TreeRB **auxRB, Record r3);

void treeSizeRB(TreeRB *t, int *cont);
void central(TreeRB *t);
void posordem(TreeRB *t);

void removerTree3(TreeRB **t, int key);

void RB_delete(TreeRB **root, TreeRB *z, TreeRB *y, TreeRB *x);
void RB_delete_fix(TreeRB **root, TreeRB *x, TreeRB *w);
void RB_transplant(TreeRB **root, TreeRB *aux, TreeRB *auxchild);

void searchRB(TreeRB *aux, Record z, double *quant);
void search_delete(TreeRB **root, TreeRB *aux, Record z);

void rb_insert(TreeRB **root, TreeRB *x, TreeRB *y, TreeRB *temp);


#endif