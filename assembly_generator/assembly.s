.intel_syntax noprefix

.text
	.globl main

main:

	push rbp
	mov rbp, rsp
	mov QWORD PTR [rbp-8], 0
	mov QWORD PTR [rbp-16], 3
	mov QWORD PTR [rbp-24], 0
	mov rax, QWORD PTR [rbp-8]
	push rax
	mov rax, 3
	pop rcx
	add rax, rcx
	mov rcx, rax
	mov rax, QWORD PTR [rbp-16]
	cmp rcx, rax
	jne label1
	mov rax, 10
	push rax
	mov rax, QWORD PTR [rbp-24]
	pop rcx
	imul rcx
	push rax
	mov rax, QWORD PTR [rbp-24]
	pop rcx
	sub rax, rcx
	mov QWORD PTR [rbp-24], rax
	jmp label2
label1:
	mov QWORD PTR [rbp-32], 4
	mov rax, QWORD PTR [rbp-32]
	push rax
	mov rax, 2
	pop rcx
	cqo
	idiv rcx
	mov rax, rdx
label2:
	pop rbp
	mov rax,0
	ret
