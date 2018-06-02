CC_SRCS=logger.cc
CU_SRCS=main.cu particle.cu vector3.cu
CC_OBJS=$(CC_SRCS:.cc=.o)
CU_OBJS=$(CU_SRCS:.cu=.o)
OBJS=$(CC_OBJS) $(CU_OBJS)
BIN=app.out
ARCH=compute_32

CXX_FLAGS=-std=c++14,-Wall,-Werror,-Wextra,-g3,-O0

all: $(BIN)

$(BIN): $(OBJS)
	nvcc -arch=$(ARCH) $(OBJS) -o $(BIN)

%.o: %.cc
	nvcc -arch=$(ARCH) -Xcompiler $(CXX_FLAGS) -I. -dc $< -o $@

%.o: %.cu
	nvcc -arch=$(ARCH) -Xcompiler $(CXX_FLAGS) -I. -dc $< -o $@

clean:
	rm -f $(OBJS) $(BIN)
