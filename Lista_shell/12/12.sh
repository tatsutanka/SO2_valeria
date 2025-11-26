#!/bin/bash

# Extrai o primeiro campo (nome do usuário) do /etc/passwd
# Ordena em ordem alfabética
echo "Os shells unicos cadastrados no sistema (ordem alfabética):"
cut -d: -f7 /etc/passwd | sort | uniq -c
