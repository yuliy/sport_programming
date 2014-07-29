#!/usr/bin/env escript
-export([main/1]).

is_prime_ex(N, CurDivisor, MaxDivisor) when CurDivisor =< MaxDivisor ->
    Rem = N rem CurDivisor,
    case Rem of
        0 -> false;
        _ -> is_prime_ex(N, CurDivisor + 2, MaxDivisor)
    end;
is_prime_ex(_, _, _) ->
    true.

is_prime(N) when N rem 2 =:= 0 ->
    false;
is_prime(N) ->
    MaxDivisor = erlang:round( math:sqrt(N) ),
    is_prime_ex(N, 3, MaxDivisor).


calc_nth_prime(IndexOfPrimeToFind, CurIndex, N) when CurIndex =:= IndexOfPrimeToFind ->
    N - 1;
calc_nth_prime(IndexOfPrimeToFind, CurIndex, N) when CurIndex < IndexOfPrimeToFind ->
    NewIndex = case is_prime(N) of
        true ->
            %io:format("CurIndex=~p N=~p~n", [CurIndex+1, N]),
            CurIndex + 1;
        false ->
            CurIndex
    end,
    calc_nth_prime(IndexOfPrimeToFind, NewIndex, N + 1).


main(_) ->
    io:fwrite("Running problem007...~n"),
    IndexOfPrimeToFind = 10001,
    Res = calc_nth_prime(IndexOfPrimeToFind, 1, 2),
    io:format("Answer: ~w~n", [Res]),
    io:fwrite("Done.~n").
