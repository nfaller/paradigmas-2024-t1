USER_FILES = src/lista.c

tests = \
	ListCreateDelete \
	ListInfo \
	ListPush \
	ListSearchRemove \
	ListIterator

tests_extra = DoubleListTests

TESTS = $(addprefix features/,$(tests))
TESTS_EXTRA = $(addprefix features/,$(tests_extra))

targets: $(TESTS) $(TESTS_EXTRA)

all: targets test memtest

test:
	@features/utils/bdd_test.sh $(TESTS)

test_extra: $(TESTS_EXTRA)
	@features/utils/bdd_test.sh $(TESTS_EXTRA)
	@features/utils/memtest.sh $(TESTS_EXTRA)

memtest:
	@features/utils/memtest.sh $(TESTS)

all_tests:
	@features/utils/bdd_test.sh $(patsubst %.cpp,%,$(wildcard features/*.cpp))

clean:
	$(RM) $(TESTS) $(TESTS_EXTRA) main features/*.o{,pp} src/*.o{,pp}

.PHONY: all clean tests test_extra memtest all_tests list

include Makefile.rules

