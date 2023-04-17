IDIR = include
SDIR = sources
ODIR = obj
BOOST = /opt/local/include

_DEPS = data_container.hpp data_point.hpp mnist_parser.hpp
_OBJ = data_container.o data_point.o mnist_parser.o main.o

CC = g++
CFLAGS = -O2 -Wno-deprecated-declarations -Wno-reorder -std=c++20 -I$(IDIR) -I$(BOOST)


DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: directories

directories:
	mkdir -p $(ODIR)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 