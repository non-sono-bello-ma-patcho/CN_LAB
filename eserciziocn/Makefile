CC = gcc
CC1 = g++
CFLAGS = -Wall -o
OFLAG = -Ilib -c ${CFLAGS}


TRASH_DIR = trash
BIN_DIR = bin
O_DIR = objfiles
CODICE_DIR = codice
LIB_DIR = lib
SL = $(O_DIR)/system_library.a
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


#creating static library:
$(SL): $(O_DIR)/auto_creazione_dati_matrice.o $(O_DIR)/gauss_moves.o $(O_DIR)/init_mv.o $(O_DIR)/perturbatore_vettore.o $(O_DIR)/output_type.o $(O_DIR)/output_type.o $(O_DIR)/fill_mv.o | $(O_DIR)
ar rcs $@ $(O_DIR)/*.o

# creating object files:
$(O_DIR)/auto_creazione_dati_matrice.o: codice/auto_creazione_dati_matrice.c lib/auto_creazione_dati_matrice.h | objfiles
	gcc $(OFLAG) $@ $<

$(O_DIR)/gauss_moves.o: codice/gauss_moves.c lib/gauss_moves.h | objfiles
	gcc $(OFLAG) $@ $<

$(O_DIR)/init_mv.o: codice/init_mv.c lib/init_mv.h | objfiles
	gcc $(OFLAG) $@ $<

$(O_DIR)/perturbatore_vettore.o: codice/perturbatore_vettore.c lib/perturbatore_vettore.h | objfiles
	gcc $(OFLAG) $@ $<

$(O_DIR)/output_type.o: codice/output_type.c lib/output_type.h | objfiles
	gcc $(OFLAG) $@ $<

$(O_DIR)/fill_mv.o: codice/fill_mv.c lib/fill_mv.h | objfiles
	gcc $(OFLAG) $@ $<

# creating directories
$(O_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@
                                                                                                                                                                                                                               mv -d  $(BIN_DIR)/file_matrice trash/ mv -d  $(BIN_DIR)/file_vettore trash/ mv -d  $(BIN_DIR)/main.out trash/ mv -d  $(BIN_DIR)/esercizio2_autorun.out trash/ mv -d  $(BIN_DIR)/esercizio1_autorun.out trash/#
