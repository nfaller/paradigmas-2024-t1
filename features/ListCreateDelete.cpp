/* SPDX-License-Identifer: MIT */

#if defined(GITHUB_WORKFLOW) && GITHUB_WORKFLOW == 1
    #include <catch2/catch.hpp>
#else
    #include <catch2/catch_test_macros.hpp>
#endif /* GITHUB_WORKFLOW */

#include <stdlib.h>

#include "lista.h"

SCENARIO("Cria e destrói uma lista de inteiros", "[CreateDeleteInt]") {
    GIVEN("Uma lista não inicializada.") {
        Lista intlist;

        WHEN ("Inicializo a lista") {
            Lista_new(&intlist, sizeof(int), NULL);

            THEN("A lista é inicialidada corretamente.") {}

            WHEN ("A lista é destruîda.") {
                Lista_delete(&intlist);
                THEN ("A lista é finalizada corretamente.") {}
            }
        }
    }
}

SCENARIO("Cria e destrói uma lista de doubles", "[CreateDeleteDouble]") {
    GIVEN("Uma lista não inicializada.") {
        Lista doublelist;

        WHEN ("Inicializo a lista") {
            Lista_new(&doublelist, sizeof(double), NULL);

            THEN("A lista é inicialidada corretamente.") {
            }
            WHEN ("A lista é destruîda.") {
                Lista_delete(&doublelist);
                THEN ("A lista é finalizada corretamente.") {}
            }
        }
    }
}

/* conta número de chamadas a my_free. */
static int my_free_calls = 0;
/* reseta a contagem */
void reset_count(int *var) {
    *var = 0;
}
/* Libera a memório e atualiza o número de chamadas a função. */
void my_free(void* data) {
    my_free_calls++;
    free(data);
}

SCENARIO ("Cria e destrói uma lista de strings", "[CreateDeleteCharPointer]") {
    GIVEN ("Uma lista não inicializada.") {
        Lista charplist;

        WHEN ("Inicializo a lista") {
            Lista_new(&charplist, sizeof(char*), my_free);

            THEN ("A lista é inicialidada corretamente.") {
            }
            WHEN ("A lista é destruîda.") {
                Lista_delete(&charplist);
                THEN ("A lista é finalizada corretamente.") {}
            }
        }
    }
}
