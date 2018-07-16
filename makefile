IDIR = include
SDIR = sources
ODIR = obj

_DEPS = data_parser.hpp image.hpp image_container.hpp literals.hpp
_OBJ = data_parser.o image.o image_container.o literals.o main.o

CC = g++
CFLAGS = -O2 -Wall -Wno-reorder -std=c++11 -I$(IDIR)


DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 