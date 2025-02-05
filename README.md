# Semáforo

Este projeto tem como objetivo mostrar a funcionalidade de um temporizador periódico com callback de um Raspberry Pi Pico W.

# Como baixar e executar o código

    1-Baixar ou utilizar git clone no repositório.
          git clone https://github.com/MSoares0079/EmbarcaTech_Semaforo_temporizacao_periodica.git
    2-Ter o VS Code instalado e devidamente configurado.
    3-Ter a extensão do Raspberry Pi Pico instalada no VS Code.
    4-Compilar o arquivo "Semaforo_temporizacao_periodica.c" utilizando o compilador do Raspberry Pi Pico.
    5-O código pode ser simulado pelo "diagram.json" apartir da extensão Wokwi,
        mas caso deseje utilizar em um Raspberry Pi Pico W, especificamente o disponibilizado pelo EmbarcaTech,
        haverá divergência na cor do LEDs, porque não existe o LED amarelo como cor primária e sim o azul.
# Estrutura do código

Na função principal(int main) não ocorre nenhum processamento de informação referente ao semáforo, 
porém o mesmo poderia estar ocupado em outra tarefa,
para representar isso foi utilizado um printf com as informações "Processador ocupado em outra tarefa".

Foi configurado um temporizador com callback de forma períodica por 3s. 
Ou seja, toda vez que passar 3s ocorrerá uma interrupção em que uma função será chamada e ela é responsável por alterar LEDs de um semáforo.

A alteração dos LEDs ocorre através de um contador(cont) que representa os três estados do sistema: 

Apenas o Led vermelho ativado -> Apenas o Led amarelo ativado -> Apenas o Led verde ativado

O contador é incrementado após a interupção do temporizador e após alcançar o último estado o mesmo retorna ao valor inicial. 

# Video demonstrando o funcionamento do código
https://drive.google.com/file/d/1-1fJtuztCFnzNeMO_CJbkQ2SFz5mB1-X/view?usp=sharing
