!#/bin/bash
echo "Os usuarios cadastratos são:"
cut -d: -f1 /etc/passwd | sort
