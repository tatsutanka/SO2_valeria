#!/bin/bash

# Pergunta o diretório
read -p "Digite o diretório onde estão os arquivos: " DIR

# Verifica se é um diretório válido
if [ ! -d "$DIR" ]; then
  echo "Erro: '$DIR' não é um diretório válido."
  exit 1
fi

# Pergunta as extensões
read -p "Digite a extensão atual (sem ponto, ex: mpeg3): " EXT_OLD
read -p "Digite a nova extensão (sem ponto, ex: mp3): " EXT_NEW

echo ""
echo "Renomeando arquivos '.$EXT_OLD' para '.$EXT_NEW' em: $DIR"
echo ""

# Loop para renomear
FOUND=0
for ARQ in "$DIR"/*."$EXT_OLD"; do
  [ -e "$ARQ" ] || continue # ignora se não houver correspondência
  FOUND=1
  NOVO="${ARQ%.$EXT_OLD}.$EXT_NEW"
  echo "Renomeando: $ARQ → $NOVO"
  mv "$ARQ" "$NOVO"
done

# Caso não tenha encontrado nenhum arquivo
if [ $FOUND -eq 0 ]; then
  echo "Nenhum arquivo .$EXT_OLD encontrado no diretório."
else
  echo ""
  echo "Concluído!"
fi
