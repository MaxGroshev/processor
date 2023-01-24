in
in
in
pop cx
pop bx
pop ax
push ax
push cx
push -4
mul
mul
push bx
push bx
mul
add
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
hlt
