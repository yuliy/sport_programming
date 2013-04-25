-module(problem002).
-export([solve/2]).

solve({PNum, PSum}, {PPNum, PPSum}) when PFibNum == 1; PPFibNum == 1 ->
    {2, 0};
solve({PNum, PSum}, {PPNum, PPSum}) ->
    Num = PNum + PPNum.
    case Num rem 2 of
        0 -> {Num, PSum + Num};
        1 -> {Num, PSum};
    end.
