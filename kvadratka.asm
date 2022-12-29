in
in
in
popr cx
popr bx
popr ax
pushr ax
pushr cx
push -4
mul
mul
pushr bx
pushr bx
mul
add
sqrt
popr dx
push 2
pushr ax
mul
pushr dx
jmp :1
:2
push 2
pushr ax
mul
pushr dx
push -1
mul
pushr bx
push -1
mul
add
div
out
ret
:1
pushr bx
push -1
mul
add
div
out
call :2
hlt
