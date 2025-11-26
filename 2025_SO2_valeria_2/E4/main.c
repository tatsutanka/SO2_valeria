
#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int mkdir_p(const char *caminho, mode_t mode) {
  char temp[1024];
  char *p = NULL;
  size_t len;

  snprintf(temp, sizeof(temp), "%s", caminho);
  len = strlen(temp);

  // Remove "/" do final se houver
  if (temp[len - 1] == '/')
    temp[len - 1] = '\0';

  for (p = temp + 1; *p; p++) {
    if (*p == '/') {
      *p = '\0'; // corta a string aqui

      // cria diretório até aqui
      if (mkdir(temp, mode) != 0) {
        perror("mkdir");
        return -1;
      }

      *p = '/'; // restaura a barra
    }
  }

  // cria diretório final
  if (mkdir(temp, mode) != 0) {
    perror("mkdir");
    return -1;
  }

  return 0;
}

int main(int argc, char *argv[]) {

  if (argc < 2) {
    fprintf(stderr,
            "Uso: %s <caminho de subdiretorio a ser criado recuso=ivamente>\n",
            argv[0]);
    return 1;
  }
  int status;
  chdir(argv[1]);
  if (mkdir_p(argv[1], 0755) == 0) {
    printf("Diretórios criados com sucesso!\n");
  } else {
    printf("Erro ao criar diretórios.\n");
  }

  return 0;
}
