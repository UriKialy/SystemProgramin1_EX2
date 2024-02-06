CC=gcc
AR=ar

FLAGS=-Wall -g

DYN_LIB_FLAGS=-shared -fPIC -o 

GRAPH_FILES=my_mat.c my_mat.h
RUN_GRAPH_FILES=my_graph.c my_mat.h

all: connections my_graph libmymat

connections: my_graph.o libmymat
	$(CC) $(FLAGS) -c

libmymat: my_mat.so
my_mat.so : my_mat.o 
	$(CC)  $(DYN_LIB_FLAGS) $  my_mat.c

my_graph.o: $(RUN_GRAPH_FILES)
	$(CC) $(FLAGS) -c  $(RUN_GRAPH_FILES)

my_mat.o: $(GRAPH_FILES)
	$(CC) $(FLAGS) -c $(GRAPH_FILES)
 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so *.gch my_graph