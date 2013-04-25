-module(problem002).
-export([fib/1]).

fib_ex(1) -> {1, 0};
fib_ex(2) -> {1, 1};
fib_ex(Num) ->
    {P, PP} = fib_ex(Num-1),
    {P + PP, P}.

fib(N) ->
    {P, _PP} = fib_ex(N),
    P.
