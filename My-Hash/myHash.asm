;********************************************************
;                   NOME E NUSP DOS ALUNOS
;********************************************************
;   Ueslei Aparecido Moreira Santos Pina - NUSP: 11837081
;   João Pedro Matos de Deus - NUSP: 12677492
;   Nicolas de Góes - NUSP: 12563780
;********************************************************



;********************************************************
;                   REGISTRADORES
;********************************************************
;   r0 = Posição na tela ou contador
;   r1 =
;   r2 = Strings
;   r3 =
;   r4 = Cor
;   r5 =
;   r6 = Delay
;   r7 = Inchar
;********************************************************



;********************************************************
;                    TABELA DE CORES
;********************************************************
; adicione ao caracter para adicionar a cor correspondente
; 0 branco                          0000
; 255 marrom                        0001
; 512 verde                         0010
; 768 oliva                         0011
; 1024 azul marinho                 0100
; 1280 roxo                         0101
; 1537 teal                         0110
; 1793 prata                        0111
; 2048 cinza                        1000
; 2304 vermelho                     1001
; 2561 lima                         1010
; 2816 amarelo                      1011
; 3072 azul                         1100
; 3328 rosa                         1101
; 3584 aqua                         1110
; 3839 preto                        1111
;********************************************************



;********************************************************
;                       VARIÁVEIS
;********************************************************
Posicao1: var #0
Posicao2: var #0
Posicao3: var #0
Posicao4: var #0
Posicao5: var #0
Posicao6: var #0
Posicao7: var #0
Posicao8: var #0
Posicao9: var #0

Player1: var #0
Vez: var #0

X: var #2
O: var #3

; Posição de memória 4001: Flag de utilização do X na posição 1 do jogo
; Posição de memória 4002: Flag de utilização do X na posição 2 do jogo
; Posição de memória 4003: Flag de utilização do X na posição 3 do jogo
; Posição de memória 4004: Flag de utilização do X na posição 4 do jogo
; Posição de memória 4005: Flag de utilização do X na posição 5 do jogo
; Posição de memória 4006: Flag de utilização do X na posição 6 do jogo
; Posição de memória 4007: Flag de utilização do X na posição 7 do jogo
; Posição de memória 4008: Flag de utilização do X na posição 8 do jogo
; Posição de memória 4009: Flag de utilização do X na posição 9 do jogo

; Posição de memória 5001: Flag de utilização do X na posição 1 do jogo
; Posição de memória 5002: Flag de utilização do X na posição 2 do jogo
; Posição de memória 5003: Flag de utilização do X na posição 3 do jogo
; Posição de memória 5004: Flag de utilização do X na posição 4 do jogo
; Posição de memória 5005: Flag de utilização do X na posição 5 do jogo
; Posição de memória 5006: Flag de utilização do X na posição 6 do jogo
; Posição de memória 5007: Flag de utilização do X na posição 7 do jogo
; Posição de memória 5008: Flag de utilização do X na posição 8 do jogo
; Posição de memória 5009: Flag de utilização do X na posição 9 do jogo

; Posição de memória 4000: Quantidade de jogadas escolhida pelo jogador

; Posição de memória 4010: Contador de jogadas feitas

; Posição de memória 5010: Contador de pontos do jogador 1
; Posição de memória 5011: Contador de pontos do jogador 2

;********************************************************



jmp main
;********************************************************
;                        MENSAGENS
;********************************************************
Mensagem1:  string "     _____          __  __ ______ "
Mensagem2:  string "    /_____|   /\\   |  \\/  |  ____|"
Mensagem3:  string "   | |  __   /  \\  | \\  / | |__   "
Mensagem4:  string "   | | |_ | / /\\ \\ | |\\/| |  __|  "
Mensagem5:  string "   | |__| |/ ____ \\| |  | | |____ "
Mensagem6:  string "    \\_____/_/    \\_\\_|__|_|______|"
Mensagem7:  string "    _    _           _____ _    _ "
Mensagem8:  string "   | |  | |   /\\    / ____| |  | |"
Mensagem9:  string "   | |__| |  /  \\  | (___ | |__| |"
Mensagem10: string "   |  __  | / /\\ \\  \\___ \\|  __  |"
Mensagem11: string "   | |  | |/ ____ \\ ____\\ | |  | |"
Mensagem12: string "   |_|  |_/_/    \\_\\_____/|_|  |_|"

PressEnter1: string "     -------------------------- "
PressEnter2: string "    ( P R E S S     E N T E R  )"

EscolheNumeroJogos: string "CHOOSE HOW MANY GAMES TO WIN"
PressEnterConfirmaEscolha: string "PRESS ENTER TO CONFIRM"

DeuVelhaSTR: string "  G A M E   H A S H !!!"

PressEnterPartidaSTR: string "(PRESS ENTER TO PLAY ANOTHER MATCH)"

Player: string "Player 1                Player 2"

MensagemPlayer1: string " ___  _            _    _  ___  ____"
MensagemPlayer2: string "|   || |      /\\  \\ \\  / /| __|| __ |"
MensagemPlayer3: string "| | || |     /  \\  \\ \\/ / ||__ ||__||"
MensagemPlayer4: string "|  _|| |    / /\\ \\  \\  /  | __||    |"
MensagemPlayer5: string "| |  | |_  /  __  \\ | |   ||__ | |\\ \\"
MensagemPlayer6: string "|_|  |___|/__/  \\__\\|_|   |___||_| \\_\\"

MensagemVencedor1: string " _  _  _   _   ___    _   ______"
MensagemVencedor2: string "| || || | | | |   \\  | | /  ____|"
MensagemVencedor3: string "| || || | | | | |\\ \\ | | | (____"
MensagemVencedor4: string "| || || | | | | | \\ \\| | \\____  \\"
MensagemVencedor5: string "|       | | | | |  \\   | _____) |"
MensagemVencedor6: string " \\_____/  |_| |_|   \\__| \\______|"

FimDeJogoSTR: string " PRESS ENTER TO GO TO MENU"
;********************************************************



;********************************************************
;                    PROGRAMA PRINCIPAL
;********************************************************
main:

    call DesenhaMapa
    call HomePage
    call PressEnter
    cls
    call DesenhaMapa
    call EscolhaJogadas
    cls
    call DesenhaMapa
    call DesenhaHash
    call Jogando

halt
;********************************************************



;********************************************************
;                     DESENHA MAPA
;********************************************************
DesenhaMapa:

    loadn r0, #0
    loadn r1, #39
    loadn r2, #'#'
    loadn r3, #40
    loadn r4, #3072
    add r2, r2, r4

    loadn r4, #1200

    Loop_mapa:
        outchar r2, r0
        outchar r2, r1

        add r0, r0, r3
        add r1, r1, r3

        cmp r0, r4
        jle Loop_mapa

    loadn r0, #1
    loadn r1, #1161

    Stage_Loop2:
        outchar r2, r0
        outchar r2, r1

        inc r0
        inc r1

        cmp r0, r3
        jle Stage_Loop2

    rts
;********************************************************



