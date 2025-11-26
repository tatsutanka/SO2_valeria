#!/bin/sh

# Verifica se o usuário passou um arquivo
if [ -z "$1" ]; then
  echo "Uso: $0 usuario"
  exit 1
fi

find / -user $1 >arq.txt 2>errors.txt
