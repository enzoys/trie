# Biblioteca Trie e Testes Unitários

O código implementa uma árvore trie para armazenar e manipular informações de cadastros (nome e idade) associados a IDs. Também foram implementadas funções para realizar operações como busca, inserção, remoção, impressão e salvamento do conteúdo da árvore em um arquivo de texto. Foi disponibilizado um teste unitário em CUnit para testar o funcionamento da função de Busca

## A Trie

Uma Trie (árvore de prefixos) é uma estrutura de dados de árvore especializada, utilizada principalmente para armazenar um conjunto dinâmico ou associativo de strings onde a chave é representada pela própria estrutura da árvore.

### Estrutura da Trie

##### Nodos

Cada nodo na Trie representa um caractere da string.
Cada nodo tem um conjunto fixo de filhos, um para cada caractere possível.
Cada nodo pode ter um ponteiro para um valor associado (por exemplo, um cadastro).

##### Caminhos

Os caminhos da raiz até os nodos folha formam as strings armazenadas.

### Funcionamento da Trie

#### Inserção

Para inserir uma nova string, cada caractere é inserido como um nodo, seguindo o caminho correspondente.
Se o caminho não existir, novos nodos são criados.
Um nodo final geralmente contém um indicador de fim de palavra ou o valor associado.

#### Busca

Para buscar uma string, você percorre a árvore seguindo o caminho correspondente aos caracteres da string.
Se o caminho existir e você alcançar um nodo final, a string está presente na Trie.

#### Remoção

Para remover uma string, você percorre a árvore até o nodo correspondente à string.
O nodo final é removido, e se ele era o único caminho para um caractere, os nodos pai desse nodo podem ser removidos recursivamente, até que não haja mais referências.

### Vantagens da trie

##### Eficiente para Prefixos

A Trie é eficiente para buscas por prefixo, uma vez que compartilha os prefixos comuns entre as strings.

##### Busca Rápida

A busca em uma Trie é geralmente mais rápida do que em outras estruturas de dados para conjuntos de dados pequenos e médios.

### Desvantagens da trie

##### Uso de Memória

A principal desvantagem da Trie é o uso de memória. Ela pode se tornar muito grande para conjuntos de dados grandes e pode levar a um alto consumo de memória.

##### Complexidade

Implementar uma Trie pode ser complexo em comparação com estruturas de dados mais simples.

# Uso e Compilação

#### Versão: 1.1.0

## Requisitos

Compilador C (recomendado GCC)

## Compilação

Para usar as funções em um programa C, inclua o arquivo de biblioteca trie.h no seu código fonte. Certifique-se de compilar o código juntamente com o arquivo trie.c para que as funções sejam devidamente vinculadas.

    gcc seu_programa.c trie.c -o seu_programa

Além dos arquivos trie.c e trie.h, que são os únicos obrigatórios para a execução da trie, foi listado também um executável "main.c" para servir de exemplo de compilação/implementação das bibliotecas.

Certifique-se de ter um arquivo de texto "banco.txt" na mesma pasta de suas bibliotecas para o funcionamento de texto correto das funções

## Dupla

Henrique Acacio de Souza Farias 2399040

Enzo Paiva Ramos 2314606