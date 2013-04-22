-module(problem001).
-export([sum/1]).

sum(num) when num == 1 ->
    1;
sum(num) when num =/= 1 ->
    num + sum(num-1).

sum(num) ->
    case of num
        1 -> 1;
        _ -> num + sum(num-1).
    


% solve routine calculates sum of all natural numbers <= num which are multiples of 3 or 5

%solve(num) when num == 0 ->
%    0;
%solve(num) when num rem 3 == 0 ->
%    1 + solve(num-1);
%solve(num) when num rem 5 == 0 ->
%    1 + solve(num-1);
%solve(num) ->
%    solve(num-1).
