CC = gcc

CFLAGS += -Wall -Wextra -Werror 

DEPS += include/list.h

OBJFILES = src/main.o src/read_map.o src/utility.o\
						src/my_mouse.o #tar_extract.o\
						#tar_append.o tar_update.o tar_list.o


TARGET = my_mouse

all: $(TARGET)

$(TARGET): $(OBJFILES) $(DEPS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

.PHONY: clean
clean:
	rm -f src/*.o *.out $(TARGET)