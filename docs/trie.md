## criaNodo()

função aloca dinamicamente um novo nodo da trie. Utiliza um loop para inicializar todos os ponteiros filho do novo nodo como nulo e também inicializa o conteúdo como nulo. Retorna um ponteiro para o novo nodo.

## Cria Cadastro


### Cria Cadastro

    criaCadastro(char *s, int idade)

Esta função recebe uma string s (nome) e um inteiro idade, alocando dinamicamente um novo cadastro. Copia a string e a idade para o cadastro criado e retorna o ponteiro para o cadastro.

### Busca(Nodo *trie, char *s)

A função Busca recebe um nodo (raiz da trie) e uma string s (ID) e busca recursivamente a chave correspondente na árvore trie. Retorna um ponteiro para o conteúdo (tipo Cadastro). A busca ocorre até que a string de entrada (ID) seja totalmente processada ou o nodo correspondente seja nulo.

### Insere(Nodo *trie, char *s, Cadastro *cont)

Esta função recebe um nodo (raiz da trie), uma string s (ID) e um ponteiro para conteúdo (Cadastro). Insere recursivamente o nodo que aponta para o conteúdo no caminho correspondente à string.

### Remove(Nodo *trie, char *s)

A função Remove recebe um nodo (raiz da trie) e uma string s (ID), desmarcando recursivamente o ponteiro para conteúdo do nodo com caminho correspondente à string. A remoção ocorre até que a string de entrada (ID) seja totalmente processada (removida).

### Imprime(Nodo *trie, char *s, int *tam)

A função Imprime recebe um nodo (raiz da trie), uma string s e um ponteiro para inteiro tam. Sua execução imprime recursivamente todas as chaves-conteúdos em ordem alfabética. A impressão ocorre até que todos os nodos da árvore tenham sido percorridos.

### Salva(FILE *arq, Nodo *trie, char *s, int *tam)

A função Salva recebe um arquivo arq, um nodo (raiz da trie), uma string s e um ponteiro para inteiro tam. Salva recursivamente no arquivo todas as chaves-conteúdos da trie em ordem alfabética. A escrita no arquivo ocorre até que todos os nodos da árvore tenham sido percorridos.

### Tamanho(Nodo *trie)

A função Tamanho recebe um nodo (raiz da trie) e retorna recursivamente o tamanho (quantidade de chaves-conteúdos) da árvore trie. A contagem ocorre até que todos os nodos da árvore tenham sido percorridos.

### remove_espaco(char *s)

A função remove_espaco recebe uma string s e remove o último caractere espaço para ficar de acordo com o formato solicitado.

### Esvazia(Nodo *trie)

A função Esvazia recebe um nodo (raiz da trie) e libera recursivamente toda a memória armazenada dinamicamente. A liberação de memória ocorre até que todos os nodos da árvore tenham sido percorridos.### Esvazia(Nodo *trie)

A função Esvazia recebe um nodo (raiz da trie) e libera recursivamente toda a memória armazenada dinamicamente. A liberação de memória ocorre até que todos os nodos da árvore tenham sido percorridos.
### Esvazia(Nodo *trie)

A função Esvazia recebe um nodo (raiz da trie) e libera recursivamente toda a memória armazenada dinamicamente. A liberação de memória ocorre até que todos os nodos da árvore tenham sido percorridos.### Esvazia(Nodo *trie)

A função Esvazia recebe um nodo (raiz da trie) e libera recursivamente toda a memória armazenada dinamicamente. A liberação de memória ocorre até que todos os nodos da árvore tenham sido percorridos.