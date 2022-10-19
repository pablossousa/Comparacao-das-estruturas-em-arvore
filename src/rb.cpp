#include "include/rb.hpp"

TreeRB *CreateTreeRB() {
    return NULL;
}

TreeRB *temp, *nill;

void inicializaTreeRB(TreeRB **root) {
    nill = (TreeRB *)malloc(sizeof(TreeRB));
    nill->cor = black;
    nill->esq = NULL;
    nill->dir = NULL;
    nill->pai = NULL;
    nill->reg3.key = 0;
    (*root) = nill;
}

void insertFixUp(TreeRB **raiz3, TreeRB *child) {
    TreeRB *tio;

    while ((child != *raiz3) && (child->pai->cor == red)) {

        if (child->pai == child->pai->pai->esq) {

            tio = child->pai->pai->dir;

            // caso 1:
            if ((tio != nill) && (tio->cor == red)) {
                child->pai->cor = black;
                tio->cor = black;
                child->pai->pai->cor = red;
                child = child->pai->pai;
            } else {

                // caso 2
                if (child == child->pai->dir) {
                    child = child->pai;
                    rotacaoSimplesEsquerda(raiz3, child);
                }

                // caso 3
                child->pai->cor = black;
                child->pai->pai->cor = red;
                rotacaoSimplesDireita(raiz3, child->pai->pai);
            }
        } else {

            tio = child->pai->pai->esq;

            // caso 1
            if ((tio != nill) && (tio->cor == red)) {
                child->pai->cor = black;
                tio->cor = black;
                child->pai->pai->cor = red;
                child = child->pai->pai;
            } else {

                // caso 2
                if (child == child->pai->esq) {
                    child = child->pai;
                    rotacaoSimplesDireita(raiz3, child);
                }

                // caso 3
                child->pai->cor = black;
                child->pai->pai->cor = red;
                rotacaoSimplesEsquerda(raiz3, child->pai->pai);
            }
        }
    }

    (*raiz3)->cor = black;
}

void insertTree3(TreeRB **t, TreeRB **pai, TreeRB **raiz3, Record r) {

    if (*t == nill) {
        *t = (TreeRB *)malloc(sizeof(TreeRB));
        (*t)->esq = nill;
        (*t)->dir = nill;
        (*t)->pai = pai != t ? *pai : nill;
        (*t)->cor = red; // red: vermelho  black:preto
        (*t)->reg3 = r;
        insertFixUp(raiz3, *t);
    } else {

        if (r.key < (*t)->reg3.key) {
            insertTree3(&(*t)->esq, t, raiz3, r);
            return;
        }

        if (r.key > (*t)->reg3.key) {
            insertTree3(&(*t)->dir, t, raiz3, r);
            return;
        }
    }
}

void pesquisaRB(TreeRB **t, TreeRB **auxRB, Record r) {

    if (*t == nill) {
        return;
    }

    if ((*t)->reg3.key > r.key) {
        pesquisaRB(&(*t)->esq, auxRB, r);
        return;
    }
    if ((*t)->reg3.key < r.key) {
        pesquisaRB(&(*t)->dir, auxRB, r);
        return;
    }

    *auxRB = *t;

    if (*auxRB != nill) {
    }
}

void rotacaoSimplesEsquerda(TreeRB **raiz3, TreeRB *child) {
    TreeRB *x, *y;

    x = child;
    y = child->dir;
    x->dir = y->esq;

    if (y->esq != nill)
        y->esq->pai = x;

    y->pai = x->pai;

    if (x->pai == nill)
        *raiz3 = y;

    else if (x == x->pai->esq)
        x->pai->esq = y;
    else if (x == x->pai->dir)
        x->pai->dir = y;

    y->esq = x;
    x->pai = y;

}

void rotacaoSimplesDireita(TreeRB **raiz3, TreeRB *child) {
    TreeRB *x, *y;

    x = child;
    y = child->esq;
    x->esq = y->dir;

    if (y->dir != nill)
        y->dir->pai = x;

    y->pai = x->pai;

    if (x->pai == nill) {
        *raiz3 = y;
    }

    else if (x == x->pai->dir)
        x->pai->dir = y;
    else if (x == x->pai->esq)
        x->pai->esq = y;

    y->dir = x;
    x->pai = y;
}

void treeSizeRB(TreeRB *t, int *cont) {
    if (!(t == nill)) {
        (*cont)++;
        // cout << t->reg3.key << " - ";
        // printf("%s\n", t->cor ? "black" : "red");
        treeSizeRB(t->esq, cont);
        treeSizeRB(t->dir, cont);
    }
}

