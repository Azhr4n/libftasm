nasm -f macho64 ft_isalpha.s -o ft_isalpha.o
gcc -c test.c -I includes
gcc *.o
./a.out