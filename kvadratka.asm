
in
in
in
pop cx
pop bx
pop ax
push ax
push 0
jne :8
push bx
push 0
je :9
push bx
push cx

push -1
mul
div
out
jmp :9
:8

push ax
push cx
push -4
mul
mul
push bx
push bx
mul
add
pop  dx
push dx
push 0
ja :9
push dx
sqrt
pop dx
push 2
push ax
mul
push dx
jmp :1
:2
push 2
push ax
mul
push dx
push -1
mul
push bx
push -1
mul
add
div
out
ret
:1
push bx
push -1
mul
add
div
out
call :2
:9
hlt
