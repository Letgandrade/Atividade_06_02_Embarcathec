# Controle de Servomotor por PWM com Raspberry Pi Pico W

## Descrição do Projeto

Este projeto visa simular o controle do ângulo de um servomotor padrão utilizando o microcontrolador Raspberry Pi Pico W e a ferramenta Pico SDK. A simulação será realizada na plataforma Wokwi, e será implementada a modulação por largura de pulso (PWM) para ajustar o ângulo do servomotor.

## Requisitos

- Raspberry Pi Pico W (simulado no Wokwi)
- Servomotor padrão (simulado no Wokwi)
- VS Code com ambiente de desenvolvimento Pico SDK
- Simulador Wokwi integrado ao VS Code
- Repositório GitHub para versionamento

## Configuração do PWM

- **Frequência do PWM:** 50Hz (período de 20ms) na GPIO 22
- **Posição de 180 graus:** Ciclo ativo de 2400µs (0,12%) - Aguardar 5 segundos
- **Posição de 90 graus:** Ciclo ativo de 1470µs (0,0735%) - Aguardar 5 segundos
- **Posição de 0 graus:** Ciclo ativo de 500µs (0,025%) - Aguardar 5 segundos

## Movimentação Contínua

Uma rotina foi implementada para movimentação contínua entre os ângulos de 0 a 180 graus, com incrementos de 5µs a cada 10ms para um movimento suave.

## Experimento com o LED RGB

O experimento também incluiu a utilização do LED RGB na GPIO 12 da placa BitDogLab. O comportamento observado do LED deve ser registrado pelo discente.

## Como Executar o Projeto

1. Clone este repositório:
2. Configure o ambiente de desenvolvimento com Pico SDK e Wokwi.
3. Compile e execute o código utilizando o VS Code.
4. Observe o comportamento do servomotor e do LED RGB na simulação.

## Testes

Testes básicos foram implementados para garantir:

- Configuração correta da frequência de PWM
- Ajuste correto dos ciclos ativos para os ângulos do servomotor
- Movimentação suave do servomotor
- Interferência do PWM na iluminação do LED RGB

## Demonstração

Um vídeo de demonstração do projeto pode ser acessado no seguinte link: https://drive.google.com/file/d/1gVJQmjDdzWe-CcEKB05qgOOwP7VnQC-x/view?usp=sharing



