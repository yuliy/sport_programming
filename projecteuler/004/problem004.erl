#!/usr/bin/env escript
-export([main/1]).

int2list_ex(N, List) ->
    case N of
        _ when N < 10 -> [N | List];
        _ -> int2list_ex(N div 10, [N rem 10 | List])
    end.

int2list(N) ->
    int2list_ex(N, []).

is_palindrome([]) ->
    true;
is_palindrome([First | Tail]) ->
    RTail = lists:reverse(Tail),
    case RTail of
        [] -> true;
        [Last | Middle] when First =:= Last ->
            is_palindrome(Middle);
        [_ | _] ->
            false
    end.

is_palindrome_num(N) ->
    is_palindrome( int2list(N) ).

solve(I, J, Max, Res) ->
    ISP = is_palindrome_num(I * J),
    NewRes = case ISP of
        true -> max(Res, I * J);
        false -> Res
    end,
    case [I, J] of
        [Max, Max] -> NewRes;
        [_, Max] -> solve(I+1, Max, Max, NewRes);
        [Max, _] -> solve(0, J+1, Max, NewRes);
        [_, _] -> solve(I+1, J, Max, NewRes)
    end.

main(_) ->
    io:fwrite("Running problem004...~n"),
    io:format("Answer: ~p~n", [solve(1, 1, 999, 0)]),
    io:fwrite("Done.~n").
