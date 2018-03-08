
	common_sources= ESD_Project.c\
			ESD_Buffer_Handling.c				
	
	common_includes= -I ../include/common

	common_flags=	$(defined) \
			-Wall \
			-Werror \
			-g \
			-O0 \
			-std=c99 \
			-DVERBOSE \
	       		-lc

	objdir=../object
	srcdir=../src
	bindir=../bin
	asmdir=../asm
	depdir=../dep
	headdir=../header

	CC=gcc
	flags=	$(common_flags)
	sources =	$(common_sources)
	includes =	$(common_includes)
	objects:= $(sources:.c=.o)
	deps:= $(sources:.c=.d)		

.PHONY:	compile-all \
	clean \
	build \
	upload\

%.i:%.c	
	$(CC)	$(flags)	$(includes)	-S	$<	-o	$@

%.asm:%.c	
	$(CC)	$(flags)	$(includes)	-S	$<	-o	$@

%.o:%.c	
	$(CC)	$(flags)	$(includes)	-c	$<	-o	$@

%.o:%.s	
	$(CC)	$(flags)	$(includes)	-c	$<	-o	$@

%.d:%.c	
	$(CC)	$(flags)	$(includes)	-M	$<	-o	$@	

%.d:%.s	
	$(CC)	$(flags)	$(includes)	-M	$<	-o	$@

build:	$(objects)	$(deps)
	$(CC)	$(flags)	$(includes)	-o	ESD_lab3.elf	$(objects)

compile-all:	$(objects) 

upload: 
	scp	project3.elf	root@192.168.7.2:~/home

clean :
	rm	-f	*.o	*.s	*.i	*.o	*.d	*.elf *.swp
