#!/bin/bash

# Verifica se o usuário passou um arquivo
if [ -z "$1" ]; then
  echo "Uso: $0 arquivo"
  exit 1
fi

ARQ="$1"

# Verifica se o arquivo existe
if [ ! -f "$ARQ" ]; then
  echo "Erro: '$ARQ' não é um arquivo válido."
  exit 1
fi

# Usa wc para contar linhas e palavras
LINHAS=$(wc -l <"$ARQ")
PALAVRAS=$(wc -w <"$ARQ")

echo "Arquivo: $ARQ"
echo "Número de linhas: $LINHAS"
echo "Número de palavras: $PALAVRAS"
