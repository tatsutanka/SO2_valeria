#!/bin/bash

i=1

# Enquanto houver argumentos ($# > 0)
while [ $# -gt 0 ]; do
  echo "Argumento $i: $1"

  # Remove o primeiro argumento, deslocando os demais
  shift

  i=$((i + 1))
done
