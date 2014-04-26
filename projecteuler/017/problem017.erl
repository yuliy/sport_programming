#!/usr/bin/env escript
-export([main/1]).

to_human_readable(Num) when Num < 10 ->
    case Num of
        0 -> "";
        1 -> "one";
        2 -> "two";
        3 -> "three";
        4 -> "four";
        5 -> "five";
        6 -> "six";
        7 -> "seven";
        8 -> "eight";
        9 -> "nine"
    end;
to_human_readable(Num) when Num < 20 ->
    case Num of
        11 -> "eleven";
        12 -> "twelve";
        13 -> "therteen";
        14 -> "fourteen";
        15 -> "fifteen";
        16 -> "sixteen";
        17 -> "seventeen";
        18 -> "eighteen";
        19 -> "nineteen"
    end;
to_human_readable(Num) when Num < 100 ->
    D = Num div 10,
    HD = case D of
        2 -> "twenty";
        3 -> "thirty";
        4 -> "forty";
        5 -> "fifty";
        6 -> "sixty";
        7 -> "seventy";
        8 -> "eighty";
        9 -> "ninety"
    end,
    Suf = string:concat(" ", to_human_readable(Num rem 10)),
    string:concat(HD, Suf).

calc_size([H | Tail]) ->
    case H of
        32 -> calc_size(Tail);
        _ -> 1 + calc_size(Tail)
    end;
calc_size([]) ->
    0.

solve(N) ->
    Str = to_human_readable(N),
    Size = calc_size(Str),
    io:format("~p: ~p (size=~p)~n", [N, Str, Size]),
    case N of
        1 -> N;
        _ -> solve(N-1)
    end.
%solve(1) ->
%    Str = to_human_readable(1),
%    Size = calc_size(Str),
%    io:format("~p: ~p (size=~p)~n", [1, Str, Size]).

main(_) ->
    io:fwrite("Running problem017...~n"),
    N = 99,
    Res = solve(N),
    io:format("Answer: ~w~n", [Res]),
    io:fwrite("Done.~n").
