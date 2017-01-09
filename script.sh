nasm -f macho64 ft_isascii.s -o ft_isascii.o
gcc -c test.c -I includes
gcc *.o
./a.out