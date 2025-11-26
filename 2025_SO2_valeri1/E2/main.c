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
  // abrir o aquivo
  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    printf("The file is not opened");
    return 0;
  }

  char palavra[101];
  char palavra2[101];

  read(fd, palavra, 100);
  printf("palavra:%s\n", palavra);

  if (lseek(fd, 200, SEEK_SET) == -1) {
    perror("Erro no lseek");
    close(fd);
    return 1;
  }

  read(fd, palavra2, 50);
  printf("palavra2=%s\n", palavra2);
  close(fd);
  return EXIT_SUCCESS;
}
