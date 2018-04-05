SOURCE-SMTP := $(wildcard smtp/*.c)

deploy: build clean

build: main.c smtp
	clang main.c ${SOURCE-SMTP:smtp/*.c=./*.o} \
		-I. -o server

smtp : $(SOURCE-SMTP)
	clang -c $(SOURCE-SMTP) -Ismtp

clean:
	rm *.o
