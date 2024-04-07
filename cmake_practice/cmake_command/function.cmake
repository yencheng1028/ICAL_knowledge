macro(print1 MESSAGE)
    set(k ${MESSAGE})
    message(${MESSAGE})
endmacro(print1)

function(print2 MESSAGE)
    set(k ${MESSAGE})
    message(${MESSAGE})
endfunction(print2)

print1("from print1")
print2("from print2")
message(${k})
