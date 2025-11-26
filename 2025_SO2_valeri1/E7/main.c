#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd;

  if (argc < 2) {
    fprintf(stderr, "Uso: %s <arquivo>\n", argv[0]);
    return 1;
  }

  // Abre o arquivo para leitura e escrita
  fd = open(argv[1], O_RDWR);
  if (fd == -1) {
    perror("Erro ao abrir arquivo");
    return 1;
  }

  // Move o ponteiro para o byte 20
  if (lseek(fd, 20, SEEK_SET) == -1) {
    perror("Erro no lseek");
    close(fd);
    return 1;
  }

  // Escreve "FIM\n" a partir do byte 20
  if (write(fd, "FIM\n", 4) == -1) {
    perror("Erro ao escrever");
    close(fd);
    return 1;
  }

  // Trunca o arquivo no byte atual (após "FIM\n")
  if (ftruncate(fd, lseek(fd, 0, SEEK_CUR)) == -1) {
    perror("Erro ao truncar arquivo");
    close(fd);
    return 1;
  }

  printf("Arquivo truncado e atualizado com sucesso!\n");

  close(fd);
  return 0;
}
