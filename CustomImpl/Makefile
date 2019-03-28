CXX			= g++
CXX_FLAGS	= -Wall -Wextra \
              -O0 \
              -fdump-class-hierarchy-all=main.class \
              -fverbose-asm \
              -save-temps \
              -ggdb

.PHONY all: main

main:
	$(CXX) $(CXX_FLAGS) main.cpp -o main

.PHONY clean:
	$(RM) main
	$(RM) main.class
	$(RM) main.ii
	$(RM) main.s
	$(RM) main.o
