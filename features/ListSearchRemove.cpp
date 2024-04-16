/* SPDX-License-Identifer: MIT */

#if defined(GITHUB_WORKFLOW) && GITHUB_WORKFLOW == 1
    #include <catch2/catch.hpp>
#else
    #include <catch2/catch_test_macros.hpp>
#endif /* GITHUB_WORKFLOW */

#include <stdlib.h>
#include <string.h>

#include "lista.h"

int int_cmp(void *a, void *b) {
    return *(int*)a - *(int*)b;
}

int double_cmp(void *a, void *b) {
    double lhs = *(double*)a;
    double rhs = *(double*)b;
    if (lhs > rhs) { return 1; }
    if (lhs < rhs) { return -1; }
    return 0;
}

int string_cmp(void* a, void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

SCENARIO("Procura por elementos em uma lista de inteiros", "[SearchIntFail]") {
    GIVEN("Uma lista inicializada com elementos.") {
        Lista intlist;
        Lista_new(&intlist, sizeof(int), NULL);

        for(int i = 0; i < 5; i++) {
            Lista_pushBack(&intlist, &i);
        }

        WHEN ("Procuro por um valor que não está na lista.") {
            int needle = -1;
            int value;
            int encontrado = Lista_search(&intlist, &needle, &value, int_cmp);
            
            THEN ("O valor não foi encontrado.") {
                REQUIRE (false == bool(encontrado));
            }
        }

        Lista_delete(&intlist);
    }
}

/*

SCENARIO("Procura por elementos em uma lista de inteiros", "[SearchInt]") {
    GIVEN("Uma lista inicializada com elementos.") {
        Lista intlist;
        Lista_new(&intlist, sizeof(int), NULL);

        for(int i = 0; i < 5; i++) {
            Lista_pushBack(&intlist, &i);
        }

        int int_needle[] = {0, 2, 4};
        for (int i = 0; i < 3; i++) { 
            int value;
            int* esperado = int_needle + i;
            
            WHEN ("Procuro pelo valor " << *esperado << " na lista") {
                int encontrado = Lista_search(&intlist, esperado, &value, int_cmp);
                
                THEN ("O valor foi encontrado.") {
                    REQUIRE (true == bool(encontrado));
                    AND_THEN("E o valor da variável de retorno é o esperado.") {
                        REQUIRE (*esperado == value);
                    }
                }
            }
        }

        Lista_delete(&intlist);
    }
}

SCENARIO("Procura por elementos em uma lista de doubles", "[SearchDoubleFail]") {
    GIVEN("Uma lista inicializada com elementos.") {
        Lista doublelist;
        Lista_new(&doublelist, sizeof(double), NULL);

        for(double i = 0; i < 5; i++) {
            Lista_pushBack(&doublelist, &i);
        }
        WHEN ("Procuro por um valor que não está na lista.") {
            double original = -1;
            double value = original;
            double encontrado = Lista_search(&doublelist, &original, &value, double_cmp);
            
            THEN ("O valor não foi encontrado.") {
                REQUIRE (false == bool(encontrado));
            }
        }
        Lista_delete(&doublelist);
    }
} 

SCENARIO("Procura por elementos em uma lista de doubles", "[SearchDouble]") {
    GIVEN("Uma lista inicializada com elementos.") {
        Lista doublelist;
        Lista_new(&doublelist, sizeof(double), NULL);

        for(double i = 0; i < 5; i++) {
            Lista_pushBack(&doublelist, &i);
        }

        double double_needle[] = {0, 2, 4};
        for (int i = 0; i < 3; i++) { 
            double value;
            double *esperado = double_needle + i;
            
            WHEN ("Procuro pelo valor " << *esperado << " na lista") {
                int encontrado = Lista_search(&doublelist, esperado, &value, double_cmp);
                
                THEN ("O valor foi encontrado.") {
                    REQUIRE (true == bool(encontrado));
                    
                    AND_THEN("E o valor da variável de retorno é o esperado.") {
                        REQUIRE (*esperado == value);
                    }
                }
            }
        }
        
        Lista_delete(&doublelist);
    }
}

SCENARIO("Procura por elementos em uma lista de strings", "[SearchStringFail]") {
    GIVEN("Uma lista inicializada com elementos.") {
        Lista strlist;
        Lista_new(&strlist, sizeof(char*), free);

        const char* names[] = {"a", "b", "c", "d", "e"};
        for(int i = 0; i < 5; i++) {
            Lista_pushBack(&strlist, &(names[i]));
        }

        WHEN ("Procuro por um valor que não está na lista.") {
            const char* original = "z";
            char* value;
            int encontrado = Lista_search(&strlist, &original, &value, string_cmp);
            
            THEN ("O valor não foi encontrado.") {
                REQUIRE (false == bool(encontrado));
            }
        }
        Lista_delete(&strlist);
    }
}


SCENARIO("Procura por elementos em uma lista de strings", "[SearchString]") {
    GIVEN("Uma lista inicializada com elementos.") {
        Lista strlist;
        Lista_new(&strlist, sizeof(char*), free);

        const char* names[] = {"a", "b", "c", "d", "e"};
        for(int i = 0; i < 5; i++) {
            Lista_pushBack(&strlist, &(names[i]));
        }

        const char* str_needle[] = {"a", "c", "d"};
        for (int i = 0; i < 3; i++) { 
            const char* original = "z";
            char* value;
            const char** esperado = str_needle + i;
            
            WHEN ("Procuro pelo valor " << *esperado << " na lista") {
                int encontrado = Lista_search(&strlist, esperado, &value, string_cmp);
                
                THEN ("O valor foi encontrado.") {
                    REQUIRE (true == bool(encontrado));
                    AND_THEN("E o valor da variável de retorno é o esperado.") {
                        REQUIRE (strcmp(value, *esperado) == 0);
                    }
                }
            }
        }
        Lista_delete(&strlist);
    }
}

*/