;********************************************************
;                     DESENHA HASH
;********************************************************
DesenhaHash:

    loadn r0, #17
    loadn r1, #24
    loadn r2, #'|'
    loadn r3, #40
    loadn r4, #512

    add r2, r2, r4
    add r0, r0, r3
    add r1, r1, r3
    add r0, r0, r3
    add r1, r1, r3
    add r0, r0, r3
    add r1, r1, r3

    loadn r4, #720

    Loop_hash_1:
        outchar r2, r0
        outchar r2, r1

        add r0, r0, r3
        add r1, r1, r3

        cmp r0, r4
        jle Loop_hash_1

    loadn r0, #291
    loadn r1, #491
    loadn r2, #'_'
    loadn r3, #1
    loadn r4, #512

    add r2, r2, r4

    loadn r4, #297

    Loop_hash_2:
        outchar r2, r0
        outchar r2, r1

        inc r0
        inc r1
        cmp r0, r4
        jle Loop_hash_2


    loadn r0, #298
    loadn r1, #498
    loadn r4, #304

    Loop_hash_3:
        outchar r2, r0
        outchar r2, r1

        add r0, r0, r3
        add r1, r1, r3

        cmp r0, r4
        jle Loop_hash_3

    loadn r0, #305
    loadn r1, #505
    loadn r4, #311

    Loop_hash_4:
            outchar r2, r0
            outchar r2, r1

            add r0, r0, r3
            add r1, r1, r3

            cmp r0, r4
            jle Loop_hash_4

    loadn r0, #805
    loadn r4, #1024
    call posicao_desenho_X
    loadn r0, #830
    loadn r4, #2304
    call posicao_desenho_O

    loadn r0, #1004
    loadn r1, #Player
    loadn r2, #512
    loadn r3, #'\0'
    call Imprime_String

    call Desenha_pontuacao
    call Atualiza_vez

    rts
;********************************************************



;********************************************************
;                   DESENHA HOME PAGE
;********************************************************
HomePage:

    loadn r0, #82
    loadn r1, #Mensagem1
    loadn r2, #512
    loadn r3, #'\0'
    call Imprime_String

    loadn r0, #122
    loadn r1, #Mensagem2
    call Imprime_String

    loadn r0, #162
    loadn r1, #Mensagem3
    call Imprime_String

    loadn r0, #202
    loadn r1, #Mensagem4
    call Imprime_String

    loadn r0, #242
    loadn r1, #Mensagem5
    call Imprime_String

    loadn r0, #282
    loadn r1, #Mensagem6
    call Imprime_String

    loadn r0, #362
    loadn r1, #Mensagem7
    call Imprime_String

    loadn r0, #402
    loadn r1, #Mensagem8
    call Imprime_String

    loadn r0, #442
    loadn r1, #Mensagem9
    call Imprime_String

    loadn r0, #482
    loadn r1, #Mensagem10
    call Imprime_String

    loadn r0, #522
    loadn r1, #Mensagem11
    call Imprime_String

    loadn r0, #562
    loadn r1, #Mensagem12
    call Imprime_String

rts
;********************************************************



;********************************************************
;                       PRESS ENTER
;********************************************************
PressEnter:


    Loop_PressEnter:
        loadn r0, #962
        loadn r1, #PressEnter1
        loadn r2, #2048
        loadn r3, #'\0'
        call Imprime_String

        loadn r0, #1002
        loadn r1, #PressEnter2
        call Imprime_String

        loadn r0, #1042
        loadn r1, #PressEnter1
        call Imprime_String

        loadn r6, #90
        call Delay

        loadn r0, #24
        call ApagaLinha
        inc r0
        call ApagaLinha
        inc r0
        call ApagaLinha

        loadn r6, #90
        call Delay

        inchar r7
        loadn r1, #13
        cmp r7, r1
        jne Loop_PressEnter
        jeq Loop_PressEnter_Sai

    Loop_PressEnter_Sai:

rts
;********************************************************



;********************************************************
;                  ESCOLHA DE JOGADAS
;********************************************************
EscolhaJogadas:

    push r0
    push r1
    push r2
    push r3
    push r4

    loadn r0, #205
    loadn r1, #EscolheNumeroJogos
    loadn r2, #512
    loadn r3, #'\0'
    call Imprime_String

    loadn r4, #3584
    call posicao_desenho_1_escolha_jogada
    call posicao_desenho_3_escolha_jogada
    call posicao_desenho_5_escolha_jogada

    loadn r0, #889
    loadn r1, #PressEnterConfirmaEscolha
    loadn r2, #512
    loadn r3, #'\0'
    call Imprime_String

    loadn r7, #0

    EscolhendoJogada:
        inchar r7
        loadn r0, #49
        cmp r0, r7
        jeq EscolhendoJogada1

        loadn r0, #51
        cmp r0, r7
        jeq EscolhendoJogada3

        loadn r0, #53
        cmp r0, r7
        jeq EscolhendoJogada5

        jmp EscolhendoJogada

        EscolhendoJogada1:
            loadn r4, #3584
            call posicao_desenho_3_escolha_jogada
            call posicao_desenho_5_escolha_jogada
            loadn r4, #2816
            call posicao_desenho_1_escolha_jogada
            loadn r3, #1
            store 4000, r3
            jmp ConfirmarEscolha

        EscolhendoJogada3:
            loadn r4, #3584
            call posicao_desenho_1_escolha_jogada
            call posicao_desenho_5_escolha_jogada
            loadn r4, #2816
            call posicao_desenho_3_escolha_jogada
            loadn r3, #3
            store 4000, r3
            jmp ConfirmarEscolha

        EscolhendoJogada5:
            loadn r4, #3584
            call posicao_desenho_1_escolha_jogada
            call posicao_desenho_3_escolha_jogada
            loadn r4, #2816
            call posicao_desenho_5_escolha_jogada
            loadn r3, #5
            store 4000, r3
            jmp ConfirmarEscolha

    ConfirmarEscolha:
        inchar r7
        loadn r0, #13
        cmp r0, r7
        jeq EscolhaConfirmada

        loadn r0, #49
        cmp r0, r7
        jeq EscolhendoJogada1

        loadn r0, #51
        cmp r0, r7
        jeq EscolhendoJogada3

        loadn r0, #53
        cmp r0, r7
        jeq EscolhendoJogada5

        jmp ConfirmarEscolha

    EscolhaConfirmada:
        pop r4
        pop r4
        pop r2
        pop r1
        pop r0

    rts
;********************************************************



;********************************************************
;                        JOGANDO
;********************************************************
Jogando:

    call DesenhaPosicoes
    call Jogada

    rts
;********************************************************



;********************************************************
;                       JOGADA
;********************************************************
Jogada:

    push r0
    push r1
    push r2
    push r3

    loadn r0, #0
    store 4010, r0     ;contador de jogadas
    loadn r5, #0

    PosicaoEscolhida:
;case '1':
        inchar r7
        loadn r0, #49
        cmp r7, r0
        jeq PosicaoEscolhida1

;case '2':
        inc r0
        cmp r7, r0
        jeq PosicaoEscolhida2

