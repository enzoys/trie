#include "trie.h"

Nodo *criaNodo() {
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    for (int i = 0; i < 26; i++) {
        novo->filho[i] = NULL;
    }
    novo->conteudo = NULL;
    return novo;
}

Cadastro *criaCadastro(char *s, int idade) {
    Cadastro *usuario = (Cadastro *)malloc(sizeof(Cadastro));
    strcpy(usuario->Nome, s);
    usuario->Idade = idade;
    return usuario;
}

Cadastro *Busca(Nodo *trie, char *s) {
    if (*s == '\0')
        return trie->conteudo;
    if (trie->filho[(*s) - 'a'] == NULL)
        return NULL;
    return Busca(trie->filho[(*s) - 'a'], &s[1]);
}

void Insere(Nodo *trie, char *s, Cadastro *cont) {
    if (*s == '\0') {
        trie->conteudo = cont;
        return;
    } else if (trie->filho[(*s) - 'a'] == NULL)
        trie->filho[(*s) - 'a'] = criaNodo();
    Insere(trie->filho[(*s) - 'a'], &s[1], cont);
}

void Remove(Nodo *trie, char *s) {
    if (*s == '\0') {
        trie->conteudo = NULL;
        return;
    }
    Remove(trie->filho[(*s) - 'a'], &s[1]);
}

void Imprime(Nodo *trie, char *s, int *tam) {
    if (trie == NULL)
        return;

    int i;

    if (trie->conteudo != NULL) {
        printf("(");
        for (i = 0; i < *tam; i++)
            printf("%c", s[i]);
        printf("|%s|%d)\n", trie->conteudo->Nome, trie->conteudo->Idade);
    }

    for (i = 0; i < 26; i++)
        if (trie->filho[i] != NULL) {
            s[(*tam)++] = 'a' + i;
            Imprime(trie->filho[i], s, tam);
        }

    if (i == 26)
        (*tam)--;
}

void Salva(FILE *arq, Nodo *trie, char *s, int *tam) {
    if (trie == NULL)
        return;

    int i;

    if (trie->conteudo != NULL) {
        for (i = 0; i < *tam; i++)
            fprintf(arq, "%c", s[i]);
        fprintf(arq, " %s %d\n", trie->conteudo->Nome, trie->conteudo->Idade);
    }

    for (i = 0; i < 26; i++)
        if (trie->filho[i] != NULL) {
            s[(*tam)++] = 'a' + i;
            Salva(arq, trie->filho[i], s, tam);
        }

    if (i == 26)
        (*tam)--;
}

int Tamanho(Nodo *trie) {
    if (trie == NULL)
        return 0;

    int i, tam = 0;

    for (i = 0; i < 26; i++)
        if (trie->filho[i] != NULL)
            tam += Tamanho(trie->filho[i]);

    if (trie->conteudo != NULL)
        return 1 + tam;
    else
        return tam;
}

void remove_espaco(char *s) {
    s[strlen(s) - 1] = '\0';
}

void Esvazia(Nodo *trie) {
    if (trie == NULL)
        return;

    for (int i = 0; i < 26; i++)
        if (trie->filho[i] != NULL)
            Esvazia(trie->filho[i]);

    free(trie->conteudo);
    free(trie);
}