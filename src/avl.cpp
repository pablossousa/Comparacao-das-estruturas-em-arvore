#include "include/avl.hpp"

TreeAVL *CreateTreeAVL() {
	return NULL;
}

void insertTree2(TreeAVL **t, Record r2) {

	if (*t == NULL) {
		*t = (TreeAVL *)malloc(sizeof(TreeAVL));
		(*t)->left = NULL;
		(*t)->right = NULL;
		(*t)->weight = 0;
		(*t)->reg = r2;
	} else {

		if (r2.key < (*t)->reg.key) {
			insertTree2(&(*t)->left, r2);
			if ((getWeight(&(*t)->left) - getWeight(&(*t)->right)) == 2) {
				if (r2.key < (*t)->left->reg.key)
					rotacaoSimplesDireita(t);
				else
					rotacaoDuplaDireita(t);
			}
		}

		if (r2.key > (*t)->reg.key) {
			insertTree2(&(*t)->right, r2);
			if ((getWeight(&(*t)->right) - getWeight(&(*t)->left)) == 2) {
				if (r2.key > (*t)->right->reg.key)
					rotacaoSimplesEsquerda(t);
				else
					rotacaoDuplaEsquerda(t);
			}
		}
	}

	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
}

void pesquisaAVL(TreeAVL **t, TreeAVL **auxAVL, Record r2) {

	if (*t == NULL) {
		return;
	}

	if ((*t)->reg.key > r2.key) {
		pesquisaAVL(&(*t)->left, auxAVL, r2);
		return;
	}
	if ((*t)->reg.key < r2.key) {
		pesquisaAVL(&(*t)->right, auxAVL, r2);
		return;
	}

	*auxAVL = *t;

	if (*auxAVL != NULL) {}
}

int isInTree(TreeAVL *t, Record r2) {

	if (t == NULL) {
		return 0;
	}

	return t->reg.key == r2.key || isInTree(t->left, r2) || isInTree(t->right, r2);
}

void antecessor(TreeAVL **t, TreeAVL *aux) {

	if ((*t)->right != NULL) {
		antecessor(&(*t)->right, aux);
		return;
	}

	aux->reg = (*t)->reg;
	aux = *t;
	*t = (*t)->left;
	free(aux);
}

void rebalanceTree(TreeAVL **t) {

	int balance;
	int left = 0;
	int right = 0;

	balance = getWeight(&(*t)->left) - getWeight(&(*t)->right);
	if ((*t)->left)
		left = getWeight(&(*t)->left->left) - getWeight(&(*t)->left->right);
	if ((*t)->right)
		right = getWeight(&(*t)->right->left) - getWeight(&(*t)->right->right);

	if (balance == 2 && left >= 0)
		rotacaoSimplesDireita(t);
	if (balance == 2 && left < 0)
		rotacaoDuplaDireita(t);

	if (balance == -2 && right <= 0)
		rotacaoSimplesEsquerda(t);
	if (balance == -2 && right > 0)
		rotacaoDuplaEsquerda(t);
}

void removeTree2(TreeAVL **t, TreeAVL **f, Record r2) {
	TreeAVL *aux;

	if (*t == NULL) {
		return;
	}

	if (r2.key < (*t)->reg.key) {
		removeTree2(&(*t)->left, t, r2);
		return;
	}
	if (r2.key > (*t)->reg.key) {
		removeTree2(&(*t)->right, t, r2);
		return;
	}

	if ((*t)->right == NULL) {
		aux = *t;
		*t = (*t)->left;
		free(aux);
		rebalanceTree(f);
		return;
	}

	if ((*t)->left != NULL) {
		antecessor(&(*t)->left, *t);
		rebalanceTree(t);
		rebalanceTree(f);
		return;
	}

	aux = *t;
	*t = (*t)->right;
	free(aux);
	rebalanceTree(t);
	rebalanceTree(f);
}

void treeSizeAvl(TreeAVL *t, int *cont) {
	if (!(t == NULL)) {
		(*cont)++;
		treeSizeAvl(t->left, cont);
		treeSizeAvl(t->right, cont);
	}
}

void central(TreeAVL *t) {
	if (!(t == NULL)) {
		central(t->left);
		printf("%.4f\t", t->reg.key);
		central(t->right);
	}
}

void posordem(TreeAVL *t) {
	if (!(t == NULL)) {
		posordem(t->left);
		posordem(t->right);
		printf("%.4f\t", t->reg.key);
	}
}

int getWeight(TreeAVL **t) {
	if (*t == NULL)
		return -1;
	return (*t)->weight;
}

int getMaxWeight(int left, int right) {
	if (left > right)
		return left;
	return right;
}

void rotacaoSimplesDireita(TreeAVL **t) {
	TreeAVL *aux;
	aux = (*t)->left;
	(*t)->left = aux->right;
	aux->right = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
	aux->weight = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoSimplesEsquerda(TreeAVL **t) {
	TreeAVL *aux;
	aux = (*t)->right;
	(*t)->right = aux->left;
	aux->left = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
	aux->weight = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoDuplaDireita(TreeAVL **t) {
	rotacaoSimplesEsquerda(&(*t)->left);
	rotacaoSimplesDireita(t);
}

void rotacaoDuplaEsquerda(TreeAVL **t) {
	rotacaoSimplesDireita(&(*t)->right);
	rotacaoSimplesEsquerda(t);
}