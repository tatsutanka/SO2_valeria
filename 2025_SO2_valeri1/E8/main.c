#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

// Função para imprimir permissões no formato rwxrwxrwx
void print_permissions(mode_t mode) {
  printf("Permissões: ");
  // Dono
  printf((mode & S_IRUSR) ? "r" : "-");
  printf((mode & S_IWUSR) ? "w" : "-");
  printf((mode & S_IXUSR) ? "x" : "-");
  // Grupo
  printf((mode & S_IRGRP) ? "r" : "-");
  printf((mode & S_IWGRP) ? "w" : "-");
  printf((mode & S_IXGRP) ? "x" : "-");
  // Outros
  printf((mode & S_IROTH) ? "r" : "-");
  printf((mode & S_IWOTH) ? "w" : "-");
  printf((mode & S_IXOTH) ? "x" : "-");
  printf("\n");
}

// Função para determinar o tipo do arquivo
void print_file_type(mode_t mode) {
  printf("Tipo: ");
  if (S_ISREG(mode))
    printf("Arquivo regular\n");
  else if (S_ISDIR(mode))
    printf("Diretório\n");
  else if (S_ISLNK(mode))
    printf("Link simbólico\n");
  else if (S_ISCHR(mode))
    printf("Dispositivo de caractere\n");
  else if (S_ISBLK(mode))
    printf("Dispositivo de bloco\n");
  else if (S_ISFIFO(mode))
    printf("FIFO/Pipe\n");
  else if (S_ISSOCK(mode))
    printf("Socket\n");
  else
    printf("Desconhecido\n");
}

int main(int argc, char *argv[]) {
  struct stat info;

  if (argc < 2) {
    fprintf(stderr, "Uso: %s <arquivo1> <arquivo2> ...\n", argv[0]);
    return 1;
  }

  // Itera sobre todos os arquivos passados como argumento
  for (int i = 1; i < argc; i++) {
    printf("=== %s ===\n", argv[i]);

    // Usa lstat para lidar com links simbólicos corretamente
    if (lstat(argv[i], &info) == -1) {
      perror("Erro ao obter informações");
      continue;
    }

    // Exibe tamanho
    printf("Tamanho: %lld bytes\n", (long long)info.st_size);

    // Exibe tipo do arquivo
    print_file_type(info.st_mode);

    // Exibe permissões
    print_permissions(info.st_mode);

    printf("\n");
  }

  return 0;
}
