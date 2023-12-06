// teste2.c
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../src/trie.h"

// Função de inicialização do suite
int inicializacao_suite(void) {
    return 0;
}

// Função de encerramento do suite
int encerramento_suite(void) {
    return 0;
}

// Teste para verificar o funcionamento da função Busca com nodo negativo
void teste_busca_nodo_negativo(void) {
    Nodo *trie = (Nodo *)-1; // Nodo com ponteiro negativo como parâmetro
    char chave[] = "exemplo";

    // O resultado da busca deve ser NULL
    CU_ASSERT_EQUAL(Busca(trie, chave), NULL);
}

// Função principal
int main() {
    // Inicializa o registro de suítes
    CU_initialize_registry();

    // Adiciona suíte de teste
    CU_pSuite suite = CU_add_suite("Suite de Testes", inicializacao_suite, encerramento_suite);

    // Adiciona teste à suíte
    CU_add_test(suite, "Teste Busca com Nodo Negativo", teste_busca_nodo_negativo);

    // Executa os testes
    CU_basic_run_tests();

    // Limpa o registro de suítes
    CU_cleanup_registry();

    return CU_get_error();
}