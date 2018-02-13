CFLAGS = -g -Wall -I.
DBG_CFLAGS = $(CFLAGS) -D DEBUG=1
CC = gcc 
SRC = dispatcher.c 
TEST_SRC = $(SRC) tests.c
TARGET = dispatcher

all: $(TARGET)

$(TARGET): $(TARGET).c
	@$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
	@echo "Compilation complete"

run:
	./dispatcher

test:
	@$(CC) $(CFLAGS) -o $(TARGET) $(TEST_SRC)
	@echo "Compilation complete"
	./dispatcher

debug:
	@$(CC) $(DBG_CFLAGS) -o $(TARGET) $(TEST_SRC)
	@echo "Compilation complete"
	./dispatcher

clean:
	rm -rf dispatcher dispatcher.o test.o
