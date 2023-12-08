// teste3.c
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../src/trie.h"

int inicializacao_suite(void) {
    return 0;
}

int encerramento_suite(void) {
    return 0;
}

void teste_busca_nodo_positivo(void) {
    Nodo *trie = (Nodo *)1; // Nodo com ponteiro positivo como parâmetro
    char chave[] = "exemplo";

    CU_ASSERT_EQUAL(Busca(trie, chave), NULL);
}

int main() {
    CU_initialize_registry();

    CU_pSuite suite = CU_add_suite("Suite de Testes", inicializacao_suite, encerramento_suite);

    CU_add_test(suite, "Teste Busca com Nodo Positivo", teste_busca_nodo_positivo);

    CU_basic_run_tests();

    CU_cleanup_registry();

    return CU_get_error();
}