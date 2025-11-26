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
  unsigned char byte;
  off_t tamanho, pos = 0;
  long long contador = 0;
  struct stat info;

  if (argc < 2) {
    fprintf(stderr, "Uso: %s <arquivo_binario>\n", argv[0]);
    return 1;
  }

  // Abre o arquivo binário para leitura
  fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("Erro ao abrir arquivo");
    return 1;
  }

  // Descobre o tamanho do arquivo usando stat()
  if (fstat(fd, &info) == -1) {
    perror("Erro ao obter tamanho do arquivo");
    close(fd);
    return 1;
  }
  tamanho = info.st_size;

  // Percorre o arquivo byte a byte usando lseek()
  while (pos < tamanho) {
    // Move o ponteiro do arquivo para a posição atual
    if (lseek(fd, pos, SEEK_SET) == -1) {
      perror("Erro no lseek");
      close(fd);
      return 1;
    }

    // Lê um único byte
    if (read(fd, &byte, 1) != 1) {
      perror("Erro na leitura do byte");
      close(fd);
      return 1;
    }

    // Verifica se o byte é nulo
    if (byte == '\0') {
      contador++;
    }

    pos++;
  }

  printf("Total de bytes nulos encontrados: %lld\n", contador);

  close(fd);
  return 0;
}
