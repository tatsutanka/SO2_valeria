#!/bin/bash

# Verifica se o usuário passou um diretório
if [ -z "$1" ]; then
  echo "Uso: $0 diretório"
  exit 1
fi

DIR="$1"

# Verifica se o argumento é um diretório válido
if [ ! -d "$DIR" ]; then
  echo "Erro: '$DIR' não é um diretório válido."
  exit 1
fi

# Percorre todos os arquivos .mpeg3 do diretório
for ARQ in "$DIR"/*.mpeg3; do
  # Verifica se existe ao menos um arquivo que corresponda ao padrão
  [ -e "$ARQ" ] || {
    echo "Nenhum arquivo .mpeg3 encontrado no diretório."
    exit 0
  }

  # Define o novo nome (trocando a extensão)
  NOVO="${ARQ%.mpeg3}.mp3"

  echo "Renomeando: $ARQ -> $NOVO"
  mv "$ARQ" "$NOVO"
done

echo "Concluído!"
