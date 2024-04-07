set(a I am handsome)
set(b I;am;handsome)

message("${a}")
message(${a})
message(${b})


set(x I am handsome)
set(y "I am handsome")
set(z "I
am
handsome")

message("x = ${x}")
message("y = ${y}")
message("z = ${z}")
