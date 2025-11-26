#!/bin/sh

for i in {1..5}; do
  DIR="dir$i"
  mkdir -p "$DIR"
  echo "criando o diretorio -> $i"
  for j in {1..3}; do
    ARQ="$DIR/file$j"
    touch "$ARQ"
    echo "criando arquivo -> $j"
  done
done

echo "finalizado"
