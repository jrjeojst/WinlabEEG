CC=gcc
TARGET=emo-read
INPUT_SRCS=emo-read.c
INPUT_OBJS=$(INPUT_SRCS:.c=.o)

CFLAGS=-I /usr/include/openssl/ -o $(TARGET)
DEBUG=-g
LIBS=-lcrypto -ludev

all: $(INPUT_OBJS)
	$(CC) $(CFLAGS) $(LIBS) $^

debug: $(INPUT_OBJS)
	$(CC) $(DEBUG) $(CFLAGS) $(LIBS) $^

clean:
	rm -f $(TARGET) $(INPUT_OBJS)

