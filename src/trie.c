#include "trie.h"

// Função criaNodo:
// Aloca dinamicamente um novo nodo da trie e utiliza um loop "for" para inicializar todos os ponteiros filho do novo nodo como nulo.
// Inicializa o conteúdo como nulo também e retorna um ponteiro para o novo nodo.
Nodo *criaNodo() {
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    for (int i = 0; i < 26; i++) {
        novo->filho[i] = NULL;
    }
    novo->conteudo = NULL;
    return novo;
}

// Função criaCadastro:
// Função que recebe como parâmetros uma string (s) e uma idade (idade), aloca dinamicamente um novo cadastro.
// Copia a string e a idade para o cadastro criado e retorna o ponteiro para o cadastro.
Cadastro *criaCadastro(char *s, int idade) {
    Cadastro *usuario = (Cadastro *)malloc(sizeof(Cadastro));
    strcpy(usuario->Nome, s);
    usuario->Idade = idade;
    return usuario;
}

// Função Busca:
// Função que recebe como parâmetros um nodo (trie) e uma string (s) e busca recursivamente a chave correspondente na árvore trie e retorna um ponteiro para o conteúdo (tipo Cadastro). 
// A busca ocorre até que a string de entrada (ID) seja totalmente processada ou o nodo correspondente seja nulo.
Cadastro *Busca(Nodo *trie, char *s) {
    if (trie == NULL)
        return NULL;
    if (*s == '\0')
        return trie->conteudo;
    if (trie->filho[(*s) - 'a'] == NULL)
        return NULL;
    return Busca(trie->filho[(*s) - 'a'], &s[1]);
}

// Função Insere:
// Função que recebe como parâmetros um nodo (trie), uma string (s) e um ponteiro para conteúdo (cont).
// Insere recursivamente o nodo que aponta para o conteúdo no caminho correspondente à string.
void Insere(Nodo *trie, char *s, Cadastro *cont) {
    if (*s == '\0') {
        trie->conteudo = cont;
        return;
    } else if (trie->filho[(*s) - 'a'] == NULL)
        trie->filho[(*s) - 'a'] = criaNodo();
    Insere(trie->filho[(*s) - 'a'], &s[1], cont);
}

// Função Remove:
// Função que recebe como parâmetros um nodo (trie) e uma string (s) e desmarca recursivamente o ponteiro para conteúdo do nodo com caminho correspondente à string.
// A remoção ocorre recursivamente até que a string de entrada (ID) seja totalmente processada (removida).
void Remove(Nodo *trie, char *s) {
    if (*s == '\0') {
        trie->conteudo = NULL;
        return;
    }
    Remove(trie->filho[(*s) - 'a'], &s[1]);
}

// Função Imprime:
// Função que recebe como parâmetros um nodo (trie), uma string (s) e um ponteiro para inteiro (tam) e sua execução imprime recursivamente todas as chaves-conteúdos em ordem alfabética. 
// A impressão ocorre recursivamente até que todos os nodos da árvore tenham sido percorridos.
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

// Função Salva:
// Função que recebe como parâmetros um arquivo (arq), um nodo (trie), uma string (s) e um ponteiro para inteiro (tam) e salva recursivamente no arquivo todas as chaves-conteúdos da trie em ordem alfabética. 
// A escrita no arquivo ocorre até que todos os nodos da árvore tenham sido percorridos.
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

// Função Tamanho:
// Função que recebe como parâmetro um nodo (trie) e retorna recursivamente o tamanho (quantidade de chaves-conteúdos) da árvore trie. 
// A contagem ocorre recursivamente até que todos os nodos da árvore tenham sido percorridos.
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

//  Função remove_espaco:
//  Função que recebe como parâmetro uma string (s) e remove o último caractere espaço para ficar de acordo com o formato solicitado.
void remove_espaco(char *s) {
    s[strlen(s) - 1] = '\0';
}

// Função Esvazia:
// Função que recebe como parâmetro um nodo (trie) e libera recursivamente toda a memória armazenada dinamicamente. A liberação de memória ocorre recursivamente até que todos os nodos da árvore tenham sido percorridos. 
// Ou seja, ele percorrerá por todo conteúdo (cadastro da trie) e fazer a liberação de memória dos nodos através do loop da recursão.
void Esvazia(Nodo *trie) {
    if (trie == NULL)
        return;

    for (int i = 0; i < 26; i++)
        if (trie->filho[i] != NULL)
            Esvazia(trie->filho[i]);

    free(trie->conteudo);
    free(trie);
}