;case '3':
        inc r0
        cmp r7, r0
        jeq PosicaoEscolhida3

;case '4':
        inc r0
        cmp r7, r0
        jeq PosicaoEscolhida4

;case '5':
        inc r0
        cmp r7, r0
        jeq PosicaoEscolhida5

;case '6':
        inc r0
        cmp r7, r0
        jeq PosicaoEscolhida6

;case '7':
        inc r0
        cmp r7, r0
        jeq PosicaoEscolhida7

;case '8':
        inc r0
        cmp r7, r0
        jeq PosicaoEscolhida8

;case '9':
        inc r0
        cmp r7, r0
        jeq PosicaoEscolhida9

        jmp PosicaoEscolhida

        PosicaoEscolhida1:
            ;verificando se posição já foi escolhida antes
            load r0, 4001
            loadn r1, #1
            cmp r0, r1
            jeq PosicaoEscolhida
            load r0, 5001
            cmp r0, r1
            jeq PosicaoEscolhida

            loadn r4, #3839
            call posicao_desenho_1

            call Atualiza_vez

            load r0, 4010
            loadn r1, #1
            add r0, r0, r1
            store 4010, r0

            loadn r0, #131
            loadn r1, #118
            inc r5
            call VezJogador
            jmp PosicaoEscolhida

        PosicaoEscolhida2:
            ;verificando se posição já foi escolhida antes
            load r0, 4002
            loadn r1, #1
            cmp r0, r1
            jeq PosicaoEscolhida
            load r0, 5002
            cmp r0, r1
            jeq PosicaoEscolhida

            loadn r4, #3839
            call posicao_desenho_2

            call Atualiza_vez

            load r0, 4010
            loadn r1, #1
            add r0, r0, r1
            store 4010, r0

            loadn r0, #138
            loadn r1, #125
            inc r5
            call VezJogador
            jmp PosicaoEscolhida

        PosicaoEscolhida3:
            ;verificando se posição já foi escolhida antes
            load r0, 4003
            loadn r1, #1
            cmp r0, r1
            jeq PosicaoEscolhida
            load r0, 5003
            cmp r0, r1
            jeq PosicaoEscolhida

            loadn r4, #3839
            call posicao_desenho_3

            call Atualiza_vez

            load r0, 4010
            loadn r1, #1
            add r0, r0, r1
            store 4010, r0

            loadn r0, #145
            loadn r1, #133
            inc r5
            call VezJogador
            jmp PosicaoEscolhida

        PosicaoEscolhida4:
            ;verificando se posição já foi escolhida antes
            load r0, 4004
            loadn r1, #1
            cmp r0, r1
            jeq PosicaoEscolhida
            load r0, 5004
            cmp r0, r1
            jeq PosicaoEscolhida

            loadn r4, #3839
            call posicao_desenho_4

            call Atualiza_vez

            load r0, 4010
            loadn r1, #1
            add r0, r0, r1
            store 4010, r0

            loadn r0, #331
            loadn r1, #318
            inc r5
            call VezJogador
            jmp PosicaoEscolhida

        PosicaoEscolhida5:
            ;verificando se posição já foi escolhida antes
            load r0, 4005
            loadn r1, #1
            cmp r0, r1
            jeq PosicaoEscolhida
            load r0, 5005
            cmp r0, r1
            jeq PosicaoEscolhida

            loadn r4, #3839
            call posicao_desenho_5

            call Atualiza_vez

            load r0, 4010
            loadn r1, #1
            add r0, r0, r1
            store 4010, r0

            loadn r0, #338
            loadn r1, #325
            inc r5
            call VezJogador
            jmp PosicaoEscolhida

        PosicaoEscolhida6:
            ;verificando se posição já foi escolhida antes
            load r0, 4006
            loadn r1, #1
            cmp r0, r1
            jeq PosicaoEscolhida
            load r0, 5006
            cmp r0, r1
            jeq PosicaoEscolhida

            loadn r4, #3839
            call posicao_desenho_6

            call Atualiza_vez

            load r0, 4010
            loadn r1, #1
            add r0, r0, r1
            store 4010, r0

            loadn r0, #345
            loadn r1, #333
            inc r5
            call VezJogador
            jmp PosicaoEscolhida

        PosicaoEscolhida7:
            ;verificando se posição já foi escolhida antes
            load r0, 4007
            loadn r1, #1
            cmp r0, r1
            jeq PosicaoEscolhida
            load r0, 5007
            cmp r0, r1
            jeq PosicaoEscolhida

            loadn r4, #3839
            call posicao_desenho_7

            call Atualiza_vez

            load r0, 4010
            loadn r1, #1
            add r0, r0, r1
            store 4010, r0

            loadn r0, #531
            loadn r1, #518
            inc r5
            call VezJogador
            jmp PosicaoEscolhida

        PosicaoEscolhida8:
            ;verificando se posição já foi escolhida antes
            load r0, 4008
            loadn r1, #1
            cmp r0, r1
            jeq PosicaoEscolhida
            load r0, 5008
            cmp r0, r1
            jeq PosicaoEscolhida

            loadn r4, #3839
            call posicao_desenho_8

            call Atualiza_vez

            load r0, 4010
            loadn r1, #1
            add r0, r0, r1
            store 4010, r0

            loadn r0, #538
            loadn r1, #525
            inc r5
            call VezJogador
            jmp PosicaoEscolhida

        PosicaoEscolhida9:
        ;verificando se posição já foi escolhida antes
            load r0, 4009
            loadn r1, #1
            cmp r0, r1
                jeq PosicaoEscolhida
                load r0, 5009
            cmp r0, r1
            jeq PosicaoEscolhida

            loadn r4, #3839
            call posicao_desenho_9

            call Atualiza_vez

            load r0, 4010
            loadn r1, #1
            add r0, r0, r1
            store 4010, r0

            loadn r0, #545
            loadn r1, #533
            inc r5
            call VezJogador
            jmp PosicaoEscolhida

    pop r3
    pop r2
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;                     VEZ JOGADOR
;********************************************************
VezJogador:
    push r0
    push r1
    push r2
    push r3
    push r4
    push r5
    push r6

    VezDeQuem:
        loadn r5, #0
        cmp r5, r6
        jeq VezX
        jne VezO

        VezX:
            loadn r4, #1024
            inc r6
            call posicao_desenho_X
            call MarcadorFlagsX
            call PosicaoEscolhida
        VezO:
            loadn r4, #2304
            dec r6
            call posicao_desenho_O
            call MarcadorFlagsO
            call PosicaoEscolhida

    pop r6
    pop r5
    pop r4
    pop r3
    pop r2
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;                       VENCENDO
;********************************************************
Vencendo:

    push r0
    push r1
    push r2
    push r3
    push r4
    push r5

    loadn r1, #1

