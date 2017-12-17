CC = gcc
CC1 = g++
CFLAGS = -Wall -o
OFLAG = -Ilib -c ${CFLAGS}


TRASH_DIR = trash
BIN_DIR = bin
O_DIR = objfiles
CODICE_DIR = codice
LIB_DIR = lib
SL = $(O_DIR)/libcn.a
LDFLAGS = -L$(O_DIR) -lcn -lrt
E2OBJS = $(O_DIR)/auto_creazione_dati_matrice.o $(O_DIR)/gauss_moves.o $(O_DIR)/init_mv.o $(O_DIR)/perturbatore_vettore.o $(O_DIR)/fill_mv.o

all: EXEC_1 EXEC_2 EXEC_3 | $(BIN_DIR)

#creating static library:
$(SL): $(E2OBJS) | $(O_DIR) # $(O_DIR)/output_type.o
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

$(O_DIR)/esercizio2_autorun.o: codice/esercizio2_autorun.c | objfiles
	gcc $(OFLAG) $@ $<

#$(O_DIR)/output_type.o: codice/output_type.c lib/output_type.h | objfiles
#	gcc $(OFLAG) $@ $<

$(O_DIR)/fill_mv.o: codice/fill_mv.c lib/fill_mv.h | objfiles
	gcc $(OFLAG) $@ $<

# creating directories
$(O_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

#
# ESERCIZIO 1
#

EXEC_1: $(BIN_DIR)/es1a.out $(BIN_DIR)/es1b.out $(BIN_DIR)/es1c.out | $(BIN_DIR) 

# esercizio 1a:
$(BIN_DIR)/es1a.out: codice/es1a.cpp | $(BIN_DIR)
	g++ $(CFLAGS) $@ $<

#esercizio 1b:
$(BIN_DIR)/es1b.out: codice/es1b.cpp | $(BIN_DIR)
	g++ $(CFLAGS) $@ $<

# esercizio 1c;
$(BIN_DIR)/es1c.out: codice/es1c.cpp | $(BIN_DIR)
	g++ $(CFLAGS) $@ $<

#
# ESERCIZIO 2
#

EXEC_2: $(BIN_DIR)/es2.out | $(BIN_DIR)

$(BIN_DIR)/es2.out: $(O_DIR)/esercizio2_autorun.o $(SL)  | $(BIN_DIR)
	gcc $(LDFLAGS) -o $@

#
# ESERCIZIO 3
#

EXEC_3: $(BIN_DIR)/es3.out | $(BIN_DIR)

$(BIN_DIR)/es3.out: codice/main.c | $(BIN_DIR)
	gcc $(CFLAGS) $@ $<


#clean directory from unuseful files:
clean:
	rm -rf $(O_DIR)
	rm -rf $(BIN_DIR)
