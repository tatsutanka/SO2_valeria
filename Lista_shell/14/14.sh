#!/bin/bash

ARQUIVO="./ideias.txt"

# Verifica se a ideia foi informada
if [ $# -eq 0 ]; then
  echo "Uso: $0 \"sua ideia aqui\""
  exit 1
fi

# Junta todos os argumentos como uma única ideia
IDEIA="$*"

# Captura data e hora no formato DD/MM/AAAA HH:MM
DATA_HORA=$(date "+%d/%m/%Y %H:%M")

# Grava no arquivo
echo "$DATA_HORA $IDEIA" >>"$ARQUIVO"

echo "Ideia adicionada com sucesso!"
