CC=gcc
AR=ar

FLAGS=-Wall -g

GRAPH_FILES=my_mat.c my_mat.h
RUN_GRAPH_FILES=my_graph.c my_mat.h
MAIN_FILES=my_graph.o my_mat.a

all: connections libmymat 

connections: $(MAIN_FILES) 
	$(CC) $(FLAGS) -o $@ $^

libmymat: my_mat.a
my_mat.a : my_mat.o  
	$(AR) -rcs $@ $^

my_graph.o: $(RUN_GRAPH_FILES)
	$(CC) $(FLAGS) -c my_graph.c -o $@

my_mat.o: $(GRAPH_FILES)
	$(CC) $(FLAGS) -c my_mat.c -o $@

my_graph: my_graph.o my_mat.o
	$(CC) $(FLAGS) -o $@ $^

.PHONY: clean all

clean:
	rm -f *.o *.a *.so *.gch connections my_graph