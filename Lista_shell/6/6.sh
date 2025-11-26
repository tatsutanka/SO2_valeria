#!/bin/bash

# Pede o mês
read -p "Digite o mês (1-12): " MES

# Pede o ano
read -p "Digite o ano (ex: 2025): " ANO

# Mostra o calendário
echo ""
echo "Calendário de $MES/$ANO:"
cal "$MES" "$ANO"
