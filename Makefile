SOURCE-UTILS := $(wildcard utils/*.c)
SOURCE-SMTP := $(wildcard smtp/*.c)

deploy: build clean

build: main.c utils smtp
	clang main.c \
		${SOURCE-UTILS:utils/*.c=./*.o} \
		${SOURCE-SMTP:smtp/*.c=./*.o} \
		-I. -o server

utils : $(SOURCE-UTILS)
	clang -c $(SOURCE-UTILS) -Iutils -I.

smtp : $(SOURCE-SMTP)
	clang -c $(SOURCE-SMTP) -Ismtp -I.

clean:
	rm *.o
