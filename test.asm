in
popr dx
pushr dx

:1
popr ax
pushr ax
push -1
add
pushr dx
mul
popr dx
pushr ax
push -1
add
push 1
pushr ax
push -1
add

ja :1
pushr dx
out
hlt






; int fact (int n)
; {
;     if (n  == 1)
;     {
;         return 1;
;     }
;
;     int res = fact (n - 1) * n;
;     return res;
; }