;verifica vitória do jogador 1
    Jogador1Ganha123:
        loadn r2, #211
        load r0, 4001
        cmp r0, r1
        jne Jogador1Ganha456
        load r0, 4002
        cmp r0, r1
        jne Jogador1Ganha456
        load r0, 4003
        cmp r0, r1
        jeq DesenhoDaLinhaHorizontal1

    Jogador1Ganha456:
        loadn r2, #411
        load r0, 4004
        cmp r0, r1
        jne Jogador1Ganha789
        load r0, 4005
        cmp r0, r1
        jne Jogador1Ganha789
        load r0, 4006
        cmp r0, r1
        jeq DesenhoDaLinhaHorizontal1

    Jogador1Ganha789:
        loadn r2, #611
        load r0, 4007
        cmp r0, r1
        jne Jogador1Ganha147
        load r0, 4008
        cmp r0, r1
        jne Jogador1Ganha147
        load r0, 4009
        cmp r0, r1
        jeq DesenhoDaLinhaHorizontal1

    Jogador1Ganha147:
        loadn r2, #133
        load r0, 4001
        cmp r0, r1
        jne Jogador1Ganha258
        load r0, 4004
        cmp r0, r1
        jne Jogador1Ganha258
        load r0, 4007
        cmp r0, r1
        jeq DesenhoDaLinhaVertical1

    Jogador1Ganha258:
        loadn r2, #140
        load r0, 4002
        cmp r0, r1
        jne Jogador1Ganha369
        load r0, 4005
        cmp r0, r1
        jne Jogador1Ganha369
        load r0, 4008
        cmp r0, r1
        jeq DesenhoDaLinhaVertical1

    Jogador1Ganha369:
        loadn r2, #147
        load r0, 4003
        cmp r0, r1
        jne Jogador1Ganha159
        load r0, 4006
        cmp r0, r1
        jne Jogador1Ganha159
        load r0, 4009
        cmp r0, r1
        jeq DesenhoDaLinhaVertical1

    Jogador1Ganha159:
        load r0, 4001
        cmp r0, r1
        jne Jogador1Ganha357
        load r0, 4005
        cmp r0, r1
        jne Jogador1Ganha357
        load r0, 4009
        cmp r0, r1
        jeq DesenhoDaLinhaDiagonal1.1

    Jogador1Ganha357:
        load r0, 4003
        cmp r0, r1
        jne Jogador2Ganha123
        load r0, 4005
        cmp r0, r1
        jne Jogador2Ganha123
        load r0, 4007
        cmp r0, r1
        jeq DesenhoDaLinhaDiagonal1.2

;verifica vitória do jogador 2
    Jogador2Ganha123:
        loadn r2, #211
        load r0, 5001
        cmp r0, r1
        jne Jogador2Ganha456
        load r0, 5002
        cmp r0, r1
        jne Jogador2Ganha456
        load r0, 5003
        cmp r0, r1
        jeq DesenhoDaLinhaHorizontal2

    Jogador2Ganha456:
        loadn r2, #411
        load r0, 5004
        cmp r0, r1
        jne Jogador2Ganha789
        load r0, 5005
        cmp r0, r1
        jne Jogador2Ganha789
        load r0, 5006
        cmp r0, r1
        jeq DesenhoDaLinhaHorizontal2

    Jogador2Ganha789:
        loadn r2, #611
        load r0, 5007
        cmp r0, r1
        jne Jogador2Ganha147
        load r0, 5008
        cmp r0, r1
        jne Jogador2Ganha147
        load r0, 5009
        cmp r0, r1
        jeq DesenhoDaLinhaHorizontal2

    Jogador2Ganha147:
        loadn r2, #133
        load r0, 5001
        cmp r0, r1
        jne Jogador2Ganha258
        load r0, 5004
        cmp r0, r1
        jne Jogador2Ganha258
        load r0, 5007
        cmp r0, r1
        jeq DesenhoDaLinhaVertical2

    Jogador2Ganha258:
        loadn r2, #140
        load r0, 5002
        cmp r0, r1
        jne Jogador2Ganha369
        load r0, 5005
        cmp r0, r1
        jne Jogador2Ganha369
        load r0, 5008
        cmp r0, r1
        jeq DesenhoDaLinhaVertical2

    Jogador2Ganha369:
        loadn r2, #147
        load r0, 5003
        cmp r0, r1
        jne Jogador2Ganha159
        load r0, 5006
        cmp r0, r1
        jne Jogador2Ganha159
        load r0, 5009
        cmp r0, r1
        jeq DesenhoDaLinhaVertical2

    Jogador2Ganha159:
        load r0, 5001
        cmp r0, r1
        jne Jogador2Ganha357
        load r0, 5005
        cmp r0, r1
        jne Jogador2Ganha357
        load r0, 5009
        cmp r0, r1
        jeq DesenhoDaLinhaDiagonal2.1

    Jogador2Ganha357:
        load r0, 5003
        cmp r0, r1
        jne SemPontos
        load r0, 5005
        cmp r0, r1
        jne SemPontos
        load r0, 5007
        cmp r0, r1
        jeq DesenhoDaLinhaDiagonal2.2
        jmp SemPontos

    DesenhoDaLinhaVertical1:
        call LinhaVencedorVertical
        jmp MarcaPontoJ1

    DesenhoDaLinhaVertical2:
        call LinhaVencedorVertical
        jmp MarcaPontoJ2

    DesenhoDaLinhaHorizontal1:
        call LinhaVencedorHorizontal
        jmp MarcaPontoJ1

    DesenhoDaLinhaHorizontal2:
        call LinhaVencedorHorizontal
        jmp MarcaPontoJ2

    DesenhoDaLinhaDiagonal1.1:
        call LinhaVencedorDiagonal1
        jmp MarcaPontoJ1

    DesenhoDaLinhaDiagonal1.2:
        call LinhaVencedorDiagonal2
        jmp MarcaPontoJ1

    DesenhoDaLinhaDiagonal2.1:
        call LinhaVencedorDiagonal1
        jmp MarcaPontoJ2

    DesenhoDaLinhaDiagonal2.2:
        call LinhaVencedorDiagonal2
        jmp MarcaPontoJ2

    MarcaPontoJ1:
        load r0, 5010
        add r0, r0, r1
        store 5010, r0
        call Desenha_pontuacao
        call PressEnterPartida

    MarcaPontoJ2:
        load r0, 5011
        add r0, r0, r1
        store 5011, r0
        call Desenha_pontuacao
        call PressEnterPartida

    SemPontos:
        call DeuVelha

    pop r5
    pop r4
    pop r3
    pop r2
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;             ADICIONAR MARCADOR DE FLAGS X
;********************************************************
MarcadorFlagsX:

    push r0
    push r1
    push r7

    loadn r1, #1

    loadn r0, #49
    cmp r7, r0
    jeq MarcadorFlagsX1

    loadn r0, #50
    cmp r7, r0
    jeq MarcadorFlagsX2

    loadn r0, #51
    cmp r7, r0
    jeq MarcadorFlagsX3

    loadn r0, #52
    cmp r7, r0
    jeq MarcadorFlagsX4

    loadn r0, #53
    cmp r7, r0
    jeq MarcadorFlagsX5

    loadn r0, #54
    cmp r7, r0
    jeq MarcadorFlagsX6

    loadn r0, #55
    cmp r7, r0
    jeq MarcadorFlagsX7

    loadn r0, #56
    cmp r7, r0
    jeq MarcadorFlagsX8

    loadn r0, #57
    cmp r7, r0
    jeq MarcadorFlagsX9

    MarcadorFlagsX1:
        store 4001, r1
        call Vencendo

    MarcadorFlagsX2:
        store 4002, r1
        call Vencendo

    MarcadorFlagsX3:
        store 4003, r1
        call Vencendo

    MarcadorFlagsX4:
        store 4004, r1
        call Vencendo

    MarcadorFlagsX5:
        store 4005, r1
        call Vencendo

    MarcadorFlagsX6:
        store 4006, r1
        call Vencendo

    MarcadorFlagsX7:
        store 4007, r1
        call Vencendo

    MarcadorFlagsX8:
        store 4008, r1
        call Vencendo

    MarcadorFlagsX9:
        store 4009, r1
        call Vencendo

    pop r7
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;             ADICIONAR MARCADOR DE FLAGS O
;********************************************************
MarcadorFlagsO:

    push r0
    push r1
    push r7

    loadn r1, #1

    loadn r0, #49
    cmp r7, r0
    jeq MarcadorFlagsO1

    loadn r0, #50
    cmp r7, r0
    jeq MarcadorFlagsO2

    loadn r0, #51
    cmp r7, r0
    jeq MarcadorFlagsO3

    loadn r0, #52
    cmp r7, r0
    jeq MarcadorFlagsO4

    loadn r0, #53
    cmp r7, r0
    jeq MarcadorFlagsO5

    loadn r0, #54
    cmp r7, r0
    jeq MarcadorFlagsO6

    loadn r0, #55
    cmp r7, r0
    jeq MarcadorFlagsO7

    loadn r0, #56
    cmp r7, r0
    jeq MarcadorFlagsO8

    loadn r0, #57
    cmp r7, r0
    jeq MarcadorFlagsO9

    MarcadorFlagsO1:
        store 5001, r1
        call Vencendo

    MarcadorFlagsO2:
        store 5002, r1
        call Vencendo

    MarcadorFlagsO3:
        store 5003, r1
        call Vencendo

    MarcadorFlagsO4:
        store 5004, r1
        call Vencendo

    MarcadorFlagsO5:
        store 5005, r1
        call Vencendo

    MarcadorFlagsO6:
        store 5006, r1
        call Vencendo

    MarcadorFlagsO7:
        store 5007, r1
        call Vencendo

    MarcadorFlagsO8:
        store 5008, r1
        call Vencendo

    MarcadorFlagsO9:
        store 5009, r1
        call Vencendo

    pop r7
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;                      DEU VELHA
;********************************************************
DeuVelha:

    load r0, 4010
    loadn r1,  #9

    JogoDeuVelha:
        cmp r0, r1
        jeq DeuVelhaSim
        jne DeuVelhaNao

    DeuVelhaSim:
        loadn r0, #89
        loadn r1, #DeuVelhaSTR
        loadn r2, #0
        loadn r3, #'\0'
        call Imprime_String
        call PressEnterPartida

    DeuVelhaNao:
        call PosicaoEscolhida

    rts

