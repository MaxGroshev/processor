push 10
push 5
push 20
add
:1
popr ax
ret
call :1
out
jmp :4
:4
push 12
push 5
jmp :5
pushr ax
:5
mul
out
hlt

