-module(problem001).
-export([solve/1]).

% solve routine calculates sum of all natural numbers <= N which are multiples of 3 or 5

solve(N) when N == 0 ->
    0;
solve(N) when N rem 3 == 0 ->
    N + solve(N-1);
solve(N) when N rem 5 == 0 ->
    N + solve(N-1);
solve(N) ->
    solve(N-1).