;********************************************************



;********************************************************
;                  REINICIANDO JOGO
;********************************************************
Reinicio:

    loadn r0, #0

    ;4001 até 4009 para X
    store 4001, r0
    store 4002, r0
    store 4003, r0
    store 4004, r0
    store 4005, r0
    store 4006, r0
    store 4007, r0
    store 4008, r0
    store 4009, r0

    ;5001 até 5009 para O
    store 5001, r0
    store 5002, r0
    store 5003, r0
    store 5004, r0
    store 5005, r0
    store 5006, r0
    store 5007, r0
    store 5008, r0
    store 5009, r0

    store Vez, r0
    store 4010, r0
    loadn r6, #0

    cls
    call DesenhaMapa
    call Vencedor
    call DesenhaHash
    call DesenhaPosicoes

    rts
;********************************************************



;********************************************************
;                  PRESS ENTER PARTIDA
;********************************************************
PressEnterPartida:

    push r1
    push r2
    push r3
    push r4
    push r5
    push r6
    push r7

    Loop_PressEnterPartida:
        loadn r0, #762
        loadn r1, #PressEnterPartidaSTR
        loadn r2, #2816
        loadn r3, #'\0'
        call Imprime_String

        loadn r6, #90
        call Delay

        loadn r0, #19
        call ApagaLinha

        loadn r6, #90
        call Delay

        inchar r7
        loadn r1, #13
        cmp r7, r1
        jne Loop_PressEnterPartida
        jeq Loop_PressEnterPartida_Sai

    Loop_PressEnterPartida_Sai:
        call Reinicio
        call PosicaoEscolhida

    rts
;********************************************************


;********************************************************
;               LINHA VENCEDOR VERTICAL
;********************************************************
LinhaVencedorVertical:

    push r0
    push r1

    loadn r1, #40
    loadn r3, #'|'
    loadn r4, #15
    loadn r7, #0

    DesenhandoLinhaVencedorVertical:
        outchar r3, r2
        add r2, r2, r1
        inc r7
        cmp r4, r7
        jne DesenhandoLinhaVencedorVertical

    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;               LINHA VENCEDOR HORIZONTAL
;********************************************************
LinhaVencedorHorizontal:

    push r0
    push r1

    loadn r0, #1
    loadn r3, #'-'
    loadn r4, #20
    loadn r7, #0

    DesenhandoLinhaVencedorHorizontal:
        outchar r3, r2
        add r2, r2, r0
        inc r7
        cmp r4, r7
        jne DesenhandoLinhaVencedorHorizontal

    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;               LINHA VENCEDOR DIAGONAL 1
;********************************************************
LinhaVencedorDiagonal1:

    push r0
    push r1

    loadn r0, #1
    loadn r1, #41
    loadn r2, #133
    loadn r3, #'\\'
    loadn r4, #15
    loadn r7, #0

    DesenhandoLinhaVencedorDiagonal1:
        outchar r3, r2
        add r2, r2, r1
        inc r7
        cmp r4, r7
        jne DesenhandoLinhaVencedorDiagonal1

    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;               LINHA VENCEDOR DIAGONAL 2
;********************************************************
LinhaVencedorDiagonal2:

    push r0
    push r1

    loadn r0, #1
    loadn r1, #39
    loadn r2, #148
    loadn r3, #'/'
    loadn r4, #15
    loadn r7, #0

    DesenhandoLinhaVencedorDiagonal2:
        outchar r3, r2
        add r2, r2, r1
        inc r7
        cmp r4, r7
        jne DesenhandoLinhaVencedorDiagonal2

    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;                       VENCEDOR
;********************************************************
Vencedor:

    push r0
    push r1
    push r2
    push r3
    push r4

    TestandoVencedor:
        load r0, 4000
        load r1, 5010
        cmp r0, r1
        jeq Jogador1Venceu

        load r1, 5011
        cmp r0, r1
        jeq Jogador2Venceu
        jmp NenhumVencedorAinda

    Jogador1Venceu:
        call Jogador1Vence

    Jogador2Venceu:
        call Jogador2Vence

    NenhumVencedorAinda:
        pop r4
        pop r3
        pop r2
        pop r1
        pop r0

    rts
