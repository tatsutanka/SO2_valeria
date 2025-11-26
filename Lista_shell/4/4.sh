#!/bin/bash

# Verifica se o usuário passou um argumento
if [ -z "$1" ]; then
  echo "Uso: $0 nome_do_arquivo"
  exit 1
fi

ARQ="$1"

# Verifica se o arquivo existe
if [ ! -e "$ARQ" ]; then
  echo "O arquivo '$ARQ' NÃO existe."
  exit 1
fi

# Obtém o tamanho do arquivo em bytes usando stat (compatível com Linux)
TAM=$(stat -c%s "$ARQ")

echo "Tamanho do arquivo: $TAM bytes"

# Verifica se é maior que 100
if [ "$TAM" -gt 100 ]; then
  echo "O arquivo é maior que 100 bytes."
else
  echo "O arquivo NÃO é maior que 100 bytes."
fi
