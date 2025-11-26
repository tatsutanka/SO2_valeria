#!/bin/bash

# Verifica se o usuário passou um argumento
if [ -z "$1" ]; then
  echo "Uso: $0 nome_do_arquivo"
  exit 1
fi

ARQ="$1"

# Testa se o arquivo existe
if [ -e "$ARQ" ]; then
  echo "O arquivo '$ARQ' existe."
else
  echo "O arquivo '$ARQ' NÃO existe."
fi
