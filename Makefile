CC = gcc

CFLAGS += -Wall -Wextra  

DEPS += include/list.h

OBJFILES = src/main.o src/read_map.o src/utility.o\
						src/my_mouse.o src/rewrite_map.c\


TARGET = my_mouse

all: $(TARGET)

$(TARGET): $(OBJFILES) $(DEPS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

.PHONY: clean
clean:
	rm -f src/*.o *.out $(TARGET)
