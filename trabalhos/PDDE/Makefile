CFLAGS_OBJS = -Wall -g
CFLAGS_COMP = -Wall -g

BIN_PATH=bin/
LINKS_PATH=links/
SRC_PATH=src/

# Essa função dá o erro
$(LINKS_PATH)%.o:$(SRC_PATH)%.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS_OBJS) $< -lm -o $@ 

rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

SRCS = $(call rwildcard, src/, *.c)

TARGET = $(BIN_PATH)trabalho_eda

OBJS = $(patsubst $(SRC_PATH)%.c, $(LINKS_PATH)%.o, $(SRCS))

# A compilação usa SRCS pelo fato de erros com dependêcias
# Seria interessante que fosse criado os objetos antes da compilção,
# mas o fato dele tentar criar o main antes das depências impede isso
$(TARGET): $(SRCS)
	mkdir -p $(BIN_PATH)
	gcc $(CFLAGS_COMP) $^ -lm -o $@ 

all: $(TARGET)
	@echo "Compilação terminada com sucesso :)"
