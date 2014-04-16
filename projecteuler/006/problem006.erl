#!/usr/bin/env escript
-export([main/1]).

calc_sum_of_squares(N) when N > 1 ->
    N*N + calc_sum_of_squares(N-1);
calc_sum_of_squares(N) when N =:= 1 ->
    1.

main(_) ->
    io:fwrite("Running problem005...~n"),
    N = 100,
    SquareOfSums = N * N * (N + 1) * (N + 1) div 4,
    Res = SquareOfSums - calc_sum_of_squares(N),
    io:format("Answer: ~w~n", [Res]),
    io:fwrite("Done.~n").
