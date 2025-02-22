CC = clang
LD = clang

CCFLAGS += -std=c17
CCFLAGS += -Wall
CCFLAGS += -Wpedantic

LDFLAGS += -std=c17

list: list.o demo.o
	@echo "LD    $^"
	@$(LD) $(LDFLAGS) $^ -o $@
	@echo "EXE   $@"

list.o: list.c list.h
	@echo "CC    $<"
	@$(CC) $(CCFLAGS) -c $< -o $@

demo.o: demo.c list.h
	@echo "CC    $<"
	@$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@rm -rf *.o list