void central(TreeRB *t) {
    if (!(t == nill)) {
        central(t->esq);
        printf("%.4f - %s\t", t->reg3.key, t->cor ? "black" : "red");
        central(t->dir);
    }
}

void posordem(TreeRB *t) {
    if (!(t == nill)) {
        posordem(t->esq);
        posordem(t->dir);
        printf("%.4f - %s\t", t->reg3.key, t->cor ? "black" : "red");
    }
}

void removerTree3(TreeRB **t, Record r) {

    TreeRB *aux = CreateTreeRB();

    pesquisaRB(t, &aux, r);

    if (aux->reg3.key == r.key) {
    }
}

void search_delete(TreeRB **root, TreeRB *aux, Record z) {
    // cout << z.key << endl;
    while (aux != nill && z.key != aux->reg3.key) {
        if (z.key < aux->reg3.key)
            aux = aux->esq;
        else
            aux = aux->dir;
    }
    if (aux->reg3.key == z.key) {
        //printf("Node (%lf) exist\n", z.key);
        RB_delete(root, aux, aux, aux);
    }
}

void RB_delete_fix(TreeRB **root, TreeRB *x, TreeRB *w) {
    while (x != (*root) && x->cor == black) {
        if (x == x->pai->esq) {
            w = x->pai->dir;
            if (w->cor == red) {
                w->cor = black;
                x->pai->cor = red;
                rotacaoSimplesEsquerda(root, x->pai);
                w = x->pai->dir;
            } else if (w->esq->cor == black && w->dir->cor == black) {
                w->cor = red;
                x = x->pai;
            } else if (w->dir->cor == black) {
                w->esq->cor = black;
                w->cor = red;
                rotacaoSimplesDireita(root, w);
                w = x->pai->dir;
            } else {
                w->cor = x->pai->cor;
                x->pai->cor = black;
                w->dir->cor = black;
                rotacaoSimplesEsquerda(root, x->pai);
                x = (*root);
            }
        } else {
            w = x->pai->esq;
            if (w->cor == red) {
                w->cor = black;
                x->pai->cor = red;
                rotacaoSimplesDireita(root, x->pai);
                w = x->pai->esq;
            } else if (w->dir->cor == black && w->esq->cor == black) {
                w->cor = red;
                x = x->pai;
            } else if (w->esq->cor == black) {
                w->dir->cor = black;
                w->cor = red;
                rotacaoSimplesEsquerda(root, w);
                w = x->pai->esq;
            } else {
                w->cor = x->pai->cor;
                x->pai->cor = black;
                w->esq->cor = black;
                rotacaoSimplesDireita(root, x->pai);
                x = (*root);
            }
        }
    }
    x->cor = black;
}

TreeRB *tree_successor(TreeRB *aux_succ) {
    while (aux_succ->esq != nill)
        aux_succ = aux_succ->esq;
    return aux_succ;
}

void RB_delete(TreeRB **root, TreeRB *z, TreeRB *y, TreeRB *x) {
    // enum type originalcolor;                // keep track of x which moves into y's original position
    // originalcolor = (y->cor) ? black : red; // Keep track of original cor
    bool originalcolor = y->cor;

    // case 1
    if (z->esq == nill) {
        x = z->dir;
        RB_transplant(root, z, z->dir);
    }
    // case 2
    else if (z->dir == nill) {
        x = z->esq;
        RB_transplant(root, z, z->esq);
    }
    // two cases: z has both Children
    else {
        y = tree_successor(z->dir);
        originalcolor = y->cor;
        x = y->dir;

        if (y->pai == z) {
            x->pai = y;
        }
        // swap subtree of y->dir pointing to y->pai (before we move y to z)
        else {
            RB_transplant(root, y, y->dir);
            y->dir = z->dir; // partial change of y
            y->dir->pai = y;
        }
        // replacement of z with y (also builds subtrees)
        RB_transplant(root, z, y);
        y->esq = z->esq;
        y->esq->pai = y;
        y->cor = z->cor;
    }
    // imbalanced RBT only possible when we delete a black node
    if (originalcolor == black)
        RB_delete_fix(root, x, x);
    free(z);
}

void RB_transplant(TreeRB **root, TreeRB *aux, TreeRB *auxchild) {
    if (aux->pai == nill)
        (*root) = auxchild;
    else if (aux == aux->pai->esq)
        aux->pai->esq = auxchild;
    else
        aux->pai->dir = auxchild;
    auxchild->pai = aux->pai;
}