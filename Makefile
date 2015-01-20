# NAME		=	lifbta

all:
	nasm -f macho64 ft_bzero.s
	gcc -c main.c
	ld -e _main -macosx_version_min 10.8 -arch x86_64 main.o ft_bzero.o -lSystem -o loul
