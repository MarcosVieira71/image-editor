#!/bin/bash

trap 'echo -e "\n❌ Ocorreu um erro durante a execução do script. Abortando."; exit 1' ERR
set -e

if ! command -v conan &> /dev/null
then
    echo "Conan não encontrado. Por favor, instale o Conan."
    exit 1
fi
mkdir -p build

if [ ! -d "build/conan" ]; then
    echo "Instalando dependências com o Conan..."
    conan install . --build=missing -of=build/conan
else
    echo "Dependências já instaladas. Pulando o passo de instalação."
fi

cd build

echo "Configurando o CMake..."
cmake -DCMAKE_TOOLCHAIN_FILE=conan/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release .. > /dev/null 2>&1

echo "Compilando o projeto..."
cmake --build .

echo "Compilação concluida"
