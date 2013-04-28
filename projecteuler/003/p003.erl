-module(problem002).
-export([solve/1, fib_ex/4]).

%fib_ex(Max, Sum, P, PP) ->
%    Next = P + PP,
%    if
%        Next < Max, Next rem 2 == 0 -> fib_ex(Max, Next + Sum, Next, P);
%        Next < Max, Next rem 2 == 1 -> fib_ex(Max, Sum, Next, P);
%        Next >= Max -> Sum
%    end.

fib_ex(Max, Sum, P, PP) when P + PP >= Max ->
    Sum;
fib_ex(Max, Sum, P, PP) ->
    Next = P + PP,
    case Next rem 2 of
        0 -> fib_ex(Max, Next + Sum, Next, P);
        1 -> fib_ex(Max, Sum, Next, P)
    end.

solve(Max) ->
    fib_ex(Max, 0, 1, 1).
