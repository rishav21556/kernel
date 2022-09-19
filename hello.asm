section .bss
	string resb 100
	num resb 4

section .text
	global _start
_start:
	mov rax, 0
	mov rdi, 0
	mov rsi, num
	mov rdx, 4
	syscall
 
	mov rax, 1
	mov rdi, 1
	mov rsi, num
	mov rdx, 4
	syscall

	mov rax, 0
	mov rdi, 0
	mov rsi, string
	mov rdx, 100
	syscall

	mov rax, 1
	mov rdi, 1
	mov rsi, string
	mov rdx, 100
	syscall

	mov rax, 60
	mov rdi, 0
	syscall



