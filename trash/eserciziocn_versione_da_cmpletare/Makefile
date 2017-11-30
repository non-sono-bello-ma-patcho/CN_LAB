CC = gcc
CC1 = g++
CFLAGS = -Wall 

TRASH_DIR = trash
BIN_DIR = bin
CODICE_DIR = codice
LIB_DIR = lib

ESERCIZIO1A = $(BIN_DIR)/esercizio1a.out
ESERCIZIO1B = $(BIN_DIR)/esercizio1b.out
ESERCIZIO1C = $(BIN_DIR)/esercizio1c.out

EXE_ESERCIZIO1 = $(ESERCIZIO1A) $(ESERCIZIO1B) $(ESERCIZIO1C)
EXE_ESERCIZIO2 = $(BIN_DIR)/esercizio2_autorun.out
EXE_ESERCIZIO3 = $(BIN_DIR)/main.out
EXEC = $(EXE_ESERCIZIO2) $(EXE_ESERCIZIO1) $(EXE_ESERCIZIO3)

DEPENDENCY1 = $(CODICE_DIR)/es1a.cpp $(CODICE_DIR)/es1b.cpp $(CODICE_DIR)/es1c.cpp

DEPENDENCY2 = $(CODICE_DIR)/esercizio2_autorun.c $(CODICE_DIR)/auto_creazione_dati_matrice.c $(CODICE_DIR)/debug_functions.c $(CODICE_DIR)/fill_mv.c $(CODICE_DIR)/gauss_moves.c $(CODICE_DIR)/init_mv.c $(CODICE_DIR)/perturbatore_vettore.c $(LIB_DIR)/auto_creazione_dati_matrice.h $(LIB_DIR)/fill_mv.h $(LIB_DIR)/gauss_moves.h $(LIB_DIR)/init_mv.h $(LIB_DIR)/output_type.h $(LIB_DIR)/perturbatore_vettore.h

DEPENDENCY3 = $(CODICE_DIR)/main.c 

all: $(EXEC)


$(EXE_ESERCIZIO1): $(DEPENDENCY1) $(DEPENDENCY2) $(DEPENDENCY3); $(CC1) $(CFLAG)  $(CODICE_DIR)/es1a.cpp -o $(ESERCIZIO1A) ; $(CC1) $(CODICE_DIR)/es1b.cpp -o $(ESERCIZIO1B) ; $(CC1) $(CODICE_DIR)/es1c.cpp -o $(ESERCIZIO1C) 
                                                                                                                                                                                                                         
$(EXE_ESERCIZIO2): $(DEPENDENCY2) $(DEPENDENCY1) $(DEPENDENCY3) ; $(CC) $(CFLAGS) $(DEPENDENCY2) -o $(EXE_ESERCIZIO2)                    

$(EXE_ESERCIZIO3): $(DEPENDENCY3) $(DEPENDENCY2)  $(DEPENDENCY1); $(CC) $(CFLAGS) $(DEPENDENCY3) -o $(EXE_ESERCIZIO3)
    

#clean: $(EXE_ESERCIZIO3) $(EXE_ESERCIZIO2)                                                                                                                                                                                                                                 mv -d  $(BIN_DIR)/file_matrice trash/ mv -d  $(BIN_DIR)/file_vettore trash/ mv -d  $(BIN_DIR)/main.out trash/ mv -d  $(BIN_DIR)/esercizio2_autorun.out trash/ mv -d  $(BIN_DIR)/esercizio1_autorun.out trash/#
