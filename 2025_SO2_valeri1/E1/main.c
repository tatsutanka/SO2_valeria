#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("ERRO, formato %s,<Nome Arquivo>", argv[0]);
    return 0;
  }
  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    printf("The file is not opened");
    return 0;
  }

  off_t contador = lseek(fd, 0, SEEK_END);
  printf("contafor =%ld\n", contador);
  close(fd);
  return EXIT_SUCCESS;
}