;********************************************************



;********************************************************
;                  DESENHANDO POSIÇÕES
;********************************************************
DesenhaPosicoes:

    push r0
    push r1
    push r2
    push r3
    push r4

    loadn r4, #3584

    call posicao_desenho_1
    call posicao_desenho_2
    call posicao_desenho_3
    call posicao_desenho_4
    call posicao_desenho_5
    call posicao_desenho_6
    call posicao_desenho_7
    call posicao_desenho_8
    call posicao_desenho_9


    pop r4
    pop r3
    pop r2
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;                    IMPRIME STRING
;********************************************************
Imprime_String:

    push r0
    push r1
    push r2
    push r3
    push r4

    Loop_Imprime:
        loadi r4, r1
        cmp r4, r3
        jeq Sai_Imprime
        add r4, r2, r4
        outchar r4, r0
        inc r0
        inc r1
        jmp Loop_Imprime

    Sai_Imprime:
        pop r4
        pop r3
        pop r2
        pop r1
        pop r0

    rts
;********************************************************



;********************************************************
;                       APAGA LINHA
;********************************************************
ApagaLinha:

    push r0
    push r1
    push r2
    push r3

    loadn r1, #40
    mul r0, r0, r1
    loadn r1, #1
    add r0, r0, r1
    loadn r2, #' '
    loadn r3, #39

    Loop_ApagaLinha:
        outchar r2, r0
        inc r0
        inc r1
        cmp r1, r3
        jle Loop_ApagaLinha

    pop r3
    pop r2
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;                          DELAY
;********************************************************
Delay:
    push r0

    loadn r0, #1000000
    mul r6, r6, r0
    loadn r0, #0
    Loop_Delay:
        dec r6
        cmp r6, r0
        jgr Loop_Delay
        jeq Tempo_Fim


    Tempo_Fim:
        pop r0

    rts
;********************************************************



;********************************************************
;                       POSIÇÃO 1
;********************************************************
posicao_desenho_1:
    push r0
    push r1
    push r2
    push r3
    push r4

    loadn r0, #134
    loadn r1, #120
    loadn r2, #'_'
    add r2, r2, r4
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0

    loadn r0, #173
    loadn r2, #'/'
    add r2, r2, r4
    outchar r2, r0

    loadn r0, #175
    loadn r2, #'|'
    loadn r1, #40
    add r2, r2, r4
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    dec r0
    dec r0
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    inc r0
    inc r0
    outchar r2, r0

    pop r4
    pop r3
    pop r2
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;                       POSIÇÃO 2
;********************************************************
posicao_desenho_2:
    push r0
    push r1
    push r2
    push r3
    push r4

    loadn r0, #140
    loadn r2, #'_'
    add r2, r2, r4
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0
    loadn r0, #180
    outchar r2, r0
    loadn r0, #260
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0

    loadn r0, #179
    loadn r2, #'|'
    add r2, r2, r4
    outchar r2, r0
    loadn r0, #263
    outchar r2, r0

    loadn r0, #183
    loadn r2, #')'
    add r2, r2, r4
    outchar r2, r0

    loadn r0, #220
    loadn r1, #2
    loadn r2, #'/'
    add r2, r2, r4
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    loadn r0, #259
    outchar r2, r0

    pop r4
    pop r3
    pop r2
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;                       POSIÇÃO 3
;********************************************************
posicao_desenho_3:
    push r0
    push r1
    push r2
    push r3
    push r4

    loadn r0, #146
    loadn r1, #40
    loadn r2, #'_'
    add r2, r2, r4
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0
    loadn r0, #186
    outchar r2, r0
    inc r0
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    loadn r0, #266
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0

    loadn r0, #185
    loadn r2, #'|'
    add r2, r2, r4
    outchar r2, r0
    add r0, r0, r1
    inc r0
    outchar r2, r0
    add r0, r0, r1
    dec r0
    outchar r2, r0

    loadn r0, #229
    loadn r2, #'\\'
    add r2, r2, r4
    outchar r2, r0

    loadn r0, #189
    loadn r1, #80
    loadn r2, #'/'
    add r2, r2, r4
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0

    pop r4
    pop r3
    pop r2
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;                       POSIÇÃO 4
;********************************************************
posicao_desenho_4:
    push r0
    push r1
    push r2
    push r3
    push r4

    loadn r0, #332
    loadn r1, #78
    loadn r2, #'_'
    add r2, r2, r4
    outchar r2, r0
    inc r0
    inc r0
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    inc r0
    inc r0
    inc r0
    outchar r2, r0
    loadn r0, #454
    outchar r2, r0

    loadn r0, #371
    loadn r1, #2
    loadn r2, #'|'
    add r2, r2, r4
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    loadn r0, #453
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0

    loadn r0, #411
    loadn r1, #5
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0

    pop r4
    pop r3
    pop r2
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;                       POSIÇÃO 5
;********************************************************
posicao_desenho_5:
    push r0
    push r1
    push r2
    push r3
    push r4

    loadn r0, #340
    loadn r1, #39
    loadn r2, #'_'
    add r2, r2, r4
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0

    add r0, r0, r1
    outchar r2, r0
    inc r0
    outchar r2, r0

    dec r1
    add r0, r0, r1
    outchar r2, r0
    inc r0
    outchar r2, r0

    inc r1
    add r0, r0, r1
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0

    loadn r0, #379
    loadn r1, #40
    loadn r2, #'|'
    add r2, r2, r4
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    loadn r0, #383
    outchar r2, r0

    add r0, r0, r1
    loadn r2, #'\\'
    add r2, r2, r4
    outchar r2, r0

    add r0, r0, r1
    loadn r2, #'/'
    add r2, r2, r4
    outchar r2, r0

    pop r4
    pop r3
    pop r2
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;                       POSIÇÃO 6
;********************************************************
posicao_desenho_6:
    push r0
    push r1
    push r2
    push r3
    push r4

    loadn r0, #347
    loadn r1, #80
    loadn r2, #'_'
    add r2, r2, r4
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    loadn r1, #39
    add r0, r0, r1
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0

    loadn r0, #386
    loadn r1, #77
    loadn r2, #'/'
    add r2, r2, r4
    outchar r2, r0
    inc r0
    inc r0
    outchar r2, r0
    loadn r0, #425
    outchar r2, r0
    loadn r0, #469
    outchar r2, r0

    loadn r0, #465
    loadn r1, #36
    loadn r2, #'\\'
    add r2, r2, r4
    outchar r2, r0
    sub r0, r0, r1
    outchar r2, r0

    pop r4
    pop r3
    pop r2
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;                       POSIÇÃO 7
;********************************************************
posicao_desenho_7:
    push r0
    push r1
    push r2
    push r3
    push r4

    loadn r0, #532
    loadn r2, #'_'
    add r2, r2, r4
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0
    loadn r0, #572
    outchar r2, r0
    inc r0
    outchar r2, r0
    loadn r0, #653
    outchar r2, r0

    loadn r0, #571
    loadn r2, #'|'
    add r2, r2, r4
    outchar r2, r0

    loadn r0, #576
    loadn r1, #37
    loadn r2, #'/'
    add r2, r2, r4
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    inc r0
    inc r0
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    inc r0
    inc r0
    outchar r2, r0

    pop r4
    pop r3
    pop r2
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;                       POSIÇÃO 8
;********************************************************
posicao_desenho_8:
    push r0
    push r1
    push r2
    push r3
    push r4

    loadn r0, #540
    loadn r1, #39
    loadn r2, #'_'
    add r2, r2, r4
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    inc r0
    add r0, r0, r1
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0

    loadn r0, #579
    loadn r1, #36
    loadn r2, #'('
    add r2, r2, r4
    outchar r2, r0

    loadn r0, #583
    loadn r1, #36
    loadn r2, #')'
    add r2, r2, r4
    outchar r2, r0

    loadn r0, #659
    loadn r1, #36
    loadn r2, #'\\'
    add r2, r2, r4
    outchar r2, r0
    sub r0, r0, r1
    outchar r2, r0

    loadn r0, #663
    loadn r1, #44
    loadn r2, #'/'
    add r2, r2, r4
    outchar r2, r0
    sub r0, r0, r1
    outchar r2, r0

    pop r4
    pop r3
    pop r2
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;                       POSIÇÃO 9
;********************************************************
posicao_desenho_9:
    push r0
    push r1
    push r2
    push r3
    push r4

    loadn r0, #546
    loadn r1, #39
    loadn r2, #'_'
    add r2, r2, r4
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    loadn r1, #41
    add r0, r0, r1
    outchar r2, r0

    loadn r0, #585
    loadn r2, #'/'
    add r2, r2, r4
    outchar r2, r0
    loadn r1, #44
    add r0, r0, r1
    outchar r2, r0
    loadn r1, #37
    add r0, r0, r1
    outchar r2, r0
    inc r0
    inc r0
    outchar r2, r0

    loadn r0, #589
    loadn r1, #36
    loadn r2, #'\\'
    add r2, r2, r4
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0

    pop r4
    pop r3
    pop r2
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;                       DESENHA X
;********************************************************
posicao_desenho_X:
    push r0

    loadn r2, #'_'
    loadn r4, #1024
    add r2, r2, r4
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    inc r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0

    loadn r1, #119
    add r0, r0, r1
    outchar r2, r0
    dec r0
    dec r0
    dec r0
    outchar r2, r0

    dec r0
    loadn r2, #'/'
    add r2, r2, r4
    outchar r2, r0
    inc r0
    inc r0
    outchar r2, r0
    loadn r1, #77
    sub r0, r0, r1
    outchar r2, r0
    dec r0
    dec r0
    outchar r2, r0

    dec r0
    loadn r2, #'\\'
    add r2, r2, r4
    outchar r2, r0
    dec r0
    dec r0
    outchar r2, r0

    loadn r1, #83
    add r0, r0, r1
    outchar r2, r0
    inc r0
    inc r0
    outchar r2, r0

    loadn r1, #41
    sub r0, r0, r1
    loadn r2, #'<'
    add r2, r2, r4
    outchar r2, r0

    loadn r1, #3
    sub r0, r0, r1
    loadn r2, #'>'
    add r2, r2, r4
    outchar r2, r0

    pop r0

    rts
