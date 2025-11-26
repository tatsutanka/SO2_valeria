echo "Calcular o espaço utilizado no $HOME"
du -sh "$HOME"/* 2>/dev/null | sort -h
