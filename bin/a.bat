@echo off
set Step=0.01
set MaxTime=20000
set EPS=0001

set x=10.0
set y=20.0
set z=30.0

@echo Max Time = %MaxTime%
@echo Step     = %Step%
@echo EPS      = 0.0%EPS%

REM ---------------------------------------------------------------------------------------------
REM Test 1

IF NOT EXIST test1 mkdir test1

@echo Test1: Same initial condition
@echo x = %x%
@echo y = %y%
@echo z = %z%


lorenzAttractor --euler -s %Step% -t %MaxTime% -x %x% -y %y% -z %z% > test1/euler.dat
lorenzAttractor --heun  -s %Step% -t %MaxTime% -x %x% -y %y% -z %z% > test1/heun.dat
lorenzAttractor --rk    -s %Step% -t %MaxTime% -x %x% -y %y% -z %z% > test1/rk.dat

REM ---------------------------------------------------------------------------------------------
REM Test 2

IF NOT EXIST test2 mkdir test2
set xa=%x%
set ya=%y%
set za=%z%
set xb=%x%%EPS%
set yb=%y%
set zb=%z%

@echo Test2: Same Methods, epsilon-diff x initial condition
@echo x1 = %xa%
@echo y1 = %ya%
@echo z1 = %za%

@echo x2 = %xb%
@echo y2 = %yb%
@echo z2 = %zb%


lorenzAttractor --euler -s %Step% -t %MaxTime% -x %xa% -y %ya% -z %za% > test2/euler_a.dat
lorenzAttractor --euler -s %Step% -t %MaxTime% -x %xb% -y %yb% -z %zb% > test2/euler_b.dat
lorenzAttractor --heun  -s %Step% -t %MaxTime% -x %xa% -y %ya% -z %za% > test2/heun_a.dat
lorenzAttractor --heun  -s %Step% -t %MaxTime% -x %xb% -y %yb% -z %zb% > test2/heun_b.dat
lorenzAttractor --rk    -s %Step% -t %MaxTime% -x %xa% -y %ya% -z %za% > test2/rk_a.dat
lorenzAttractor --rk    -s %Step% -t %MaxTime% -x %xb% -y %yb% -z %zb% > test2/rk_b.dat

REM ---------------------------------------------------------------------------------------------
REM Test 3

IF NOT EXIST test3 mkdir test3
set xa=%x%
set ya=%y%
set za=%z%
set xb=%x%
set yb=%y%%EPS%
set zb=%z%

@echo Test3: Same Methods, epsilon-diff y initial condition
@echo x1 = %xa%
@echo y1 = %ya%
@echo z1 = %za%

@echo x2 = %xb%
@echo y2 = %yb%
@echo z2 = %zb%


lorenzAttractor --euler -s %Step% -t %MaxTime% -x %xa% -y %ya% -z %za% > test3/euler_a.dat
lorenzAttractor --euler -s %Step% -t %MaxTime% -x %xb% -y %yb% -z %zb% > test3/euler_b.dat
lorenzAttractor --heun  -s %Step% -t %MaxTime% -x %xa% -y %ya% -z %za% > test3/heun_a.dat
lorenzAttractor --heun  -s %Step% -t %MaxTime% -x %xb% -y %yb% -z %zb% > test3/heun_b.dat
lorenzAttractor --rk    -s %Step% -t %MaxTime% -x %xa% -y %ya% -z %za% > test3/rk_a.dat
lorenzAttractor --rk    -s %Step% -t %MaxTime% -x %xb% -y %yb% -z %zb% > test3/rk_b.dat

REM ---------------------------------------------------------------------------------------------
REM Test 4

IF NOT EXIST test4 mkdir test4
set xa=%x%
set ya=%y%
set za=%z%
set xb=%x%
set yb=%y%
set zb=%z%%EPS%

@echo Test4: Same Methods, epsilon-diff z initial condition
@echo x1 = %xa%
@echo y1 = %ya%
@echo z1 = %za%

@echo x2 = %xb%
@echo y2 = %yb%
@echo z2 = %zb%


lorenzAttractor --euler -s %Step% -t %MaxTime% -x %xa% -y %ya% -z %za% > test4/euler_a.dat
lorenzAttractor --euler -s %Step% -t %MaxTime% -x %xb% -y %yb% -z %zb% > test4/euler_b.dat
lorenzAttractor --heun  -s %Step% -t %MaxTime% -x %xa% -y %ya% -z %za% > test4/heun_a.dat
lorenzAttractor --heun  -s %Step% -t %MaxTime% -x %xb% -y %yb% -z %zb% > test4/heun_b.dat
lorenzAttractor --rk    -s %Step% -t %MaxTime% -x %xa% -y %ya% -z %za% > test4/rk_a.dat
lorenzAttractor --rk    -s %Step% -t %MaxTime% -x %xb% -y %yb% -z %zb% > test4/rk_b.dat
