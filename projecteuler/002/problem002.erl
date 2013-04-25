-module(problem002).
-export([solve/1]).

solve({PNum, PSum}, {PPNum, PPSum}) when PFibNum == 1; PPFibNum == 1 ->
    {2, 0};
solve({PNum, PSum}, {PPNum, PPSum}) ->
    Num = PNum + PPNum.
    if
        Num rem 2 == 0 -> {Num, PSum + Num};
        Num rem 2 == 1 -> {Num, PSum};
    end.
