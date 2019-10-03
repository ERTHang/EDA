compile_stack: src/pilha_DDE.c
	mkdir -p links
	gcc -c -g -Wall src/pilha_DDE.c -o links/pilha_DDE.o
compile_trabalho: compile_stack src/trabalho_eda_PDDE.c
	mkdir -p bin
	gcc -g -Wall src/trabalho_eda_PDDE.c links/pilha_DDE.o -o bin/trabalho_eda_PDDE
