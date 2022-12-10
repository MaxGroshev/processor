push 10
push 5
push 20
add
popr ax
push 12
jmp :4
push 5
:4
pushr ax
mul
out
hlt

