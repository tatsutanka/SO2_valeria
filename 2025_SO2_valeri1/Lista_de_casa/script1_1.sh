#!/bin/bash

# Script para aplicar um patch .diff em um arquivo

# Verifica se foram passados dois argumentos
if [ $# -ne 2 ]; then
  echo "Uso: $0 <arquivo_original> <patch.diff>"
  exit 1
fi

ARQUIVO_ORIGINAL="$1"
PATCH_FILE="$2"

# Verifica se o arquivo original existe
if [ ! -f "$ARQUIVO_ORIGINAL" ]; then
  echo "Erro: Arquivo original '$ARQUIVO_ORIGINAL' não encontrado."
  exit 1
fi

# Verifica se o patch existe
if [ ! -f "$PATCH_FILE" ]; then
  echo "Erro: Arquivo de patch '$PATCH_FILE' não encontrado."
  exit 1
fi

# Aplica o patch
if patch "$ARQUIVO_ORIGINAL" "$PATCH_FILE"; then
  echo "✅ Patch aplicado com sucesso em '$ARQUIVO_ORIGINAL'."
else
  echo "❌ Falha ao aplicar patch."
  exit 1
fi
