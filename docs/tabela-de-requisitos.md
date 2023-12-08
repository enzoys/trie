### Requisitos Funcionais:

    Número		Descrição do Requisito

    RF-01		Ler o arquivo "banco.txt" e carregar os cadastros para a estrutura de dados (trie).
    RF-02		Processar comandos do usuário (? [ID], + [ID] [Nome Completo] [Idade], - [ID], P, S, F) de acordo com as especificações.
    RF-03		Para o comando ? [ID], buscar na trie o cadastro correspondente e imprimir no formato especificado.
    RF-04		Para o comando + [ID] [Nome Completo] [Idade], inserir um novo cadastro na trie e imprimir mensagem de confirmação.
    RF-05		Para o comando - [ID], remover o cadastro da trie e imprimir mensagem de confirmação.
    RF-06		Para o comando P, percorrer a trie e imprimir todos os cadastros no formato especificado.
    RF-07		Para o comando S, salvar todos os cadastros presentes na trie no arquivo "banco.txt" e imprimir mensagem de confirmação.
    RF-08		Para o comando F, terminar a execução do programa.

### Requisitos Não Funcionais:

    Número		Descrição do Requisito
    RNF-01		O programa deve ser implementado em linguagem C.
    RNF-02		A estrutura de dados deve ser uma trie para armazenar os cadastros.
    RNF-03		Cada nó terminal da trie deve conter um ponteiro para uma struct com os dados completos do cadastro.
    RNF-04		IDs têm no máximo 30 caracteres, Nomes Completos têm no máximo 1000 caracteres, e as idades variam de 0 a 99 anos.
    RNF-05		Todo comando deve ser processado a partir da trie.
    RNF-06		Ao final da execução, liberar toda a memória utilizada pelo programa.

