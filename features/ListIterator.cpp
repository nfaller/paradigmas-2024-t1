/* SPDX-License-Identifer: MIT */

#if defined(GITHUB_WORKFLOW) && GITHUB_WORKFLOW == 1
    #include <catch2/catch.hpp>
#else
    #include <catch2/catch_test_macros.hpp>
#endif /* GITHUB_WORKFLOW */

#include <stdlib.h>
#include <string.h>

#include "lista.h"

SCENARIO("Acessa o último elemento da lista, como um iterador", "[IteratorLastInt]") {
    GIVEN("Uma lista inicializada com valores.") {
        Lista intlist;
        Lista_new(&intlist, sizeof(int), NULL);
        for (int i = 0; i < 5; i++) {
            Lista_pushBack(&intlist, &i);
        }

        WHEN ("Acesso o último item") {
            Lista_last(&intlist);

            THEN ("O último item tem valor 4.") {
                int value;
                Lista_current(&intlist, &value);
                REQUIRE (4 == value);
            }
        
            Lista_delete(&intlist);
        }
    }
}
        
/*

SCENARIO("Acessa o primeiro elemento da lista, como um iterador", "[IteratorFirstInt]") {
    GIVEN("Uma lista inicializada com valores.") {
        Lista intlist;
        Lista_new(&intlist, sizeof(int), NULL);
        for (int i = 0; i < 5; i++) {
            Lista_pushBack(&intlist, &i);
        }

        WHEN ("Acesso o primeiro item") {
            Lista_first(&intlist);

            THEN ("O primeiro item tem valor 0.") {
                int value;
                Lista_current(&intlist, &value);
                REQUIRE (0 == value);
            }
            Lista_delete(&intlist);
        }
    }
}

SCENARIO("Navega na lista de inteiros como um iterador", "[IteratorInt]") {
    GIVEN("Uma lista inicializada com valores, no primeiro elemento.") {
        Lista intlist;
        Lista_new(&intlist, sizeof(int), NULL);
        for (int i = 0; i < 5; i++) {
            Lista_pushBack(&intlist, &i);
        }
        Lista_first(&intlist);

        WHEN ("Navega nos elementos como um iterador") {
            for (int i=1; i < 5; i++) {
                int esperado = Lista_next(&intlist);
                THEN ("Acessou o próximo elemento") {
                    REQUIRE (true == bool(esperado));
                }
                AND_THEN ("O valor do elemento é " << i) {
                    int value;
                    Lista_current(&intlist, &value);
                    REQUIRE (value == i);
                }
            }
            Lista_delete(&intlist);
        }
    }
}

SCENARIO("Navega após o fim da lista como um iterador", "[IteratorAfterLastInt]") {
    GIVEN("Uma lista inicializada com valores, no último elemento.") {
        Lista intlist;
        Lista_new(&intlist, sizeof(int), NULL);
        for (int i = 0; i < 5; i++) {
            Lista_pushBack(&intlist, &i);
        }
        Lista_last(&intlist);

        WHEN ("Acesso um elemento após o último elemento da lista") {
            int esperado = Lista_next(&intlist);
            THEN ("Não existe um próximo elemento") {
                REQUIRE (false == bool(esperado));
            }
            Lista_delete(&intlist);
        }
    }
}

SCENARIO("Insere elemento apos atual, com iterador", "[IteratorAddAfterInt]") {
    GIVEN("Uma lista inicializada com valores, no terceiro.") {
        Lista intlist;
        Lista_new(&intlist, sizeof(int), NULL);
        for (int i = 0; i < 5; i++) {
            Lista_pushBack(&intlist, &i);
        }
        Lista_first(&intlist);
        REQUIRE (Lista_next(&intlist));
        REQUIRE (Lista_next(&intlist));

        int current;
        Lista_current(&intlist, &current);

        WHEN ("Insiro elemento apos o atual, usando o iterador") {
            int novo_valor = 100;
            Lista_insertAfter(&intlist, &novo_valor);
            THEN ("O valor do elemento atual continua o mesmo.") {
                int valor;
                Lista_current(&intlist, &valor);
                REQUIRE (valor == current);
            }
            AND_THEN ("Existe um novo valor") {
                REQUIRE (Lista_next(&intlist));
            }
            AND_THEN ("O valor do próximo elemento é " << novo_valor) {
                int valor;
                REQUIRE (Lista_next(&intlist));
                Lista_current(&intlist, &valor);
                REQUIRE (novo_valor == valor);
            }            

            Lista_delete(&intlist);
        }
    }
}

SCENARIO("Acessa o último elemento da lista, como um iterador", "[IteratorLastDouble]") {
    GIVEN("Uma lista inicializada com valores.") {
        Lista doublelist;
        Lista_new(&doublelist, sizeof(double), NULL);
        for (double i = 0; i < 5; i++) {
            Lista_pushBack(&doublelist, &i);
        }

        WHEN ("Acesso o último item") {
            Lista_last(&doublelist);

            THEN ("O último item tem valor 4.") {
                double value;
                Lista_current(&doublelist, &value);
                REQUIRE (4.0 == value);
            }
        
            Lista_delete(&doublelist);
        }
    }
}
        
SCENARIO("Acessa o primeiro elemento da lista, como um iterador", "[IteratorFirstDouble]") {
    GIVEN("Uma lista inicializada com valores.") {
        Lista doublelist;
        Lista_new(&doublelist, sizeof(double), NULL);
        for (double i = 0; i < 5; i++) {
            Lista_pushBack(&doublelist, &i);
        }

        WHEN ("Acesso o primeiro item") {
            Lista_first(&doublelist);

            THEN ("O primeiro item tem valor 0.") {
                double value;
                Lista_current(&doublelist, &value);
                REQUIRE (0 == value);
            }
            Lista_delete(&doublelist);
        }
    }
}

SCENARIO("Navega na lista de doubles como um iterador", "[IteratorDouble]") {
    GIVEN("Uma lista inicializada com valores, no primeiro elemento.") {
        Lista doublelist;
        Lista_new(&doublelist, sizeof(double), NULL);
        for (double i = 0; i < 5; i++) {
            Lista_pushBack(&doublelist, &i);
        }
        Lista_first(&doublelist);

        WHEN ("Navega nos elementos como um iterador") {
            for (double i=1; i < 5; i++) {
                int esperado = Lista_next(&doublelist);
                THEN ("Acessou o próximo elemento") {
                    REQUIRE (true == bool(esperado));
                }
                AND_THEN ("O valor do elemento é " << i) {
                    double value;
                    Lista_current(&doublelist, &value);
                    REQUIRE (value == i);
                }
            }
            Lista_delete(&doublelist);
        }
    }
}

SCENARIO("Navega após o fim da lista como um iterador", "[IteratorAfterLastDouble]") {
    GIVEN("Uma lista inicializada com valores, no último elemento.") {
        Lista doublelist;
        Lista_new(&doublelist, sizeof(double), NULL);
        for (double i = 0; i < 5; i++) {
            Lista_pushBack(&doublelist, &i);
        }
        Lista_last(&doublelist);

        WHEN ("Acesso um elemento após o último elemento da lista") {
            int esperado = Lista_next(&doublelist);
            THEN ("Não existe um próximo elemento") {
                REQUIRE (false == bool(esperado));
            }
            Lista_delete(&doublelist);
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

/*

SCENARIO("Acessa o último elemento da lista, como um iterador", "[IteratorLastString]") {
    GIVEN("Uma lista inicializada com valores.") {
        Lista strlist;
        Lista_new(&strlist, sizeof(char*), my_free);
        const char* names[] = {"a","b","c","d","e"};
        for (int i = 0; i < 5; i++) {
            char* value = (char*)names[i];
            Lista_pushBack(&strlist, &value);
        }

        WHEN ("Acesso o último item") {
            Lista_last(&strlist);

            THEN ("O último item tem valor '" << names[4] <<"'.") {
                char* value;
                Lista_current(&strlist, &value);
                REQUIRE (strcmp(value, names[4]) == 0);
            }
        
            Lista_delete(&strlist);
        }
    }
}
        
SCENARIO("Acessa o primeiro elemento da lista, como um iterador", "[IteratorFirstString]") {
    GIVEN("Uma lista inicializada com valores.") {
        Lista strlist;
        Lista_new(&strlist, sizeof(char*), my_free);
        const char* names[] = {"a","b","c","d","e"};
        for (int i = 0; i < 5; i++) {
            char* value = (char*)names[i];
            Lista_pushBack(&strlist, &value);
        }

        WHEN ("Acesso o primeiro item") {
            Lista_first(&strlist);

            THEN ("O primeiro item tem valor '" << names[0] <<"'.") {
                char* value;
                Lista_current(&strlist, &value);
                REQUIRE (strcmp(value, names[0]) == 0);
            }
            Lista_delete(&strlist);
        }
    }
}

SCENARIO("Navega na lista de strings como um iterador", "[IteratorString]") {
    GIVEN("Uma lista inicializada com valores, no primeiro elemento.") {
        Lista strlist;
        Lista_new(&strlist, sizeof(char*), my_free);
        const char* names[] = {"a","b","c","d","e"};
        for (int i = 0; i < 5; i++) {
            char* value = (char*)names[i];
            Lista_pushBack(&strlist, &value);
        }
        Lista_first(&strlist);

        WHEN ("Navega nos elementos como um iterador") {
            for (int i=1; i < 5; i++) {
                int esperado = Lista_next(&strlist);
                THEN ("Acessou o próximo elemento") {
                    REQUIRE (true == bool(esperado));
                }
                AND_THEN ("O valor do elemento é '" << names[i] <<"'.") {
                    char* value;
                    Lista_current(&strlist, &value);
                    REQUIRE (strcmp(value, names[i]) == 0);
                }
            }
            Lista_delete(&strlist);
        }
    }
}

SCENARIO("Navega após o fim da lista como um iterador", "[IteratorAfterLastString]") {
    GIVEN("Uma lista inicializada com valores, no último elemento.") {
        Lista strlist;
        Lista_new(&strlist, sizeof(char*), my_free);
        const char* names[] = {"a","b","c","d","e"};
        for (int i = 0; i < 5; i++) {
            char* value = (char*)names[i];
            Lista_pushBack(&strlist, &value);
        }
        Lista_last(&strlist);

        WHEN ("Acesso um elemento após o último elemento da lista") {
            int esperado = Lista_next(&strlist);
            THEN ("Não existe um próximo elemento") {
                REQUIRE (false == bool(esperado));
            }
            Lista_delete(&strlist);
        }
    }
}

*/
