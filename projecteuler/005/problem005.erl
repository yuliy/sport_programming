#!/usr/bin/env escript
-export([main/1]).

is_evenly_divisible(Num) ->
    case Num of
        _ when Num rem 20 =/= 0 -> false;
        _ when Num rem 19 =/= 0 -> false;
        _ when Num rem 18 =/= 0 -> false;
        _ when Num rem 17 =/= 0 -> false;
        _ when Num rem 16 =/= 0 -> false;
        _ when Num rem 15 =/= 0 -> false;
        _ when Num rem 14 =/= 0 -> false;
        _ when Num rem 13 =/= 0 -> false;
        _ when Num rem 12 =/= 0 -> false;
        _ when Num rem 11 =/= 0 -> false;
        _ when Num rem 9 =/= 0 -> false;
        _ when Num rem 8 =/= 0 -> false;
        _ when Num rem 7 =/= 0 -> false;
        _ when Num rem 6 =/= 0 -> false;
        _ when Num rem 3 =/= 0 -> false;
        _ -> true
    end.

find_smallest_evenly_divisible(N) ->
    IsED = is_evenly_divisible(N),
    case IsED of
        true -> N;
        false -> find_smallest_evenly_divisible(N+20)
    end.

main(_) ->
    io:fwrite("Running problem005...~n"),
    Res = find_smallest_evenly_divisible(20),
    io:format("Answer: ~w~n", [Res]),
    io:fwrite("Done.~n").
