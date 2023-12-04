#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// STRUCT Cadastro:
// Estrutura que representa o conteúdo a ser armazernado em cada nodo da trie.
// Apresentada na forma de um cadastro contendo um char para um nome (até 1000 caracteres) e um inteiro para a idade.
typedef struct {
    char Nome[1001];
    int Idade;
} Cadastro;

// STRUCT nodo:
// Estrutura de um nodo na árvore trie. 
// Cada nodo tem um vetor de 26 ponteiros para nodos filhos (um para cada letra do alfabeto) e um ponteiro para um cadastro (conteudo da trie).
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
