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

  if (argc < 2) {
    fprintf(stderr, "Uso: %s <Arquivos a serem criados>\n", argv[0]);
    return 1;
  }
  int status;
  for (int i = 0; i < argc - 1; i++) {
    status = mkdir(argv[i + 1], 0755);
    printf("-------------------\n");
    if (status == 0) {
      printf("status: successo\n");
    } else {
      printf("status: ERRO\n");
    }

    printf("path: %s\n", argv[i + 1]);
  }
  return 0;
}
