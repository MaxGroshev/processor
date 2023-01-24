in
push 17
pop dx
push 17
pop dx
call :13
out
jmp :143
:13
pop  ax
push ax
push  1
je   :12
push ax
push -1
add
push ax
pop  bx
pop  ax
push bx
push ax
call :13
mul
:12
ret
:143
hlt
