	extern printf
	extern scanf
section .data
	fmt:	db "%d",10,0
	fmt1:	db "%d",0
	fmt3:	db "%s",0
	fmt4:	db "%s",10,0

section .bss
	num resb 4
	string resb 100

section .text
	global main
main:
	push	rbp

	mov	rdi,fmt1
	mov	rsi,num
	mov	rax,0
	call	scanf

	mov	rdi,fmt
	mov	rsi,[num]
	mov	rax,0
	call	printf

	mov	rdi,fmt3
	mov	rsi,string
	mov	rax,0
	call	scanf

	mov	rdi,fmt4
	mov	rsi,string
	mov	rax,0
	call	printf

	pop rbp
	mov rax,0
	ret
