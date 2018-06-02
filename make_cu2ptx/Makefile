SRCS=main.cu kernels.cu
OBJS=$(SRCS:.cu=.o)
BIN=app.out
ARCH=sm_50

CXX_FLAGS=-std=c++14,-Wall,-Werror,-Wextra,-g3,-O0

all: $(BIN)

$(BIN): $(OBJS)
	nvcc --gpu-architecture=$(ARCH) $(OBJS) -o $(BIN)

main.o: main.cu
	nvcc --gpu-architecture=$(ARCH) -Xcompiler $(CXX_FLAGS) -I. -dc main.cu -o main.o

#kernels.o: kernels.cu
#	nvcc --gpu-architecture=$(ARCH) -Xcompiler $(CXX_FLAGS) -I. -dc kernels.cu -o kernels.o



kernels.ptx: kernels.cu
	nvcc --gpu-architecture=$(ARCH) --ptx -dc kernels.cu -o kernels.ptx

kernels.o: kernels.ptx
	nvcc --gpu-architecture=$(ARCH) -dc kernels.ptx -o kernels.o


clean:
	rm -f $(OBJS) $(BIN)
