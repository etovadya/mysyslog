CC = gcc
CFLAGS = -Wall -g -I/home/oleg/mysyslog1/libmysyslog -I/home/oleg/mysyslog1/libmysyslog-text -I/home/oleg/mysyslog1/libmysyslog-json
LDFLAGS = -L/home/oleg/mysyslog1/libmysyslog -L/home/oleg/mysyslog1/libmysyslog-text -L/home/oleg/mysyslog1/libmysyslog-json -lmysyslog -lmysyslog-text -lmysyslog-json -ldl

all:mysyslog-daemon

mysyslog-daemon: mysyslog-daemon.o
	$(CC) -o $@ $^ $(LDFLAGS)

mysyslog-daemon.o: mysyslog-daemon.c
	$(CC) $(CFLAGS) -c $<

run: mysyslog-daemon
	./mysyslog-daemon

clean:
	rm -f mysyslog-daemon *.o
