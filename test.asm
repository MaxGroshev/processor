jmp :2
:1
push 10
ret
:2
push 5
push 20
add
popr ax
call :1
out
push 12
push 5
push 12
pushr ax
mul
div
out
hlt

