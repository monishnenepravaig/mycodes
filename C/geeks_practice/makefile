	common_sources=	bit_manipulation.c
	
	common_includes = 

	common_flags =	-g \
			-O0 \
			-lpthread\
			-pthread \
			-lrt \
			-lm \
			-lc

	CC=gcc
	flags =	$(common_flags)
	sources =	$(common_sources)
	includes =	$(common_includes)
	objects:= $(sources:.c=.o)
	deps:= $(sources:.c=.d)	

.PHONY:	compile-all \
	clean \
	build \
	upload \
	go \
	run 

build:	bit_manipulation.elf	

%.elf:	$(objects)	$(deps)
	$(CC)	$(flags)	-o	$@	$(objects)	

%.i:%.c		$(includes)
	$(CC)	$(flags)	-S	$<	-o	$@

%.asm:%.c	$(includes)
	$(CC)	$(flags)	-S	$<	-o	$@

%.o:%.c		$(includes)
	$(CC)	$(flags)	-c	$<	-o	$@

%.o:%.s		$(includes)
	$(CC)	$(flags)	-c	$<	-o	$@
	
%.d:%.c		$(includes)
	$(CC)	$(flags)	-M	$<	-o	$@	

%.d:%.s		$(includes)
	$(CC)	$(flags)	-M	$<	-o	$@

compile-all:	$(objects)

clean :
	rm	-f	*.o	*.s	*.i	*.o	*.d	*.elf *.swp
