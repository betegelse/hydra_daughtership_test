# Um repositório para teste do Hydra/daughtership

Para compilá-lo, primeiro instale o ESP-FreeRTOS e seu ambiente de desenvolvimento seguindo os passos delineados nesta [página](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/).

Assumindo que este ambiente foi instalado em `~/esp`, rode os seguintes comandos:

        cd ~/esp
        git clone https://github.com/betegelse/hydra_daughtership_test.git

Isto criará uma pasta dentro de `~/esp` com o nome hydra\_daughtership\_test.  Este será o projeto.  Em seguida, dentro deste diretório, crie uma pasta components.  Dentro desta subpasta, rode o comando

        git clone https://github.com/betegelse/hydra_daughtership.git

Para compilar o código de teste, volte para o diretório hydra\_daughtership\_test e rode `. ../esp-idf/export.sh`. Depois, rode `idf.py build` (ou qualquer outra variante) para compilar o código. Parabéns, você tem um ambiente para começar a programar o Hydra.

Observe que há dois repositórios coexistindo, um do código de teste e outro, dentro da subpasta `components`, que é o código do Hydra em si.  As atualizações do Git de um e de outro são feitos separadamente.  Para as instruções sobre o Git abaixo, você precisará antes entrar no diretório apropriado.

Depois de modificar o código em sua máquina, você provavelmente vai querer disponibilizá-lo para os outros fazendo o upload para o GitHub.  Rode então o seguinte comando:

        git push origin

Você também pode baixar para a sua máquina as atualizações no código que outras pessoas fizeram rodando o comando

        git pull

