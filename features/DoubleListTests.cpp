/* SPDX-License-Identifer: MIT */

#if defined(GITHUB_WORKFLOW) && GITHUB_WORKFLOW == 1
    #include <catch2/catch.hpp>
#else
    #include <catch2/catch_test_macros.hpp>
#endif /* GITHUB_WORKFLOW */

#include <stdlib.h>
#include <string.h>

#include "lista.h"

SCENARIO("Remove o elemento atual de uma lista de inteiros, quando este é o último elemento", "[RemoveLastIntList]") {
    GIVEN("Uma lista inicializada com valores, no último item.") {
        Lista intlist;
        Lista_new(&intlist, sizeof(int), NULL);
        for (int i = 0; i < 10; i++) {
            Lista_pushBack(&intlist, &i);
        }
        Lista_last(&intlist);

        WHEN ("Removo o último item") {
            int original;
            Lista_current(&intlist, &original);
            int size = Lista_size(&intlist);

            Lista_removeCurrent(&intlist);
            
            THEN ("O tamanho da lista reduziu em um elemento") {
                REQUIRE (size - 1 == Lista_size(&intlist));
            
                AND_THEN("O último elemento é o penúltimo anterior") {
                    int value;
                    Lista_last(&intlist);
                    Lista_current(&intlist, &value);
                    
                    REQUIRE (value != original);
                    REQUIRE (value == 8);
                }
            }
            Lista_delete(&intlist);
        }
    }
}
/*
        WHEN ("Acesso o primeiro item") {
            int value;
            Lista_first(&intlist);
            Lista_current(&intlist, &value);
            int size = Lista_size(&intlist);

            AND_WHEN("Removo o elemento atual") {
                Lista_removeCurrent(&intlist);
            }

            THEN ("O tamanho da lista reduziu em um elemento") {
                REQUIRE (size - 1 == Lista_size(&intlist));
            }
            AND_THEN("O último elemento é o segundo anterior") {
                Lista_last(&intlist);
                Lista_current(&intlist, &value);
                
                REQUIRE (value == 2);
            }
        }

        WHEN ("Acesso o terceiro item") {
            int value, esperado;
            Lista_first(&intlist);
            for (int i = 0; i < 3; i++) {
                int exists = Lista_next(&intlist);
                REQUIRE (true == bool(exists));
            }
            esperado = value + 1;
            int size = Lista_size(&intlist);

            AND_WHEN("Removo o elemento atual") {
                Lista_removeCurrent(&intlist);
            }

            THEN ("O tamanho da lista reduziu em um elemento") {
                REQUIRE (size - 1 == Lista_size(&intlist));
            }
            AND_THEN("O novo terceiro elemento é o quarto anterior.") {
                Lista_first(&intlist);
                for (int i = 0; i < 2; i++) {
                    int exists = Lista_next(&intlist);
                    REQUIRE (true == bool(exists));
                }
                
                REQUIRE (value == esperado);
            }
        }
    }
}

SCENARIO("Remove o elemento atual de uma lista de doubles", "[RemoveCurrentDoubleList]") {
    GIVEN("Uma lista inicializada com valores.") {
        Lista doublelist;
        Lista_new(&doublelist, sizeof(double), NULL);
        for (double i = 0; i < 10; i += 1) {
            Lista_pushBack(&doublelist, &i);
        }

        WHEN ("Acesso o último item") {
            double value;
            Lista_last(&doublelist);
            Lista_current(&doublelist, &value);
            int size = Lista_size(&doublelist);

            AND_WHEN("Removo o elemento atual") {
                Lista_removeCurrent(&doublelist);
            }

            THEN ("O tamanho da lista reduziu em um elemento") {
                REQUIRE (size - 1 == Lista_size(&doublelist));
            }
            AND_THEN("O último elemento é o penúltimo anterior") {
                Lista_last(&doublelist);
                Lista_current(&doublelist, &value);
                
                REQUIRE (value == 8);
            }
        }

        WHEN ("Acesso o primeiro item") {
            double value;
            Lista_first(&doublelist);
            Lista_current(&doublelist, &value);
            int size = Lista_size(&doublelist);

            AND_WHEN("Removo o elemento atual") {
                Lista_removeCurrent(&doublelist);
            }

            THEN ("O tamanho da lista reduziu em um elemento") {
                REQUIRE (size - 1 == Lista_size(&doublelist));
            }
            AND_THEN("O último elemento é o segundo anterior") {
                Lista_last(&doublelist);
                Lista_current(&doublelist, &value);
                
                REQUIRE (value == 2);
            }
        }

        WHEN ("Acesso o terceiro item") {
            double value, esperado;
            Lista_first(&doublelist);
            for (int i = 0; i < 3; i++) {
                int exists = Lista_next(&doublelist);
                REQUIRE (true == bool(exists));
            }
            esperado = value + 1;
            int size = Lista_size(&doublelist);

            AND_WHEN("Removo o elemento atual") {
                Lista_removeCurrent(&doublelist);
            }

            THEN ("O tamanho da lista reduziu em um elemento") {
                REQUIRE (size - 1 == Lista_size(&doublelist));
            }
            AND_THEN("O novo terceiro elemento é o quarto anterior.") {
                Lista_first(&doublelist);
                for (int i = 0; i < 2; i++) {
                    int exists = Lista_next(&doublelist);
                    REQUIRE (true == bool(exists));
                }
                
                REQUIRE (value == esperado);
            }
        }
    }
}

SCENARIO("Remove o elemento atual de uma lista de strings", "[RemoveCurrentStringList]") {
    GIVEN("Uma lista inicializada com valores.") {
        const char *names[] = {"a", "b", "c", "d", "e", "f", "g", "h"};
        Lista strlist;
        Lista_new(&strlist, sizeof(char*), NULL);
        for (int i = 0; i < 8; i++) {
            Lista_pushBack(&strlist, strdup(names[i]));
        }

        WHEN ("Acesso o último item") {
            Lista_last(&strlist);
            int size = Lista_size(&strlist);

            AND_WHEN("Removo o elemento atual") {
                Lista_removeCurrent(&strlist);
            }

            THEN ("O tamanho da lista reduziu em um elemento") {
                REQUIRE (size - 1 == Lista_size(&strlist));
            }
            AND_THEN("O último elemento é o penúltimo anterior") {
                char* value;
                Lista_last(&strlist);
                Lista_current(&strlist, &value);
                REQUIRE (strcmp(value, names[6]));
                free(value);
            }
        }

        WHEN ("Acesso o primeiro item") {
            Lista_first(&strlist);
            int size = Lista_size(&strlist);

            AND_WHEN("Removo o elemento atual") {
                Lista_removeCurrent(&strlist);
            }

            THEN ("O tamanho da lista reduziu em um elemento") {
                REQUIRE (size - 1 == Lista_size(&strlist));
            }
            AND_THEN("O último elemento é o segundo anterior") {
                char* value;
                Lista_last(&strlist);
                Lista_current(&strlist, &value);
                REQUIRE (strcmp(value, names[1]));
                free(value);
            }
        }

        WHEN ("Acesso o terceiro item") {
            Lista_first(&strlist);
            for (int i = 0; i < 3; i++) {
                int exists = Lista_next(&strlist);
                REQUIRE (true == bool(exists));
            }
            int size = Lista_size(&strlist);

            AND_WHEN("Removo o elemento atual") {
                Lista_removeCurrent(&strlist);
            }

            THEN ("O tamanho da lista reduziu em um elemento") {
                REQUIRE (size - 1 == Lista_size(&strlist));
            }
            AND_THEN("O novo terceiro elemento é o quarto anterior.") {
                Lista_first(&strlist);
                for (int i = 0; i < 2; i++) {
                    int exists = Lista_next(&strlist);
                    REQUIRE (true == bool(exists));
                }

                char* value;
                Lista_current(&strlist, &value);
                REQUIRE (strcmp(value, names[5]));
                free(value);
            }
        }
    }
}

SCENARIO("Insere elementos antes do atual numa lista de inteiros.", "[InsertBeforInt]") {
    GIVEN("Uma lista inicializada com valores e posicionada no primeiro elemento.") {
        Lista intlist;
        Lista_new(&intlist, sizeof(int), NULL);
        for (int i = 0; i < 5; i += 1) {
            Lista_pushBack(&intlist, &i);
        }
        Lista_first(&intlist);
        int size = Lista_size(&intlist);

        WHEN ("Adiciono um elemento antes do elemento atual") {
            int value = 100;
            Lista_insertBefore(&intlist, &value);

            THEN ("O tamanho da lista aumentou em um elemento") {
                REQUIRE (size + 1 == Lista_size(&intlist));
            }
            AND_THEN("O primeiro elemento tem o valor 100") {
                int value;
                Lista_first(&intlist);
                Lista_current(&intlist, &value);
                REQUIRE(100 == value);
            }
        }
    }
    GIVEN("Uma lista inicializada com valores e posicionada no terceiro elemento.") {
        Lista intlist;
        Lista_new(&intlist, sizeof(int), NULL);
        for (int i = 0; i < 5; i += 1) {
            Lista_pushBack(&intlist, &i);
        }
        Lista_first(&intlist);
        Lista_next(&intlist);
        Lista_next(&intlist);
        int size = Lista_size(&intlist);

        WHEN ("Adiciono um elemento antes do elemento atual") {
            int value = 100;
            Lista_insertBefore(&intlist, &value);

            THEN ("O tamanho da lista aumentou em um elemento") {
                REQUIRE (size + 1 == Lista_size(&intlist));
            }
            AND_THEN("O terceeiro elemento tem o valor 100") {
                int value;
                Lista_first(&intlist);
                Lista_next(&intlist);
                Lista_next(&intlist);
                Lista_current(&intlist, &value);
                REQUIRE(100 == value);
            }
        }
    }
}

SCENARIO("Insere elementos antes do atual numa lista de doubles.", "[InsertBeforeDouble]") {
    GIVEN("Uma lista inicializada com valores e posicionada no primeiro elemento.") {
        Lista doublelist;
        Lista_new(&doublelist, sizeof(double), NULL);
        for (double i = 0; i < 5; i += 1) {
            Lista_pushBack(&doublelist, &i);
        }
        Lista_first(&doublelist);
        int size = Lista_size(&doublelist);

        WHEN ("Adiciono um elemento antes do elemento atual") {
            double value = 100;
            Lista_insertBefore(&doublelist, &value);

            THEN ("O tamanho da lista aumentou em um elemento") {
                REQUIRE (size + 1 == Lista_size(&doublelist));
            }
            AND_THEN("O primeiro elemento tem o valor 100") {
                double value;
                Lista_first(&doublelist);
                Lista_current(&doublelist, &value);
                REQUIRE(100 == value);
            }
        }
    }
    GIVEN("Uma lista inicializada com valores e posicionada no terceiro elemento.") {
        Lista doublelist;
        Lista_new(&doublelist, sizeof(double), NULL);
        for (int i = 0; i < 5; i += 1) {
            Lista_pushBack(&doublelist, &i);
        }
        Lista_first(&doublelist);
        Lista_next(&doublelist);
        Lista_next(&doublelist);
        int size = Lista_size(&doublelist);

        WHEN ("Adiciono um elemento antes do elemento atual") {
            double value = 100;
            Lista_insertBefore(&doublelist, &value);

            THEN ("O tamanho da lista aumentou em um elemento") {
                REQUIRE (size + 1 == Lista_size(&doublelist));
            }
            AND_THEN("O terceeiro elemento tem o valor 100") {
                double value;
                Lista_first(&doublelist);
                Lista_next(&doublelist);
                Lista_next(&doublelist);
                Lista_current(&doublelist, &value);
                REQUIRE(100 == value);
            }
        }
    }
}

SCENARIO("Insere elementos antes do atual numa lista de string.", "[InsertBeforeString]") {
    GIVEN("Uma lista inicializada com valores e posicionada no primeiro elemento.") {
        const char* names[] = {"a", "b", "c", "d", "e"};
        Lista strlist;
        Lista_new(&strlist, sizeof(char*), free);
        for (int i = 0; i < 5; i += 1) {
            Lista_pushBack(&strlist, strdup(names[i]));
        }
        int size = Lista_size(&strlist);
        Lista_first(&strlist);

        WHEN ("Adiciono um elemento antes do elemento atual") {
            char* value = strdup("Novo");
            Lista_insertBefore(&strlist, &value);

            THEN ("O tamanho da lista aumentou em um elemento") {
                REQUIRE (size + 1 == Lista_size(&strlist));
            }
            AND_THEN("O primeiro elemento tem o valor 'Novo'") {
                char* value;
                Lista_first(&strlist);
                Lista_current(&strlist, &value);
                REQUIRE(strcmp(value, "Novo"));
            }
        }
    }
    GIVEN("Uma lista inicializada com valores e posicionada no terceiro elemento.") {
        const char* names[] = {"a", "b", "c", "d", "e"};
        Lista strlist;
        Lista_new(&strlist, sizeof(char*), free);
        for (int i = 0; i < 5; i += 1) {
            Lista_pushBack(&strlist, strdup(names[i]));
        }
        int size = Lista_size(&strlist);
        Lista_first(&strlist);
        Lista_next(&strlist);
        Lista_next(&strlist);

        WHEN ("Adiciono um elemento antes do elemento atual") {
            char* value = strdup("Novo");
            Lista_insertBefore(&strlist, &value);

            THEN ("O tamanho da lista aumentou em um elemento") {
                REQUIRE (size + 1 == Lista_size(&strlist));
            }
            AND_THEN("O terceeiro elemento tem o valor 100") {
                char* value;
                Lista_first(&strlist);
                Lista_next(&strlist);
                Lista_next(&strlist);
                Lista_current(&strlist, &value);
                REQUIRE(strcmp(value, "Novo"));
            }
        }
    }
}
*/
