@echo off

REM Test 1

IF NOT EXIST test1 mkdir test1
set x=1.0
set y=1.0
set z=1.0

@echo Test1: Same initial condition
@echo x = %x%
@echo y = %y%
@echo z = %z%


lorenzAttractor --euler -x %x% -y %y% -z %z% > test1/euler.plt
lorenzAttractor --heun  -x %x% -y %y% -z %z% > test1/heun.plt
lorenzAttractor --rk    -x %x% -y %y% -z %z% > test1/rk.plt


REM Test 2

IF NOT EXIST test2 mkdir test2
set xa=1.0
set ya=1.0
set za=1.0
set xb=1.000001
set yb=1.0
set zb=1.0

@echo Test2: Same Methods, epsilon-diff x initial condition
@echo x1 = %xa%
@echo y1 = %ya%
@echo z1 = %za%

@echo x2 = %xb%
@echo y2 = %yb%
@echo z2 = %zb%


lorenzAttractor --euler -x %xa% -y %ya% -z %za% > test2/euler_a.plt
lorenzAttractor --euler -x %xb% -y %yb% -z %zb% > test2/euler_b.plt
lorenzAttractor --heun  -x %xa% -y %ya% -z %za% > test2/heun_a.plt
lorenzAttractor --heun  -x %xb% -y %yb% -z %zb% > test2/heun_b.plt
lorenzAttractor --rk    -x %xa% -y %ya% -z %za% > test2/rk_a.plt
lorenzAttractor --rk    -x %xb% -y %yb% -z %zb% > test2/rk_b.plt


REM Test 3

IF NOT EXIST test3 mkdir test3
set xa=1.0
set ya=1.0
set za=1.0
set xb=1.0
set yb=1.000001
set zb=1.0

@echo Test3: Same Methods, epsilon-diff y initial condition
@echo x1 = %xa%
@echo y1 = %ya%
@echo z1 = %za%

@echo x2 = %xb%
@echo y2 = %yb%
@echo z2 = %zb%


lorenzAttractor --euler -x %xa% -y %ya% -z %za% > test3/euler_a.plt
lorenzAttractor --euler -x %xb% -y %yb% -z %zb% > test3/euler_b.plt
lorenzAttractor --heun  -x %xa% -y %ya% -z %za% > test3/heun_a.plt
lorenzAttractor --heun  -x %xb% -y %yb% -z %zb% > test3/heun_b.plt
lorenzAttractor --rk    -x %xa% -y %ya% -z %za% > test3/rk_a.plt
lorenzAttractor --rk    -x %xb% -y %yb% -z %zb% > test3/rk_b.plt
