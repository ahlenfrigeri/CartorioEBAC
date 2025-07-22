# 📜 Cartório EBAC

Este é um projeto simples de cartório, desenvolvido como atividade prática do curso de C da EBAC.

## ✅ Funcionalidades

- Registro de pessoas com CPF, nome, sobrenome e cargo.
- Consulta de pessoas cadastradas por CPF.
- Exclusão de cadastros por CPF.
- Armazenamento dos dados em arquivos `.txt` para persistência.

## 🛠️ Tecnologias utilizadas

- Linguagem C
- Manipulação de arquivos (`fopen`, `fwrite`, `fread`, `fclose`, `remove`)
- Git e GitHub

## 📂 Estrutura dos Arquivos

Cada cadastro é salvo em um arquivo `.txt` nomeado com o CPF da pessoa.

Exemplo:
12345678900.txt

arduino
Copiar
Editar
Conteúdo do arquivo:
Nome: Maria
Sobrenome: Silva
Cargo: Gerente

markdown
Copiar
Editar

## ▶️ Como executar

1. Compile o programa em um compilador C (Ex: Dev-C++, Code::Blocks, GCC).
2. Execute o arquivo `.exe` gerado.
3. Use o menu para registrar, consultar ou excluir registros.

## 🧠 Aprendizados

- Estruturação de projetos em C
- Manipulação de arquivos
- Organização de código com boas práticas
- Uso do GitHub para versionamento

### 🛠 Tecnologias
Este projeto foi feito em linguagem C.

### 🚀 Como usar no computador
Se você estiver no Windows:
1. Baixe e instale o Dev C++
2. Abra o arquivo cartorioebac.c
3. Clique em “Executar” (ou pressione F11 no teclado)

Se quiser usar pelo terminal (Linux ou Mac):
1. Abra o terminal na pasta onde está o arquivo
2. Digite:
   gcc cartorioebac.c -o cartorio
   ./cartorio

### 👤 Autor
Projeto feito por Ahlen Mhethika Frigeri, como parte do curso da EBAC.
