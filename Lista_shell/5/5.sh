#!/bin/sh

NUM_PROC=$(ps -e | wc -l)
NUM_PROC=$((NUM_PROC - 1))

echo "Número de processos em execução: $NUM_PROC"
