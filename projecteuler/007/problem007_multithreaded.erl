#!/usr/bin/env escript
-export([main/1]).

is_prime_ex(N, CurDivisor) when CurDivisor < N ->
    Rem = N rem CurDivisor,
    case Rem of
        0 -> false;
        _ -> is_prime_ex(N, CurDivisor + 1)
    end;
is_prime_ex(N, CurDivisor) when CurDivisor =:= N ->
    true.

is_prime(N) ->
    MinDivisor = erlang:round( math:sqrt(N) ),
    is_prime_ex(N, MinDivisor).

slave_proc(MasterPID) ->
    ChildPID = self(),
    receive
        {stop} -> ChildPID;
        {calc_is_prime, N} ->
            %io:format("[SLAVE]: {calc_is_prime, ~p}~n", [N]),
            Res = is_prime(N),
            MasterPID ! {is_prime_result, ChildPID, N, Res},
            %io:format("[SLAVE]: Result: {is_prime_result, ~p, ~p, ~p}~n", [ChildPID, N, Res]),
            slave_proc(MasterPID);
        Message ->
            io:format("[SLAVE]: Invalid message format: ~p~n", [Message])
    end.

create_pool(_MasterPID, Size) when Size =:= 0 ->
    [];
create_pool(MasterPID, Size) when Size > 0 ->
    SlavePID = spawn(fun() -> slave_proc(MasterPID) end),
    [SlavePID, create_pool(MasterPID, Size - 1)].

run_pool([], _N) ->
    true;
run_pool([SlavePID, Pool], N) ->
    SlavePID ! {calc_is_prime, N},
    run_pool(Pool, N + 1),
    true.

calc_prime(IndexOfPrimeToFind, CurPrimeIndex, N, _MaxCalculatedN) when CurPrimeIndex =:= IndexOfPrimeToFind ->
    N;
calc_prime(IndexOfPrimeToFind, CurPrimeIndex, N, MaxCalculatedN) when CurPrimeIndex < IndexOfPrimeToFind ->
    receive
        {is_prime_result, ChildPID, N, true} ->
            io:format("[MASTER]: N=~p CurPrimeIndex=~p MaxCalculatedN=~p ~n", [N, CurPrimeIndex, MaxCalculatedN]),
            ChildPID ! {calc_is_prime, MaxCalculatedN + 1},
            calc_prime(IndexOfPrimeToFind, CurPrimeIndex + 1, N + 1, MaxCalculatedN + 1);
        {is_prime_result, ChildPID, N, false} ->
            %io:format("[MASTER]: N=~p CurPrimeIndex=~p MaxCalculatedN=~p ~n", [N, CurPrimeIndex, MaxCalculatedN]),
            ChildPID ! {calc_is_prime, MaxCalculatedN + 1},
            calc_prime(IndexOfPrimeToFind, CurPrimeIndex + 0, N + 1, MaxCalculatedN + 1)
        %Message ->
        %    io:format("[MASTER]: Invalid message format: ~p~n", [Message])
    after
            1 ->
                %io:format("Ping~n"),
                calc_prime(IndexOfPrimeToFind, CurPrimeIndex, N, MaxCalculatedN)
    end.

main(_) ->
    io:fwrite("Running problem007...~n"),
    IndexOfPrimeToFind = 10001,
    PoolSize = 1000,

    MasterPID = self(),
    Pool = create_pool(MasterPID, PoolSize),
    run_pool(Pool, 2),
    Res = calc_prime(IndexOfPrimeToFind, 1, 2, PoolSize),

    io:format("Answer: ~w~n", [Res]),
    io:fwrite("Done.~n").