;********************************************************



;********************************************************
;                       DESENHA O
;********************************************************
posicao_desenho_O:
    push r0

    inc r0
    loadn r1, #120
    loadn r2, #'_'
    loadn r4, #2304
    add r2, r2, r4
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0

    add r0, r0, r1
    outchar r2, r0
    dec r0
    outchar r2, r0
    dec r0
    outchar r2, r0

    dec r0
    loadn r1, #76
    add r2, r2, r4
    loadn r2, #'\\'
    add r2, r2, r4
    outchar r2, r0
    sub r0, r0, r1
    outchar r2, r0

    loadn r1, #4
    sub r0, r0, r1
    loadn r2, #'/'
    add r2, r2, r4
    outchar r2, r0
    loadn r1, #84
    add r0, r0, r1
    outchar r2, r0

    loadn r1, #40
    sub r0, r0, r1
    loadn r2, #'|'
    add r2, r2, r4
    outchar r2, r0
    loadn r1, #2
    sub r0, r0, r1
    outchar r2, r0
    sub r0, r0, r1
    outchar r2, r0

    pop r0

    rts
;********************************************************



;********************************************************
;             POSIÇÃO 1 - ESCOLHA DE JOGADA
;********************************************************
posicao_desenho_1_escolha_jogada:
    push r0
    push r1
    push r2
    push r3
    push r4

    loadn r0, #488
    loadn r1, #120
    loadn r2, #'_'
    add r2, r2, r4
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0

    loadn r0, #527
    loadn r2, #'/'
    add r2, r2, r4
    outchar r2, r0

    loadn r0, #529
    loadn r2, #'|'
    loadn r1, #40
    add r2, r2, r4
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    dec r0
    dec r0
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    inc r0
    inc r0
    outchar r2, r0

    pop r4
    pop r3
    pop r2
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;             POSIÇÃO 3 - ESCOLHA DE JOGADA
;********************************************************
posicao_desenho_3_escolha_jogada:
    push r0
    push r1
    push r2
    push r3
    push r4

    loadn r0, #498
    loadn r1, #40
    loadn r2, #'_'
    add r2, r2, r4
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0
    loadn r0, #538
    outchar r2, r0
    inc r0
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    loadn r0, #618
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0

    loadn r0, #537
    loadn r2, #'|'
    add r2, r2, r4
    outchar r2, r0
    add r0, r0, r1
    inc r0
    outchar r2, r0
    add r0, r0, r1
    dec r0
    outchar r2, r0

    loadn r0, #581
    loadn r2, #'\\'
    add r2, r2, r4
    outchar r2, r0

    loadn r0, #541
    loadn r1, #80
    loadn r2, #'/'
    add r2, r2, r4
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0

    pop r4
    pop r3
    pop r2
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;             POSIÇÃO 5 - ESCOLHA DE JOGADA
;********************************************************
posicao_desenho_5_escolha_jogada:
    push r0
    push r1
    push r2
    push r3
    push r4

    loadn r0, #510
    loadn r1, #39
    loadn r2, #'_'
    add r2, r2, r4
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0

    add r0, r0, r1
    outchar r2, r0
    inc r0
    outchar r2, r0

    dec r1
    add r0, r0, r1
    outchar r2, r0
    inc r0
    outchar r2, r0

    inc r1
    add r0, r0, r1
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0

    loadn r0, #549
    loadn r1, #40
    loadn r2, #'|'
    add r2, r2, r4
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    loadn r0, #553
    outchar r2, r0

    add r0, r0, r1
    loadn r2, #'\\'
    add r2, r2, r4
    outchar r2, r0

    add r0, r0, r1
    loadn r2, #'/'
    add r2, r2, r4
    outchar r2, r0

    pop r4
    pop r3
    pop r2
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;                  POSIÇÃO 1 - VENCEDOR
;********************************************************
posicao_desenho_1_vencedor:
    push r0
    push r1
    push r2
    push r3
    push r4

    loadn r0, #459
    loadn r1, #120
    loadn r2, #'_'
    add r2, r2, r4
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0

    loadn r0, #498
    loadn r2, #'/'
    add r2, r2, r4
    outchar r2, r0

    loadn r0, #500
    loadn r2, #'|'
    loadn r1, #40
    add r2, r2, r4
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    dec r0
    dec r0
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    inc r0
    inc r0
    outchar r2, r0

    loadn r6, #90
    call Delay

    pop r4
    pop r3
    pop r2
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;                  POSIÇÃO 2 - VENCEDOR
;********************************************************
posicao_desenho_2_vencedor:
    push r0
    push r1
    push r2
    push r3
    push r4

    loadn r0, #458
    loadn r2, #'_'
    add r2, r2, r4
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0
    loadn r0, #498
    outchar r2, r0
    loadn r0, #578
    outchar r2, r0
    inc r0
    outchar r2, r0
    inc r0
    outchar r2, r0

    loadn r0, #497
    loadn r2, #'|'
    add r2, r2, r4
    outchar r2, r0
    loadn r0, #581
    outchar r2, r0

    loadn r0, #501
    loadn r2, #')'
    add r2, r2, r4
    outchar r2, r0

    loadn r0, #538
    loadn r1, #2
    loadn r2, #'/'
    add r2, r2, r4
    outchar r2, r0
    add r0, r0, r1
    outchar r2, r0
    loadn r0, #577
    outchar r2, r0

    loadn r6, #90
    call Delay

    pop r4
    pop r3
    pop r2
    pop r1
    pop r0

    rts
