CC=gcc
AR=ar

FLAGS=-Wall -g

GRAPH_FILES=my_mat.c my_mat.h
RUN_GRAPH_FILES=my_graph.c my_mat.h
MAIN_FILES=my_graph.o my_mat.a

all: my_graph my_Knapsack libmymat 

my_Knapsack: my_Knapsack.o
	$(CC) $(FLAGS) -o $@ $^

my_Knapsack.o: my_Knapsack.c
	$(CC) $(FLAGS) -c my_Knapsack.c -o $@

my_graph: my_graph.o my_mat.a
	$(CC) $(FLAGS) -o $@ $^

my_graph.o: $(RUN_GRAPH_FILES)
	$(CC) $(FLAGS) -c my_graph.c -o $@

libmymat: my_mat.a
my_mat.a : my_mat.o  
	$(AR) -rcs $@ $^

my_mat.o: $(GRAPH_FILES)
	$(CC) $(FLAGS) -c my_mat.c -o $@

.PHONY: clean all

clean:
	rm -f *.o *.a *.so *.gch my_graph my_Knapsack libmymat