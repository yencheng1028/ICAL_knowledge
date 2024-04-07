set(var hello)
set(foo var)

message(${foo})
message(${${foo}})
