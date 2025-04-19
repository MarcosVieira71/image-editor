#!/bin/bash

if ! command -v conan &> /dev/null
then
    echo "Conan não encontrado. Por favor, instale o Conan."
    exit 1
fi
mkdir -p build

echo "Instalando dependências com o Conan..."
conan install . --build=missing  -of=build/conan

cd build

echo "Configurando o CMake..."
cmake -DCMAKE_TOOLCHAIN_FILE=conan/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release ..

echo "Compilando o projeto..."
cmake --build .

echo "Compilação concluida"
