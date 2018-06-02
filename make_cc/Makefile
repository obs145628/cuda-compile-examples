SRCS=logger.cc main.cc particle.cc vector3.cc
OBJS=$(SRCS:.cc=.o)
BIN=app.out
ARCH=compute_32

all: $(BIN)


$(BIN): $(OBJS)
	nvcc -arch=$(ARCH) $(OBJS) -o $(BIN)

%.o: %.cc
	nvcc -x cu -arch=$(ARCH) -I. -dc $< -o $@

clean:
	rm -f $(OBJS) $(BIN)
