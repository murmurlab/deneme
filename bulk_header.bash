#!/bin/bash

backup=""
insert_file=""
delete_start=false
dosyalar=()

while [ "$#" -gt 0 ]; do
  case "$1" in
    -b)
      backup=".bak"
      ;;
    -in)
      shift
      insert_file="$1"
      ;;
    -ex)
      delete_start=true
      ;;
    *)
      dosyalar+=("$1")
      ;;
  esac
  shift
done

for dosya in "${dosyalar[@]}"; do
  if [ -f "$dosya" ]; then
    if [ "$delete_start" = true ]; then
      sed -i "$backup" '1,11d' "$dosya"
      echo "delete bulk: $dosya"
    fi
    if [ -n "$insert_file" ]; then
      cat "$insert_file" "$dosya" > temp_file && mv temp_file "$dosya"
      echo "insert content: $dosya"
    fi
  else
    echo "Dosya bulunamadı: $dosya"
  fi
done