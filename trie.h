#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Nome[1001];
    int Idade;
} Cadastro;

typedef struct nodo {
    struct nodo *filho[26];
    Cadastro *conteudo;
} Nodo;

Nodo *criaNodo();
Cadastro *criaCadastro(char *s, int idade);
Cadastro *Busca(Nodo *trie, char *s);
void Insere(Nodo *trie, char *s, Cadastro *cont);
void Remove(Nodo *trie, char *s);
void Imprime(Nodo *trie, char *s, int *tam);
void Salva(FILE *arq, Nodo *trie, char *s, int *tam);
int Tamanho(Nodo *trie);
void remove_espaco(char *s);
void Esvazia(Nodo *trie);

#endif
