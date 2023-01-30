push 1

in
pop ax
push ax
jb :9
push 1
push ax
call :13
jmp :1

:13
pop ax
push ax
push 1
je :2
push ax
push -1
add
push ax
pop bx
pop ax
push bx
push ax
call :13
mul

:2
ret
:1
out
:9
hlt
