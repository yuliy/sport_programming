#!/usr/bin/env escript
-export([main/1]).

is_prime_ex(N, CurDivisor) when CurDivisor < N ->
    Rem = N rem CurDivisor,
    %io:format("~p rem ~p = ~p~n", [N, CurDivisor, Rem]),
    case Rem of
        0 -> false;
        _ -> is_prime_ex(N, CurDivisor + 1)
    end;
is_prime_ex(N, CurDivisor) when CurDivisor =:= N ->
    true.

is_prime(N) ->
    MinDivisor = erlang:round( math:sqrt(N) ),
    is_prime_ex(N, MinDivisor).

calc_nth_prime(IndexOfPrimeToFind, CurIndex, N) when CurIndex =:= IndexOfPrimeToFind ->
    N;
calc_nth_prime(IndexOfPrimeToFind, CurIndex, N) when CurIndex < IndexOfPrimeToFind ->
    case is_prime(N) of
        true -> calc_nth_prime(IndexOfPrimeToFind, CurIndex + 1, N + 1);
        false -> calc_nth_prime(IndexOfPrimeToFind, CurIndex, N + 1)
    end,
    N.

main(_) ->
    io:fwrite("Running problem007...~n"),
    IndexOfPrimeToFind = 1001,
    Res = calc_nth_prime(IndexOfPrimeToFind, 1, 2),
    io:format("Answer: ~w~n", [Res]),
    io:fwrite("Done.~n").
