SECTION .data
msg:  db "Hello, Holberton", 0
fmt:  db "%s", 10, 0

SECTION .tect
extern printf
global main
main:
move esi, msg
mov edi, fmt
mov eax, 0
call printf

mov eax, 0
ret
