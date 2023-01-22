in
pop dx
push dx

:1
pop ax
push ax
push -1
add
push dx
mul
pop dx
push ax
push -1
add
push 1
push ax
push -1
add

ja :1
push dx
out
hlt

