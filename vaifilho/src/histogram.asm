// histogram.s
//
// Created by Gabriel Guerrero
//
// March 2021

#define VALUE_64K 0x100000
#define HIST_SIZE 256
	.syntax unified
	.text
	.align 2
	.global EightBitHistogram
	.thumb_func


EightBitHistogram:
	PUSH {R4,LR}	//return address is saved so lr can be used for scratch
	MUL R0, R0, R1
	CMP R0, #VALUE_64K
	ITT HS
	MOVHS R0, #0
	BHS ret
	ADD R1, R3, #(HIST_SIZE <<2) //r1 = address of last element of histogram[] +2
	MOV R12, #0
	//clear histogram[]
loop:
	CMP R3,R1 //compara R1 (final do vetor) com R3 (começo do vetor)
	IT EQ
	BEQ limpazero
	LDR LR, [R1]
	MOV LR, #0
	STR LR, [R1],#-4
	B   loop
	//calculate histogram[]
	//PUSH {R4}
limpazero:
	//LIMPA ZERO
	LDR LR, [R3]
	MOV LR, #0
	STR LR, [R3]
varrematriz:
	CMP R0,R12 // COMPARA O TAMANHO DA MATRIZ COM O I
	IT	EQ //SE IGUAL, PARA LOOP
	BEQ ret
	LDRB R4, [R2], #1 //CARREGA EM R4 O VALOR DO PIXEL DA IMAGEM E ATUALIZA PARA O PRÓXIMO
	LSL R4, 1 //MULTIPLICA POR 4 PARA ENCONTRAR O VALOR DO VETOR CORRESPONDENTE
	ADD R3, R1, R4 //SOMA A BASE COM O VALOR DO PIXEL
	LDR LR, [R3] //TIRA O +2
	ADD LR, #1 // VALOR++
	STRH LR,[R3] //GUARDA NOVAMENTE NO VETOR
	ADD R12, #1	//ATUALIZA CONTADOR
	B varrematriz //LOOP
	//return histogram[]
ret:
	POP {R4,LR}	//DEVOLVE R4 E LT
	MOV R0,R1 //POSICIONA PONTEIRO PARA RETORNO

	BX LR //RETURN

