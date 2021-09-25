# Jogo da forca usando RPC
##### Potifícia Universidade Católica de Goiás
**Professor:** Cláudio Martins Garcia<br>
**Aluno:** Higor Ferreira Alves Santos


### Objetivo
Implementar um jogo da forca multiusuário, que suporta até quatro jogadores. O jogo será implementado utilizando-se *RPC*, (Remote Procedure Call), a fim de estruturar uma arquiteura cliente servidor na qual os jogadores acessam o servidor. Será implementado um semáforo para tratar o acesso simultâneo ao mesmo recurso.

### Como testar o jogo
Os executáveis já estão inclusos. Basta apenas iniciar o servidor com o comando:
```bash
./forca_server
```
E cada jogador é iniciado com:
```bash
./forca_client localhost
```

### O Build do projeto

O arquivo forca.x descreve as estruturas de dados utilizadas e também os métodos que serão implementados nos clientes e no servidor. Para construir o projeto, primeiro utilizamos

```bash
rpcgen -a -C forca.x
```
para gerar os arquivos de cabeçalho e os códigos em c.
Após a geração desses arquivos, são feitas as devidas implementações, e para que não seja necessário compllar os aruivos um por um, utilizamos o **make**.
```bash
make -f Makefile.forca
```
Após o comando make os arquivos descritos em **como testar o jogo** são gerados.