# 當 expr 值為下列其中之一時，執行 command1：
#    ON, 1, YES, TRUE, Y
# 當 expr 值為下列其中之一時，執行 command2：
#    OFF, 0, NO, FALSE, N, NOTFOUND, *-NOTFOUND, IGNORE

set(expr ON)
set(var1 no)
if(expr)
        message(hello)
else(expr)
        message(no)
endif(expr)

if(var1)
    message(yyyyyyy)
else()
    message(nnnnnnn)
endif(var1)


