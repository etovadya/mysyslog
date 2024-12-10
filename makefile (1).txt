CC = gcc
CFLAGS = -Wall -g -I/home/oleg/mysyslog1/libmysyslog -I/homr/oleg/mysyslog1/libmysyslog-text -I/home/oleg/mysyslog1/libmysyslog-json
LDFLAGS = -L/home/oleg/mysyslog1/libmysyslog -L/home/oleg/mysyslog1/libmysyslog-text -L/home/oleg/mysyslog1/libmysyslog-json -lmysyslog -lmysyslog-text -lmysyslog-json -ldl

all: mysyslog-client

mysyslog-client: mysyslog-client.o
	$(CC) -o $@ $^ $(LDFLAGS)

mysyslog-client.o: mysyslog-client.c
	$(CC) $(CFLAGS) -c $<

run: mysyslog-client
	./mysyslog-client

clean:
	rm -f mysyslog-client *.o
