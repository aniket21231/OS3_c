obj-m +=ass3_c.o
all:
	make -C/lib/modules/$(shell uname -r)/build M=$(PWD)modules
clean:
	make -C/lib/modules/$(shell uname -r)/build M=$(PWD) clean
