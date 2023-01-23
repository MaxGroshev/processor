in
call :13

jmp :14
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
:14
out
hlt