;********************************************************



;********************************************************
;                   DESENHA PONTUAÇÃO
;********************************************************
Desenha_pontuacao:
    load r1, 5010
    loadn r2, #'0'
    add r2, r2, r1          ;convertendo para char
    loadn r0, #1087
    outchar r2, r0

    load r1, 5011
    loadn r2, #'0'
    add r2, r2, r1          ;convertendo para char
    loadn r0, #1112
    outchar r2, r0
rts
;********************************************************



;********************************************************
;                     ATUALIZA VEZ
;********************************************************
Atualiza_vez:
    load r1, Vez
    loadn r2, #0
    cmp r2, r1
    jeq vez_1       ;0 para player 1
    jne vez_2       ;1 para player 2

    vez_1:
        loadn r0, #1026
        loadn r2, #' '
        outchar r2, r0
        loadn r0, #1002
        loadn r2, #'>'
        loadn r4, #2304
        add r2, r2, r4
        outchar r2, r0
        inc r1
        store Vez, r1
        rts

    vez_2:
        loadn r0, #1002
        loadn r2, #' '
        outchar r2, r0
        loadn r0, #1026
        loadn r2, #'>'
        loadn r4, #2304
        add r2, r2, r4
        outchar r2, r0
        dec r1
        store Vez, r1
        rts
;********************************************************



;********************************************************
;                  JOGADOR 1 VENCE
;********************************************************
Jogador1Vence:

    loadn r0, #0
    store 5010, r0       ; Zerando o placar
    store 5011, r0

    call FimDeJogo

    Player1Wins:
        inchar r7
        loadn r5, #13
        loadn r6, #90

        loadn r2, #2304
        loadn r3, #'\0'
        call DesenhaPlayer
        loadn r4, #2304
        call posicao_desenho_1_vencedor

        loadn r2, #3072
        loadn r3, #'\0'
        call DesenhaPlayer
        loadn r4, #3072
        call posicao_desenho_1_vencedor

        loadn r2, #512
        loadn r3, #'\0'
        call DesenhaPlayer
        loadn r4, #512
        call posicao_desenho_1_vencedor

        loadn r2, #2816
        loadn r3, #'\0'
        call DesenhaPlayer
        loadn r4, #2816
        call posicao_desenho_1_vencedor

        cmp r5, r7
        jeq Recomecando1
        jmp Player1Wins

    Recomecando1:
        cls
        call main

    rts
;********************************************************



;********************************************************
;                  JOGADOR 2 VENCE
;********************************************************
Jogador2Vence:

    loadn r0, #0
    store 5010, r0       ; Zerando o placar
    store 5011, r0

    call FimDeJogo

    Player2Wins:
        inchar r7
        loadn r5, #13
        loadn r6, #90

        loadn r2, #2304
        loadn r3, #'\0'
        call DesenhaPlayer
        loadn r4, #2304
        call posicao_desenho_2_vencedor

        loadn r2, #3072
        loadn r3, #'\0'
        call DesenhaPlayer
        loadn r4, #3072
        call posicao_desenho_2_vencedor

        loadn r2, #512
        loadn r3, #'\0'
        call DesenhaPlayer
        loadn r4, #512
        call posicao_desenho_2_vencedor

        loadn r2, #2816
        loadn r3, #'\0'
        call DesenhaPlayer
        loadn r4, #2816
        call posicao_desenho_2_vencedor

        cmp r5, r7
        jeq Recomecando2
        jmp Player2Wins

    Recomecando2:
        cls
        call main

    rts
;********************************************************



;********************************************************
;                      FIM DE JOGO
;********************************************************
FimDeJogo:

    loadn r0, #1007
    loadn r1, #FimDeJogoSTR
    loadn r2, #3584
    loadn r3, #'\0'
    call Imprime_String

    rts
;********************************************************



;********************************************************
;                   DESENHA PLAYER
;********************************************************
DesenhaPlayer:

    loadn r0, #81
    loadn r1, #MensagemPlayer1
    loadn r3, #'\0'
    call Imprime_String

    loadn r0, #121
    loadn r1, #MensagemPlayer2
    call Imprime_String

    loadn r0, #161
    loadn r1, #MensagemPlayer3
    call Imprime_String

    loadn r0, #201
    loadn r1, #MensagemPlayer4
    call Imprime_String

    loadn r0, #241
    loadn r1, #MensagemPlayer5
    call Imprime_String

    loadn r0, #281
    loadn r1, #MensagemPlayer6
    call Imprime_String

    call DesenhaWins

rts
;********************************************************



;********************************************************
;                   DESENHA WINS
;********************************************************
DesenhaWins:

    loadn r0, #684
    loadn r1, #MensagemVencedor1
    loadn r3, #'\0'
    call Imprime_String

    loadn r0, #724
    loadn r1, #MensagemVencedor2
    call Imprime_String

    loadn r0, #764
    loadn r1, #MensagemVencedor3
    call Imprime_String

    loadn r0, #804
    loadn r1, #MensagemVencedor4
    call Imprime_String

    loadn r0, #844
    loadn r1, #MensagemVencedor5
    call Imprime_String

    loadn r0, #884
    loadn r1, #MensagemVencedor6
    call Imprime_String

rts
;********************************************************