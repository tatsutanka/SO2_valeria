#include <dirent.h>
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

int diretorio_vazio(const char *caminho) {
  struct dirent *entrada;
  DIR *dir = opendir(caminho);
  if (dir == NULL) {
    perror("Não foi possível abrir o diretório");
    return -1; // erro
  }

  while ((entrada = readdir(dir)) != NULL) {
    // Ignora "." e ".."
    if (strcmp(entrada->d_name, ".") != 0 &&
        strcmp(entrada->d_name, "..") != 0) {
      closedir(dir);
      return 0; // Não está vazio
    }
  }

  closedir(dir);
  return 1; // Vazio
}

int main(int argc, char *argv[]) {

  if (argc < 2) {
    fprintf(stderr, "Uso: %s <Caminho para navegar um subdiretorio>\n",
            argv[0]);
    return 1;
  }

  const char *pasta = "./teste";

  int resultado = diretorio_vazio(pasta);
  if (resultado == 1) {
    printf("O diretório está vazio.\n");
  } else if (resultado == 0) {
    printf("O diretório NÃO está vazio.\n");
  } else {
    printf("Erro ao acessar o diretório.\n");
  }

  return 0;
}
